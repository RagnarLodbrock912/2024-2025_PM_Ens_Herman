#include <iostream> 
using namespace std;

// Функция проверки числа на простоту
bool prostoe(int num) {
  if (num <= 1) return 0; 
  for (int i = 2; i * i <= num; ++i) if (num % i == 0) return 0; 
  return 1; 
}

bool has7No6 (int num) {
    bool seven = false; // Флаг наличия цифры 7
    bool six = false;  // Флаг наличия цифры 6
    while (num > 0) { // Проверяем наличие цифр 6 и 7 в числе
      int digit = num % 10; 
      if (digit == 7) seven = true;
      if (digit == 6) six = true;
      num /= 10; 
    }
    if (seven)
        if(!six)
            return true;
    return false;
    
}
int main() {
    const int MAX = 10000; 
    int n;

    cout << "Enter n\n";
    cin >> n; 

    if (n <= 0 || n > MAX) { // Проверка на корректность ввода
        cout << "Uncorrect n" << endl;
    return 1;
    }

    int numbers[MAX]; 
    cout << "Enter the sequense\n";
    for (int i = 0; i < n; ++i) { 
        cin >> numbers[i];
    }

    int count = 0; // Счетчик для нового размера массива после удаления элементов

    for (int i = 0; i < n; ++i) { 
    if (!has7No6(numbers[i])) { // число должно быть сохранено, если оно не содержит 7 И НЕ содержит 6
        numbers[count++] = numbers[i]; // Сохраняем число, если условие выполнено
    }
    }
    n = count; // Новый размер массива после удаления элементов

    for (int i = 0; i < n; ++i) { 
    if (prostoe(numbers[i])) { 
        n++;
        for (int j = n - 1; j > i; j--) {
            numbers[j] = numbers[j - 1];
        }
        i++;
    }
    }

    cout << "Final sequence:\n";
        for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}