#include <cstddef>
#include <iostream>
#include <limits>

#include "array_ops.h"

void print_menu() {
    std::cout 
        << "\n======================\n"
        << "||   Dynamic Array  ||\n"
        << "======================\n"
        << " [1] Create array\n"  
        << " [2] Print\n"
        << " [3] Insert\n"
        << " [4] Remove\n"
        << " [5] Resize\n"
        << " [6] Save\n"
        << " [7] Merge\n"
        << " [0] Exit\n"
        << "----------------------\n";
}

int read_int(const char* prompt) {
    int value;

    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "ERROR\n";
    }
}

int main() {
    int* arr = nullptr;
    int* saved_arr = nullptr;

    std::size_t size = 0, saved_size = 0;
    
    bool running = true;

    print_menu();

    while (running) {
        int command = read_int("\n>> Enter command: ");

        switch (command) {
            case 1: {
                int new_size = read_int("Enter array size: ");

                if (new_size >= 0) {
                    array_delete(arr);

                    size = static_cast<std::size_t>(new_size);
                    arr = array_create(size);
                    
                    std::cout << "Array created\n";
                } else {
                    std::cout << "Wrong size\n";
                }
                break;
            }
            case 2: {
                array_print(arr, size);
                break;
            }
            case 3: {
                int value = read_int("Enter value: ");
                int pos = read_int("Enter value position: ");

                if (pos >= 0) {
                    arr = array_insert(arr, size, static_cast<std::size_t>(pos), value);
                    std::cout << "Value inserted\n";
                } else {
                    std::cout << "Wrong position\n";
                }
                break;
            }
            case 4: {
                int pos = read_int("Enter removing position: ");

                if (pos >= 0) {
                    arr = array_remove(arr, size, static_cast<std::size_t>(pos));
                    std::cout << "Value removed\n";
                } else {
                    std::cout << "Wrong position\n";
                }
                break;
            }
            case 5: {
                int new_size = read_int("Enter new size: ");

                if (new_size >= 0) {
                    arr = array_resize(arr, size, static_cast<std::size_t>(new_size));
                    std::cout << "Array resized\n";
                } else {
                    std::cout << "Wrong new size\n";
                }
                break;
            }
            case 6: {
                array_delete(saved_arr);

                saved_arr = arr;
                saved_size = size;

                arr = nullptr;
                size = 0;

                std::cout << "Array saved. Current array is now empty.\n";
                break;
            }
            case 7: {
                std::size_t new_size{};

                arr = array_merge(
                    arr, size,
                    saved_arr, saved_size,
                    new_size
                );
                size = new_size;

                array_delete(saved_arr);
                saved_size = 0;

                std::cout << "Arrays merged\n";
                break;
            }
            case 0: {
                running = false;
                std::cout << "Exited\n";
                break;
            }
            default: {
                std::cout << "Unknown command\n";
                break;
            }
        }
    }

    array_delete(arr);
    array_delete(saved_arr);

    return 0;
}
