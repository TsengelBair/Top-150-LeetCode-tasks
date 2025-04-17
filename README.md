## LeetCode 150 top tasks

### 88. Merge Sorted Array

Даны два целочисленных массива, nums1 и nums2 отсортированные в порядке возрастания и также даны два числа, число m для первого массива, отображающее количество нулей, равных количеству чисел в nums2 (это число n)

Нули в первом массиве необходимы для того, чтобы вместо них расположить в первом массиве элементы из второго массива, но так чтобы итоговый мутированный массив nums1 остался отсортированным

Пример
```c++
nums1 = {1, 2, 3, 0, 0, 0}, m = 3
nums2 = {2, 5, 6}, n = 3

merge(nums1, m, nums2, n)
nums1 = {1, 2, 2, 3, 5, 6}
```

[Подробное описание](https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150)

Основная идея это итерация с конца массива, необходимо сравнить последний (ненулевой) элемент из первого массива с последним элементом из второго массива и в случае если первый элемент меньше либо равен, записать на место последнего нуля в nums1 последний элемент из nums2 (т.к. он будет максимальным), сдвинуть указатель m для того чтобы сравнивать следующий элемент из nums1 и указатель indexToWrite

К примеру 
```c++
nums1 = {1, 2, 3, 0, 0, 0}, m = 3
nums2 = {2, 5, 6}, n = 3

int indexToWrite = nums1.size() - 1; /// последний элемент nums1 равный нулю

if (nums1[m - 1] <= nums2[n - 1] ) {
    nums1[indexToWrite] = nums2[n - 1];
    --m;
    --indexToWrite;
}
```

Но что делать в случае, когда элемент из первого массива оказался больше?

Разберем более простой пример

```c++
nums1 = {9, 0}, m = 1
nums2 = {6}, n = 1
```

В таком случае необходимо вместо текущего элемента [indexToWrite] записать nums1[m - 1], то есть получится 
```c++
nums1 = {9, 9}
```

И уже в следующем цикле до тех пор пока указатель n > 0 записывать в nums1[indexToWrite] элемент nums2[n - 1]

В данном примере когда nums1 = {9, 9} указатель n равен 1 и цикл 
```c++
while (n > 0) {
    nums1[indexToWrite] = nums2[n - 1];
    --n;
    --indexToWrite;
}
```

Сделает массив nums1
```c++
nums1 = {6, 9}
```

#### Solution
```c++
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int indexToWrite = nums1.size() - 1;

    /// до тех пор пока есть что сравнивать
    while (n > 0 && m > 0) {
        if (nums1[m - 1] <= nums2[n - 1]) {
            nums1[indexToWrite] = nums2[n - 1];
            --n;
        }
        else {
            nums1[indexToWrite] = nums1[m - 1];
            --m;
        }

        --indexToWrite;
    }

    while (n > 0) {
        nums1[indexToWrite] = nums2[n - 1];
        --n;
        --indexToWrite;
    }
}
```

### 27. Remove Element

Дан целочисленный массив nums и число val, необходимо убрать все вхождения val in place и вернуть количество оставшихся элементов.

In place - означает, что метод должен работать напрямую с переданной по ссылке структурой без создания вспомогательных структур и аллокаций доп памяти.

Пример
```c++
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]

Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

[Подробное описание](https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150)

Для решения используем классический алогоритм двух указателей, один будет указывать на начало, другой на конец массива

```c++
int left = 0;
int right = nums.size() - 1;
```

Сравним первый элемент с переданным val и в случае если первый элемент равен val, поменяем его местами с последним элементом и сдвинем указатель right назад, если же первый элемент не равен val, сдвигаем указатель left вперед.

Итерируемся до тех пор, пока left <= right.

Рассмотрим на примере

![Иллюстрация](img/27.jpg)

#### Solution
```c++
int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right];
                --right;
            } else {
                ++left;
            }
        }

        return left;
}   
```

### 26. Remove Duplicates from Sorted Array

Дан целочисленный массив nums, отсортированный в порядке возрастания, необходимо удалить дубли "на месте" причем так, чтобы массив остался отсортированным и вернуть число уникальных элементов. Как и в предыдущей задаче, неважно что за элементы будут содержаться после уникальных

**Пример 1**
```c++
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Пример 2**
```c++
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Алгоритм**

Пройдемся обычным циклом по всему массиву, сравнивая текущий и предыдущий элемент, предварительно создав указатель для отслеживания позиции (indexForUniqueElem = 1), на которую нужно вставить уникальный элемент

Итерироваться будем с индекса 1, т.к. элемент под индексом 0 всегда уникальный

К примеру имеем массив 

```c++
nums = [1,1,2]
```

Сравниваем текущей элемент итерации с предыдущим и в случае, если они не равны, записываем в nums[indexForUniqueElem] = nums[i] и сдвигаем указатель ++indexForUniqueElem

В противном случае ничего не делаем

Рассмотрим алгоритм на следующем примере 

![Иллюстрация](img/26.jpg)