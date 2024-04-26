#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <filesystem>

using namespace std;

// namespace fs = filesystem;

class Student
{
private:
    string name;
    string id;
    double gpa;

public:
    Student() : name(""), id(""), gpa(0.0) {}
    Student(string id, string name, double gpa)
    {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
    }
    bool operator<(const Student &second) const
    {
        return name < second.name;
    }
    bool operator<=(const Student &second) const
    {
        return name <= second.name;
    }
    bool operator>(const Student &second) const
    {
        return name > second.name;
    }
    //    For cout
    friend ostream &operator<<(ostream &out, const Student &s)
    {
        out << s.name << " " << s.id << " " << s.gpa;
        return out;
    }

    const string &getName() const
    {
        return name;
    }

    void setName(const string &name)
    {
        this->name = name;
    }

    const string &getId() const
    {
        return id;
    }

    void setId(const string &id)
    {
        this->id = id;
    }

    double getGpa() const
    {
        return gpa;
    }

    void setGpa(double gpa)
    {
        this->gpa = gpa;
    }
};

template <typename T>
void printArray(T arr[])
{
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void BubbleSort(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

template <typename T>
void BubbleSortByGPA(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j].getGpa() > arr[j + 1].getGpa())
                swap(arr[j], arr[j + 1]);
        }
    }
}

template <typename T>
void InsertionSort(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j >= 0 && arr[j] > arr[j + 1]; j--)
            swap(arr[j], arr[j + 1]);
    }
}

template <typename T>
void InsertionSortByGPA(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j >= 0 && arr[j].getGpa() > arr[j + 1].getGpa(); j--)
            swap(arr[j], arr[j + 1]);
    }
}

template <typename T>
void SelectionSort(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(arr[minIndex], arr[i]);
    }
}

template <typename T>
void SelectionSortByGPA(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].getGpa() < arr[minIndex].getGpa())
                minIndex = j;
        }
        if (minIndex != i)
            swap(arr[minIndex], arr[i]);
    }
}

template <typename T>
void shellSort(T *arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <typename T>
void shellSortByGPA(T *arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].getGpa() > temp.getGpa(); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


template <typename T>
void Merge(T array[], int const left, int const mid,
           int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new T[subArrayOne],
            *rightArray = new T[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
template <typename T>
void MergeSort(T array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}


//By GPA
template <typename T>
void MergeByGPA(T array[], int const left, int const mid,
           int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new T[subArrayOne],
            *rightArray = new T[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne].getGpa()
            <= rightArray[indexOfSubArrayTwo].getGpa()) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
template <typename T>
void MergeSortByGPA(T array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    MergeSortByGPA(array, begin, mid);
    MergeSortByGPA(array, mid + 1, end);
    MergeByGPA(array, begin, mid, end);
}

template <typename T>
void QuickSort(T *arr, int size)
{

}

template <typename T>
void QuickSortByGPA(T *arr, int size)
{

}

int main()
{
//     fs::path currentPath = fs::current_path();

    // string FilePath;

    // cin>> FilePath;
    ifstream inputFile;
    ofstream sortByName;
    ofstream sortByGPA;

    try
    {
//        Note:- Absolute paths
        inputFile.open(R"(E:\Amr\EDUCATION\FCAI\Second-Year\Second-semester\DataStructures\Assignments\Assignment-1\students.txt)");
        sortByName.open(R"(E:\Amr\EDUCATION\FCAI\Second-Year\Second-semester\DataStructures\Assignments\Assignment-1\sortByName.txt)");
        sortByGPA.open(R"(E:\Amr\EDUCATION\FCAI\Second-Year\Second-semester\DataStructures\Assignments\Assignment-1\sortByGPA.txt)");
    }
    catch (exception &e)
    {
        cout << "Error opening file " << e.what();
        exit(1);
    }

    int StudentsNumber;
    inputFile >> StudentsNumber;
    inputFile.ignore();

    //    For testing
    //    cout << StudentsNumber << endl;

    Student arr[StudentsNumber];
    for (int i = 0; i < StudentsNumber; ++i)
    {
        string name;
        inputFile >> name;
        arr[i].setName(name);
        string id;
        inputFile >> id;
        arr[i].setId(id);
        double gpa;
        inputFile >> gpa;
        arr[i].setGpa(gpa);
    }
    //    Start dummy scope
    {
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        BubbleSort(arr, StudentsNumber);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByName << "Algorithm: Bubble Sort" << endl;
        sortByName << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;

        for (int i = 0; i < StudentsNumber; ++i)
        {
            sortByName << arr[i] << endl;
        }
        sortByName << endl;
    }

    //    Start dummy scope
    {
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        BubbleSortByGPA(arr, StudentsNumber);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByGPA << "Algorithm: Bubble Sort" << endl;
        sortByGPA << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;

        for (int i = 0; i < StudentsNumber; ++i)
        {
            sortByGPA << arr[i] << endl;
        }
        sortByGPA << endl;
    }

    //    Start dummy scope
    {
        //    InsertionSort
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        InsertionSort(arr, StudentsNumber);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByName << "Algorithm: Insertion Sort" << endl;
        sortByName << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;
    }
    for (int i = 0; i < StudentsNumber; ++i)
    {
        sortByName << arr[i] << endl;
    }
    sortByName << endl;

    //    Start dummy scope
    {
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        InsertionSortByGPA(arr, StudentsNumber);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByGPA << "Algorithm: Insertion Sort" << endl;
        sortByGPA << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;
    }

    for (int i = 0; i < StudentsNumber; ++i)
    {
        sortByGPA << arr[i] << endl;
    }
    sortByGPA << endl;

    //    Start dummy scope

    {
        //    SelectionSort
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        SelectionSort(arr, StudentsNumber);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByName << "Algorithm: Selection Sort" << endl;
        sortByName << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;
    }

    for (int i = 0; i < StudentsNumber; ++i)
    {
        sortByName << arr[i] << endl;
    }
    sortByName << endl;

    //    Start dummy scope
    {
        //    SelectionSort
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        SelectionSortByGPA(arr, StudentsNumber);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByGPA << "Algorithm: Selection Sort" << endl;
        sortByGPA << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;
    }

    for (int i = 0; i < StudentsNumber; ++i)
    {
        sortByGPA << arr[i] << endl;
    }
    sortByGPA << endl;

    //    Start dummy scope
    {
        //    shellSort
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        shellSort(arr, StudentsNumber);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByName << "Algorithm: Shell Sort" << endl;
        sortByName << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;
    }

    for (int i = 0; i < StudentsNumber; ++i)
    {
        sortByName << arr[i] << endl;
    }
    sortByName << endl;
    //    Start dummy scope
    {
        //    shellSort
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        shellSortByGPA(arr, StudentsNumber);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByGPA << "Algorithm: Shell Sort" << endl;
        sortByGPA << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;
    }

    for (int i = 0; i < StudentsNumber; ++i)
    {
        sortByGPA << arr[i] << endl;
    }
    sortByGPA << endl;
    //    Start dummy scope
    {
        //    Merge sort
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        MergeSort(arr,0 , StudentsNumber-1);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByName << "Algorithm: Merge Sort" << endl;
        sortByName << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;
    }

    for (int i = 0; i < StudentsNumber; ++i)
    {
        sortByName << arr[i] << endl;
    }
    sortByName << endl;

    //    Start dummy scope
    {
        //    Merge sort
        // Start the clock
        auto start = std::chrono::high_resolution_clock::now();
        MergeSortByGPA(arr,0 , StudentsNumber-1);
        // Stop the clock
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        chrono::duration<double> duration = end - start;
        sortByGPA << "Algorithm: Merge Sort" << endl;
        sortByGPA << "Running Time: " << duration.count() * 1000 << " milliseconds" << endl;
    }

    for (int i = 0; i < StudentsNumber; ++i)
    {
        sortByGPA << arr[i] << endl;
    }
    sortByGPA << endl;



    inputFile.close();
    sortByName.close();
    sortByGPA.close();
    return 0;
}
