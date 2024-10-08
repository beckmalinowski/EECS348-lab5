#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    /* takes in a temperature in celsius and converts it to fahrenheit */
    return ((9.0 / 5.0) * celsius) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    /* takes in a temperature in fahrenheit and converts it to celsius */
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

float celsius_to_kelvin(float celsius) {
    /* takes in a temperature in celsius and converts it to kelvin */
    float kelvin = celsius + 273.15;
    if (kelvin < 0) {
        kelvin = 0;
    }
    return kelvin;
}

float kelvin_to_celsius(float kelvin) {
    /* takes in a temperature in kelvin and converts it to celsius */
    return kelvin - 273.15;
}

void categorize_temperature(float celsius) {
    /*
     * takes in the temperature (in celsius) and prints out an assessment of the
     * temperature (ex. Freezing) and a weather advisory to go with it. Void.
     */ 
    printf("Temperature category: ");
    if (celsius < 0.0) {
        printf("Freezing\n");
        printf("Weather advisory: Be careful for ice..\n");
    } else if (celsius <= 10.0) {
        printf("Cold\n");
        printf("Weather advisory: Put on some layers.\n");
    } else if (celsius <= 25.0) {
        printf("Comfortable\n");
        printf("Weather advisory: You should be okay.\n");
    } else if (celsius <= 35.0) {
        printf("Hot\n"); 
        printf("Weather advisory: Wear a T-shirt and shorts.\n");
    } else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}

float scale_to_target(float temperature, int scale, int target) {
    /* takes the three user-inputted variables and runs the conversion logic. */
    float converted;
    switch (scale) {
        case 1:
            switch (target) {
                case 1:
                    return temperature;
                case 2:
                     return celsius_to_fahrenheit(temperature);
                case 3:
                     return celsius_to_kelvin(temperature);
            }
        case 2:
            switch (target) {
                case 1:
                    return fahrenheit_to_celsius(temperature);
                case 2:
                    return temperature;
                case 3:
                    converted = fahrenheit_to_celsius(temperature);
                    return celsius_to_kelvin(converted);
            }
        case 3:
            switch (target) {
                case 1:
                    return kelvin_to_celsius(temperature);
                case 2:
                    converted = kelvin_to_celsius(temperature);
                    return celsius_to_fahrenheit(converted);
                case 3:
                    return temperature;
            }
    }
}

int main() {
    float temperature;
    int scale, target;

    // user input
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    while (1) { // loops until valid input
        while (1) { // loops until valid input
            printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            scanf("%d", &scale);
            if ((scale <= 3) && (scale > 0)) { // scale is between 1-3 (inclusive)
                break;
            }
            printf("Please enter an option 1, 2, or 3!\n");
        }
        while (1) { // loops until valid input
            printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            scanf("%d", &target);
            if ((target <= 3) && (target > 0)) { // scale is between 1-3 (inclusive)
                break;
            }
            printf("Please enter an option 1, 2, or 3!\n");
        }
        if (scale != target) { // if scale and target are equal, (ex. C -> C) asks again
            break;
        }
        printf("Please choose two unique options for scale and target!\n");
    }

    float converted_temperature = scale_to_target(temperature, scale, target);
    // celsius_temperature is used for categorize_temperature()
    float celsius_temperature = scale_to_target(temperature, scale, 1);

    printf("Converted temperature: %f\n", converted_temperature);
    categorize_temperature(celsius_temperature);
    return 0;
}
