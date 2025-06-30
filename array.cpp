#include <iostream>
using namespace std;

class Array
{
private:
    int* arr;
    int length;
    int size;

public:
    Array(int arrsize)
    {
        length = 0;
        size = arrsize;
        arr = new int[size];
    }


    bool isempty()
    {
        return length == 0;
    }
    bool isfull()
    {
        return length == size;
    }

    int get_size()
    {
        return size;
    }

    int get_length()
    {
        return length;
    }

    void display()
    {
        if (isempty())
        {
            cout << "The Array Is Empty\n";
        }
        else
        {
            cout << "Array Contains:\n";
            for (int i = 0; i < length; i++)
            {
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
    }

    int count()
    {
        if (isempty())
        {
            cout << "The Array Is Empty\n";
            return 0;
        }
        else
        {
            return length;
        }
    }

    void fill()
    {
        int no_of_items;
        cout << "Enter how many items you want to fill: ";
        cin >> no_of_items;

        if (no_of_items <= size)
        {
            for (int i = 0; i < no_of_items; i++)
            {
                cout << "Enter the value of item " << i + 1 << ": ";
                cin >> arr[i];
                length++;
            }
        }
        else
        {
            cout << "Invalid input\n";
            cout << "Number of items cannot be larger than array size\n";
        }
    }


    void insert(int index, int value)
    {
        if (isfull())
        {
            cout << "The Array IS Full \n";
        }
        else if (index >= size)

        {
            cout << "Error\n Out OF Range\n";
        }

        else
        {
            for (int i = length; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = value;
            length++;
        }
    }

    void append(int value)
    {
        if (isfull())
        {
            cout << "Array Is Full\n";
        }
        else
        {
            arr[length] = value;
            length++;
        }
    }


    void search(int value)
    {
        if (isempty())
        {
            cout << "The Array Is Empty\n";
        }
        else
        {
            bool isFound = false;

            for (int i = 0; i < length; i++)
            {
                if (arr[i] == value)
                {
                    isFound = true;
                    break;
                }
            }


            if (isFound)
            {
                cout << value << " Is Found\n";
            }
            else
            {
                cout << value << " Is Not Found\n";
            }

        }
    }

    void delete_item(int index)
    {
        if (isempty())
        {
            cout << "The array is empty.\n";
        }
        else if (index < 0 || index >= length)
        {
            cout << "Out of range.\n";
        }
        else
        {
            for (int i = index; i < length - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }

    void enlarge(int new_size)
    {
        if (new_size <= size)
        {
            cout << "New size must be larger \n";
        }
        else

        {
            size = new_size;
            int* temp = arr;
            arr = new int[size];
            for (int i = 0; i < length; i++)
            {
                arr[i] = temp[i];

            }
            delete[]temp;
        }

    }

    void merge(Array two)
    {
        int newsize = size + two.size;
        enlarge(newsize);
        for (int i = 0; i < two.length; i++)
        {
            arr[i + length] = two.arr[i];

        }
        length += two.length;

    }


    ~Array()
    {
        delete[]arr;
    }
};

int main()
{
    int size;
    cout << "Enter initial size of the array: ";
    cin >> size;

    Array arr(size);  // Create an array object

    int choice;
    do
    {
        cout << "\n================== MENU ==================\n";
        cout << "1. Fill the Array\n";
        cout << "2. Display the Array\n";
        cout << "3. Insert Element\n";
        cout << "4. Append Element\n";
        cout << "5. Delete Element\n";
        cout << "6. Search for Element\n";
        cout << "7. Enlarge the Array\n";
        cout << "8. Merge with Another Array\n";
        cout << "9. Get Length\n";
        cout << "10. Get Size\n";
        cout << "0. Exit\n";
        cout << "==========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            arr.fill();
            break;

        case 2:
            arr.display();
            break;

        case 3:
        {
            int index, value;
            cout << "Enter index to insert at: ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> value;
            arr.insert(index, value);
            break;
        }

        case 4:
        {
            int value;
            cout << "Enter value to append: ";
            cin >> value;
            arr.append(value);
            break;
        }

        case 5:
        {
            int index;
            cout << "Enter index of element to delete: ";
            cin >> index;
            arr.delete_item(index);
            break;
        }

        case 6:
        {
            int value;
            cout << "Enter value to search for: ";
            cin >> value;
            arr.search(value);
            break;
        }

        case 7:
        {
            int new_size;
            cout << "Enter new size: ";
            cin >> new_size;
            arr.enlarge(new_size);
            break;
        }

        case 8:
        {
            int new_arr_size;
            cout << "Enter size of new array to merge: ";
            cin >> new_arr_size;
            Array another(new_arr_size);
            another.fill();
            arr.merge(another);
            break;
        }

        case 9:
            cout << "Current length: " << arr.get_length() << endl;
            break;

        case 10:
            cout << "Current size (capacity): " << arr.get_size() << endl;
            break;

        case 0:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

