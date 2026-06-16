#include "Definition.h"
#include <stdint.h>

RCC_Type* RCC_addr = (RCC_Type*)0x40023800;
GPIO_Type* GPIOA = (GPIO_Type*)0x40020000;
GPIO_Type* GPIOB = (GPIO_Type*)0x40020400;
GPIO_Type* GPIOC = (GPIO_Type*)0x40020800;
GPIO_Type* GPIOD = (GPIO_Type*)0x40020C00;
USART_Type* USART1 = (USART_Type*)0x40011000;
USART_Type* USART6 = (USART_Type*)0x40011400;

// Функция отправки символа через USART1
void uart1_send_char(int c)
{ 
    while(!USART1->x_SR.TXE);  // Ожидание готовности передатчика
    USART1->x_DR.DR = c;       // Отправка символа
    while(!USART1->x_SR.TC);   // Ожидание завершения передачи
}

// Функция приема символа через USART1
uint8_t uart1_receive_char(void)
{
    while(!USART1->x_SR.RXNE); // Ожидание приема данных
    return USART1->x_DR.DR;
}

uint16_t calculate_crc_modbus(const uint8_t *data, uint16_t length)
{
    uint16_t crc = 0xFFFF;
    uint8_t i;
    
    while(length--) {
        crc ^= *data++;
        
        for(i = 0; i < 8; i++) {
            if(crc & 0x0001) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

// Функция отправки Modbus команды записи регистра (функция 06)
void send_modbus_write_register(uint8_t address, uint16_t register_addr, uint16_t value)
{
    uint8_t message[8];
    uint16_t crc;
    
    // Формируем сообщение для функции 06
    message[0] = address;
    message[1] = 0x06;  // Функция записи регистра
    message[2] = (register_addr >> 8) & 0xFF;  // Старший байт адреса
    message[3] = register_addr & 0xFF;         // Младший байт адреса
    message[4] = (value >> 8) & 0xFF;          // Старший байт значения
    message[5] = value & 0xFF;                 // Младший байт значения
    
    // Рассчитываем CRC
    crc = calculate_crc_modbus(message, 6);
    
    // Добавляем CRC (младший байт первый)
    message[6] = crc & 0xFF;
    message[7] = (crc >> 8) & 0xFF;
    
    // Переключаемся в режим передачи
    GPIOB->x_ODR.ODR4 = 1;
    
    // Отправляем все 8 байт
    for(int i = 0; i < 8; i++) {
        uart1_send_char(message[i]);
    }
    
    // Ждем завершения передачи
    while(!USART1->x_SR.TC);
    
    // Возвращаемся в режим приема
    GPIOB->x_ODR.ODR4 = 0;
}

// Функция отправки Modbus команды чтения регистров (функция 03)
void send_modbus_read_registers(uint8_t address, uint16_t start_addr, uint16_t count)
{
    uint8_t message[8];
    uint16_t crc;
    
    // Формируем сообщение для функции 03
    message[0] = address;
    message[1] = 0x03;  // Функция чтения регистров
    message[2] = (start_addr >> 8) & 0xFF;  // Старший байт адреса
    message[3] = start_addr & 0xFF;         // Младший байт адреса
    message[4] = (count >> 8) & 0xFF;       // Старший байт количества
    message[5] = count & 0xFF;              // Младший байт количества
    
    // Рассчитываем CRC
    crc = calculate_crc_modbus(message, 6);
    
    // Добавляем CRC (младший байт первый)
    message[6] = crc & 0xFF;
    message[7] = (crc >> 8) & 0xFF;
    
     for(volatile int k = 0; k < 100; ++k);
    // Переключаемся в режим передачи
    GPIOB->x_ODR.ODR4 = 1;
    
    // Отправляем все 8 байт
    for(int i = 0; i < 8; i++) {
        uart1_send_char(message[i]);
    }
    
    // Ждем завершения передачи
    while(!USART1->x_SR.TC);
    
     for(volatile int k = 0; k < 100; ++k);
    // Возвращаемся в режим приема
    GPIOB->x_ODR.ODR4 = 0;
}

// Функция приема ответа Modbus
uint8_t receive_modbus_response(uint8_t *buffer, uint16_t max_length)
{
    uint16_t timeout = 1000000;
    uint8_t index = 0;
    
    // Ожидаем начало ответа
    while(timeout-- && index < max_length) {
        if(USART1->x_SR.RXNE) {
            buffer[index++] = uart1_receive_char();
            timeout = 100000; // Сброс таймаута при получении байта
        }
    }
    
    return index; // Возвращаем количество принятых байт
}

void SystemInit(void)
{
    // Включение HSE и ожидание готовности
    RCC_addr->CR.HSE_ON = 0x1;
    while(!RCC_addr->CR.HSE_RDY);
    
    for(volatile int k = 0; k < 10000; ++k);

    // Настройка источника PLL
    RCC_addr->PLLCFGR.PLLSRC = 0x1; // HSE как источник PLL

    // Настройка PLL для 24 МГц: 8MHz /4 *72 /6 = 24MHz
    RCC_addr->PLLCFGR.PLLM = 0x4;  // Делитель 4
    RCC_addr->PLLCFGR.PLLN = 0x48; // Множитель 72  
    RCC_addr->PLLCFGR.PLLP = 0x2;  // Делитель 6

    // Сброс bypass режима
    RCC_addr->CR.HSE_BYP = 0x0;

    // Настройка делителей шин
    RCC_addr->CFGR.HPRE = 0x0;   // AHB без деления
    RCC_addr->CFGR.PPRE1 = 0x4;  // APB1 /2 > 12 МГц
    RCC_addr->CFGR.PPRE2 = 0x0;  // APB2 без деления > 24 МГц
    
    // Включение PLL и ожидание готовности
    RCC_addr->CR.PLL_ON = 0x1;
    while(!RCC_addr->CR.PLL_RDY);
    
    for(volatile int k = 0; k < 500000; ++k);

    // Переключение на PLL
    RCC_addr->CFGR.SW = 0x2;
    while(RCC_addr->CFGR.SWS != 0x2);
}

int main(void)
{
    SystemInit();

    // Включение тактирования
    RCC_addr->AHB1ENR.GPIO_DEN = 0x1;  // GPIOD
    RCC_addr->AHB1ENR.GPIO_AEN = 0x1;  // GPIOA
    RCC_addr->AHB1ENR.GPIO_BEN = 0x1;  // Включить GPIOB
    RCC_addr->AHB1ENR.GPIO_CEN = 0x1;  // GPIOC
    RCC_addr->APB2ENR.USART1 = 0x1;    // USART1 (APB2)
    RCC_addr->APB2ENR.USART6 = 0x1;    // USART6 (APB2)

    // Настройка светодиодов на GPIOD
    GPIOD->x_MODER.MODER12 = 0x1; // Output mode (зеленый - запись)
    GPIOD->x_MODER.MODER13 = 0x1; // Output mode (оранжевый - чтение)
    GPIOD->x_MODER.MODER14 = 0x1; // Output mode (красный - успех)
    GPIOD->x_OTYPER.OT12 = 0x0;   // Push-pull
    GPIOD->x_OTYPER.OT13 = 0x0;   // Push-pull
    GPIOD->x_OTYPER.OT14 = 0x0;   // Push-pull
    GPIOD->x_OSPEEDR.OSPEEDR12 = 0x2; // Medium speed
    GPIOD->x_OSPEEDR.OSPEEDR13 = 0x2; // Medium speed
    GPIOD->x_OSPEEDR.OSPEEDR14 = 0x2; // Medium speed

    // Настройка UART пинов для USART1 (PB6 - TX, PB7 - RX)
    GPIOB->x_MODER.MODER6 = 0x2;   // Alternate function
    GPIOB->x_MODER.MODER7 = 0x2;   // Alternate function
    GPIOB->x_AFRL.AFRL6 = 0x7;     // AF7 для USART1_TX
    GPIOB->x_AFRL.AFRL7 = 0x7;     // AF7 для USART1_RX
    GPIOB->x_OSPEEDR.OSPEEDR6 = 0x3; // High speed
    GPIOB->x_OSPEEDR.OSPEEDR7 = 0x3; // High speed
    GPIOB->x_PUPDR.PUPDR6 = 0x1;   // Pull-up
    GPIOB->x_PUPDR.PUPDR7 = 0x1;   // Pull-up
      
    // Настройка PB4 как output для управления RE/DE
    GPIOB->x_MODER.MODER4 = 0x1;    // Output mode
    GPIOB->x_OTYPER.OT4 = 0x0;      // Push-pull
    GPIOB->x_OSPEEDR.OSPEEDR4 = 0x2; // Medium speed
    GPIOB->x_PUPDR.PUPDR4 = 0x0;    // No pull-up/pull-down
    
    // По умолчанию в режиме приема
    GPIOB->x_ODR.ODR4 = 0;
    
    // Настройка USART1 для 9600 бод при 24 МГц с четностью Even (8E1)
    USART1->x_BRR.DIV_Mantissa = 0x9C;  // 156
    USART1->x_BRR.DIV_Fraction = 0x4;   // 4/16 = 0.25
    
    // Включение USART1 с настройками 8E1
    USART1->x_CR1.UE = 0;       // Отключить USART перед настройкой
    USART1->x_CR1.TE = 1;       // Включение передатчика
    USART1->x_CR1.RE = 1;       // Включение приемника
    USART1->x_CR1.M = 1;        // 8 бит данных
    USART1->x_CR1.PCE = 1;      // Включение контроля четности
    USART1->x_CR1.PS = 0;       // Четность Even (0=Even, 1=Odd)
    for(volatile int i = 0; i < 10000; i++);
    USART1->x_CR1.UE = 1;       // Включить USART1

    uint8_t response[32];
    uint8_t response_length;
    uint16_t read_value;
    
    // Основной цикл
    while(1)
    {
        // 1. Запись значения 2 в регистр 0x10
        GPIOD->x_ODR.ODR12 = 1; // Зеленый - запись активна
        send_modbus_write_register(0x01, 0x0010, 0x0002);
        GPIOD->x_ODR.ODR12 = 0; // Выключить зеленый
        
        for(volatile int k = 0; k < 100000; ++k); // Задержка
        
        // 2. Чтение значения из регистра 0x10
        GPIOD->x_ODR.ODR13 = 1; // Оранжевый - чтение активно
        send_modbus_read_registers(0x01, 0x0010, 0x0001);
        
        // Прием ответа
        response_length = receive_modbus_response(response, sizeof(response));
        GPIOD->x_ODR.ODR13 = 0; // Выключить оранжевый
        
        // 3. Проверка полученных данных
        if(response_length >= 7) {
            // Извлекаем значение из ответа (байты 3 и 4)
            read_value = (response[3] << 8) | response[4];
            
            // Если прочитанное значение равно 2 - зажигаем красный диод
            if(read_value == 0x0002) {
                GPIOD->x_ODR.ODR14 = 1; // Красный - успех
            } else {
                GPIOD->x_ODR.ODR14 = 0; // Выключить красный
            }
        } else {
            GPIOD->x_ODR.ODR14 = 0; // Выключить красный при ошибке
        }
        
        for(volatile int k = 0; k < 1000000; ++k); // Задержка перед следующей итерацией
    }
}