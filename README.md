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

[Подробное описание](https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150)

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

### 80. Remove Duplicates from Sorted Array II

Пока что пропустил

### 169. Majority Element

Дан целочисленный массив nums, необходимо вернуть наиболее часто встречающийся элемент (элемент, который появляется более ⌊n / 2⌋ раз, где n - размер массива).

[Подробное описание](https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150)

**Пример 1**
```c++
Input: nums = [3,2,3]
Output: 3
```

**Пример 2**
```c++
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

Решим с помощью hashMap (словарь на основе хэш таблицы) просто посчитав кол-во вхождений каждого числа

```c++
int majorityElement(vector<int>& nums) {
    unordered_map<int, int>hash;
    int majority = nums.size() / 2;
    
    for (int i = 0; i < nums.size(); ++i) {
        ++hash[nums[i]];
        if (hash[nums[i]] > majority) {
            return nums[i];
        }
    }
    
    return -1;
}
```

### 189. Rotate Array

Дан целочисленный массив nums, необходимо "перевернуть" его заданное k количество раз

[Подробное описание](https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150)

**Пример 1**
```c++
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

**Пример 2**
```c++
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]

Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

**Решение**

Можно сразу увидеть

![Иллюстрация](img/189.jpg)

Единственное, нужно учесть, что число k может быть больше размерности массива, поэтому в самом начале 

```c++
int n = nums.size();
if (n == 0) return;
k = k % n; 
```

```c++
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    k = k % n; 
    
    std::vector<int> tmp;
    tmp.reserve(n); 
    
    for (int i = n - k; i < n; ++i) {
        tmp.push_back(nums[i]); 
    }
    
    for (int i = 0; i < n - k; ++i) {
        tmp.push_back(nums[i]); 
    }
    
    nums = tmp; 
    }
```

### 121. Best Time to Buy and Sell Stock

Дан целочисленный массив prices, где prices[i] - это цена акции на текущий момент.

Необходимо сначала купить и потом продать акцию (покупка и продажа осуществляется единожды!), выручив максимальную прибыль.

[Подробное описание](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1609542553/?envType=study-plan-v2&envId=top-interview-150)

**Пример 1**
```c++
Input: prices = [7,1,5,3,6,4]
Output: 5

Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

**Пример 2**
```c++
Input: prices = [7,6,4,3,1]
Output: 0

Explanation: In this case, no transactions are done and the max profit = 0.
```

**Решение**

Для соблюдения условия "сначала купить - потом продать" используем обычный цикл, в первой проверке постараемся обновить минимально известную цену и уже в следующей будем из элемента текущей итерации вычитать минимально известный (это обеспечит условие, что сначала акция должна быть куплена)

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
};
```

### 122. Best Time to Buy and Sell Stock II

Дан целочисленный массив prices, где prices[i] - это цена акции на текущий момент.

Необходимо сначала купить и потом продать акцию, выручив максимальную прибыль, покупать и продавать можно неограниченное кол-во раз, причем можно купить и сразу продать (весь подвох кроется в этом условии), также в единый момент времени можно владеть лишь одной акцией.

[Подробное описание](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150)


**Пример 1**
```c++
Input: prices = [7,1,5,3,6,4]
Output: 7

Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

```

**Пример 2**
```c++
Input: prices = [1,2,3,4,5]
Output: 4

Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
```

**Пример 3**
```c++
Input: prices = [7,6,4,3,1]
Output: 0

Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
```

Суть решения заключается в этом условии:
 "вы можете купить акцию, а затем продать в этот же день" 

 Рассмотрим на примере что это значит, предположим массив prices выглядит следующим образом:

 ```c++
 prices = [1, 10, 90];
 ```

 **Решение**

 Интуитивно понятно, что самым выгодным решением будет купить акцию за одну условную единицу и продать за 90 у.е. , таким образом выручив 89 у.е.

 Можно ли как то иначе получит эту сумму?

 На самом деле да, мы можем купить акцию за 1 у.е., затем продать ее за 10 у.е. и сразу же купить за те же 10 у.е., для того чтобы потом продать ее за 90 у.е. и в результате мы получим точно такую сумму.

Теперь становится понятно, что покупать акцию нужно тогда, как есть хотя бы минимальный профит 

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
```
