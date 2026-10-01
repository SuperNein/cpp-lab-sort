#include <cstddef>
#include <iostream>

namespace array {

int* array_create(std::size_t size) {
    if (size == 0) {
        return nullptr;
    }

    return new int[size]{};
}

void array_delete(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

int* array_resize(int* arr, std::size_t size, std::size_t new_size) {
    if (new_size == 0) {
        array_delete(arr);
        return nullptr;
    }

    int* data = new int[new_size]{};

    std::size_t to_copy = (size < new_size) ? size : new_size;

    for (std::size_t i = 0; i < to_copy; ++i) {
        data[i] = arr[i];
    }

    array_delete(arr);

    return data;
}

int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value) {
    if (pos > size) {
        pos = size;
    }

    int* data = new int[size + 1]{};
    
    for (std::size_t i = 0; i < pos; ++i) {
        data[i] = arr[i];
    }

    data[pos] = value;

    for (std::size_t i = pos; i < size; ++i) {
        data[i + 1] = arr[i];
    }

    delete[] arr;
    ++size;
    
    return data;
}

int* array_remove(int* arr, std::size_t& size, std::size_t pos) {
    if (size == 0 || pos >= size) {
        return arr;
    }

    if (size == 1) {
        delete[] arr;
        size = 0;
        return nullptr;
    }

    int* data = new int[size - 1]{};

    for (std::size_t i = 0; i < pos; ++i) {
        data[i] = arr[i];
    }

    for (std::size_t i = pos + 1; i < size; ++i) {
        data[i - 1] = arr[i];
    }

    delete[] arr;
    --size;

    return data;
}

void array_print(const int* arr, std::size_t size) {
    std::cout << "[";

    if (arr != nullptr) {
        for (std::size_t i = 0; i < size; ++i) {
            std::cout << arr[i];

            if (i + 1 < size) {
                std::cout << ", ";
            }
        }
    }

    std::cout << "]" << std::endl;
}

int* array_merge(
    const int* a, std::size_t na, 
    const int* b, std::size_t nb, 
    std::size_t& out_size
) {
    out_size = na + nb;
    if (out_size == 0) {
        return nullptr;
    }

    int* arr = new int[out_size]{};

    std::size_t ia = 0;
    std::size_t ib = 0;
    std::size_t k = 0;

    while (ia < na && ib < nb) {
        if (a[ia] <= b[ib]) {
            arr[k++] = a[ia++];
        } else {
            arr[k++] = b[ib++];
        }
    }

    while (ia < na) {
        arr[k++] = a[ia++];
    }

    while (ib < nb) {
        arr[k++] = b[ib++];
    }

    return arr;
}

} // namespace array
