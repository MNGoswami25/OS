#include <iostream>
#include <condition_variable>
using namespace std;
int myMutex = 1, full = 0, empty = 3, x = 0;
int wait(int s) {
    return (--s);
}
int signal(int s) {
    return (++s);
}
void producer() {
    myMutex = wait(myMutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    cout << "\nProducer produces the item " << x << endl;
    myMutex = signal(myMutex);
}
void consumer() {
    myMutex = wait(myMutex);
    full = wait(full);
    empty = signal(empty);
    cout << "\nConsumer consumes item " << x << endl;
    x--;
    myMutex = signal(myMutex);
}
int main() {
    int n;
    cout << "\n1. PRODUCER\n2. CONSUMER\n3. EXIT\n";
    while (true) {
        cout << "\nENTER YOUR CHOICE\n";
        cin >> n;
        switch (n) {
            case 1:
                if (myMutex == 1 && empty != 0)
                    producer();
                else
                    cout << "BUFFER IS FULL" << endl;
                break;

            case 2:
                if (myMutex == 1 && full != 0)
                    consumer();
                else
                    cout << "BUFFER IS EMPTY" << endl;
                break;

            case 3:
                return 0;
        }
    }
    return 0;
}
