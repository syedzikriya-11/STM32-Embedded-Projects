int main(void)
{
    GPIO_INIT();

    int count = 0;

    // Initially both LEDs OFF
    GPIOB_ODR |= (1 << 13);
    GPIOB_ODR |= (1 << 14);

    while(1)
    {
        // Wait for button PRESS
        while (GPIOC_IDR & (1 << 8))
        {
        }

        // Wait for button RELEASE
        while (!(GPIOC_IDR & (1 << 8)))
        {
        }

        // One complete press + release
        count++;

        if (count % 2 == 1)
        {
            // 1st, 3rd, 5th... → RED ON
            GPIOB_ODR &= ~(1 << 13);
            GPIOB_ODR |=  (1 << 14);
        }
        else
        {
            // 2nd, 4th, 6th... → GREEN ON
            GPIOB_ODR |=  (1 << 13);
            GPIOB_ODR &= ~(1 << 14);
        }
    }
}