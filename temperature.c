#include <stdio.h>
#include <stdbool.h>

// conversion functions
float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius)
{
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin)
{
    return kelvin - 273.15;
}

float fahrenheit_to_jelvin(float fahrenheit)
{
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin)
{
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// temperature categorization
void categorize_temperature(float celsius)
{
    printf("Temperature Category: ");

    if (celsius < 0)
    {
        printf("Freezing\n");
        printf("Advisory: Wear heavy winter clothing\n");
    }
    else if (celsius < 10)
    {
        printf("Cold\n");
        printf("Advisory: Wear a jacket and warm clothing\n");
    }
    else if (celsius < 25)
    {
        printf("Comfortable\n");
        printf("Advisory: Enjoy the pleasant weather\n");
    }
    else if (celsius < 35)
    {
        printf("Hot\n");
        printf("Advisory: Stay hydrated and avoid direct sunlight\n");
    }
    else
    {
        printf("Extreme Heat\n");
        printf("AdvisoryL Stay indoors");
    }
}

int main()
{
    float temp;
    int input_scale, target_scale;
    bool valid_input = false;

    printf("Temperature Conversion Utility\n");
    printf("-----------------------------\n");

    // input validation loop
    while (!valid_input)
    {
        printf("\nEnter temperature value: ");
        if (scanf("%f", &temp) != 1)
        {
            printf("Invalid temperature value. Please enter a number\n");
            while (getchar() != '\n')
                ; // clear input buffer
            continue;
        }

        printf("\nSelect input scale:\n");
        printf("1. Fahrenheit\n");
        printf("2. Celsius\n");
        printf("3. Kelvin\n");
        printf("Choice: ");
        scanf("%d", &input_scale);

        if (input_scale < 1 || input_scale > 3)
        {
            printf("Invalid scale selection. Please shoose 1-3\n");
            continue;
        }

        // validate temperature based on scale
        if (input_scale == 3 && temp < 0)
        {
            printf("Invalid temperature: Kelvin cannot be negative\n");
            continue;
        }

        printf("\nSelect target scale:\n");
        printf("1. Fahrenheit\n");
        printf("2. Celsius\n");
        printf("3. Kelvin\n");
        printf("Choice: ");
        scanf("%d", &target_scale);

        if (target_scale < 1 || target_scale > 3)
        {
            printf("Invalid scale selection. Please choose 1-3\n");
            continue;
        }

        if (input_scale == target_scale)
        {
            printf("Input and target scales are the same. No conversion needed\n");
            continue;
        }

        valid_input = true;
    }

    // convert to celsius first
    float celsius;
    switch (input_scale)
    {
    case 1: // Fahrenheit
        celsius = fahrenheit_to_celsius(temp);
        break;
    case 2: // Celsius
        celsius = temp;
        break;
    case 3: // Kelvin
        celsius = kelvin_to_celsius(temp);
        break;
    }

    // convert to target scale
    float converted_temp;
    char *scale_name;
    switch (target_scale)
    {
    case 1: // fahrenheit
        converted_temp = celsius_to_fahrenheit(celsius);
        scale_name = "Fahrenheit";
        break;
    case 2: // Celsius
        converted_temp = celsius;
        scale_name = "Celsius";
        break;
    case 3: // Kelvin
        converted_temp = celsius_to_kelvin(celsius);
        scale_name = "Kelvin";
        break;
    }

    // display results
    printf("\nConversion results:\n");
    printf("-----------------\n");
    printf("Converted Temperature: %.2f %s\n", converted_temp, scale_name);

    // categorize based on celsius
    categorize_temperature(celsius);

    return 0;
}