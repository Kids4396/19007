#include <stdio.h>
#include <string.h>

#define nums 14 //�˴���������
#define num 2 * nums + 1

void printState(int state[num]) {
    for (int j = 0; j < num; ++j) {             //��ʼ���������е�ֵ
        if (state[j] == 0)                      //���ֵΪ0
            printf("    ");                    //�������λ�������ո�
        else                                    //����
            printf("%4d", state[j]);            //�������ǰ�油λ�ո������
    }
    printf("\n");                                //����
}

void yanghuiA() {
    int lastState[num] = {0};                                   //��ʼ����ʼ����
    int newState[num];                                          //��ʼ���޸ĺ�����
    lastState[nums] = 1;                                        //���ʼ������м�ֵΪ1
    printState(lastState);                                      //��ӡ��һ�е�����
    for (int i = 0; i < nums; ++i) {                            //��ʼѭ��
        newState[0] = lastState[1];                             //�����������������ߵ�ֵΪ��һ�����������߿���һλ��ֵ
        newState[num - 1] = lastState[num - 2];                 //ͬ��
        for (int j = 1; j < num - 1; ++j) {                     //��ʼ�м���ѭ��
            newState[j] = lastState[j - 1] + lastState[j + 1];  //��һ���������ֵ���ǰһ�������Ӧλ��ǰ�������
        }
        printState(newState);                                   //��ӡ������
        memcpy(&lastState, &newState, sizeof(lastState));       //#�º���# �������鸴�Ƶ������飬��Ϊ��һ��ѭ������һ��
    }
}

void yanghui() {
    int a[nums][nums] = {0};
    a[0][0] = 1;
    for (int i = 0; i < nums; ++i) {
        for (int j = 0; j < i; ++j)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
    for (int i = 0; i < nums; ++i) {
        for (int j = 0; j < i; ++j)
            printf("%3d ", a[i][j]);
        printf("\n");
    }
}
//쳲������ݹ�ʵ�� 
void fibonacciA() {
    int a = 1, b = 1, c;
    printf("%3d %3d ", a, b);
    for (int i = 2; i < nums; ++i) {
        c = a + b;
        printf("%3d ", c);
        a = b;
        b = c;
    }
}

//쳲���������ʵ�� 
void fibonacci() {
    int a[nums];
    a[0]=a[1]=1;
    for (int i = 2; i < nums; ++i) {
        a[i] = a[i - 2] + a[i - 1];
    }
    for (int i = 0; i < nums; ++i) {
        printf("%3d ", a[i]);
    }
}

int main() {
    fibonacci();
}

