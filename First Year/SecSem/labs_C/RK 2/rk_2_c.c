// Вариант 1.
/*1. Информация об автомобилях, включающая название автомобиля, цену и пробег,
 * записывается в текстовый файл.
 * Длина строковых данных не превышает 50 символов.
 * Найти самый дорогой автомобиль и автомобиль с максимальным пробегом. Полученный результат вывести на экран.
*/

//TAREk CHAWICH IU7-21B

#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_CAR_NAME_LENGTH 50

typedef struct {
    char name[MAX_CAR_NAME_LENGTH];
    double price;
    double mileage;
} Car;
// Функция поиска самого дорогого автомобиля из множества автомобилей
Car findMostExpensiveCar(Car cars[], int numCars) {
    Car mostExpensiveCar = cars[0];
    for (int i = 1; i < numCars; i++) {
        if (cars[i].price > mostExpensiveCar.price) {
            mostExpensiveCar = cars[i];
        }
    }
    return mostExpensiveCar;
}
// Функция поиска автомобиля с максимальным пробегом в массиве автомобилей
Car findCarWithMaxMileage(Car cars[], int numCars) {
    Car maxMileageCar = cars[0];
    for (int i = 1; i < numCars; i++) {
        if (cars[i].mileage > maxMileageCar.mileage) {
            maxMileageCar = cars[i];
        }
    }
    return maxMileageCar;
}

int main() {
    FILE *file;
    char filename[MAX_FILENAME_LENGTH];
    int numCars;
// Getting the file name to open.
    printf("Enter the filename: ");
    if (scanf("%s", filename) != 1) {
        printf("Error: Failed to read the filename.\n");
        // Additional error handling or program termination can be added here
    }

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1; // File error
    }

// Checking if the file is empty.
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize == 0) {
        printf("Error: The file is empty.\n");
        fclose(file);
        return 1; // Empty file error
    }
    rewind(file);
// Getting the numbers of cars.
    printf("Enter the number of cars: ");
    scanf("%d", &numCars);

    Car cars[numCars];


    // Read car information from the file
    for (int i = 0; i < numCars; i++) {
        fscanf(file, "%s %lf %lf", cars[i].name, &cars[i].price, &cars[i].mileage);
    }

    fclose(file);

    // Find the most expensive car
    Car mostExpensiveCar = findMostExpensiveCar(cars, numCars);

    // Find the car with the maximum mileage
    Car maxMileageCar = findCarWithMaxMileage(cars, numCars);

    // Display the results
    printf("Most expensive car: %s\n", mostExpensiveCar.name);
    printf("Car with maximum mileage: %s\n", maxMileageCar.name);

    return 0;
}
