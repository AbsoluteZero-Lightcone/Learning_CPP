/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;

class Fish{};

int random() {
    time_t now;
    time(&now);
    srand(now);
    return rand();
}

bool isContinue() {
    string command;
    cout << "您要结束养鱼吗？(Y/N) : ";
    cin >> command;
    if (command == "y" || command == "Y")
        return 1;
    else if (command == "n" || command == "N")
        return 0;
    else {
        cerr << "Invalid command." << endl;
        return isContinue();
    }
}

int main(){
    do {
        cout << "您要养几条鱼（N>=5）: ";
        int N;
        cin >> N;
        Fish** fish = new Fish * [N];
        string name, color;
        for (int i = 0; i < N; i++) {
            cout << "请输入第" << i + 1 << "条鱼的名字、颜色：";
            cin >> name >> color;
            fish[i] = new Fish(name, color);
        }
        cout << "开始养鱼了！" << endl;
        int day = 1;
        cout << "第" << day << "天：";
        fish[random() % N]->eat();
    } while (isContinue());
    return 0;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
