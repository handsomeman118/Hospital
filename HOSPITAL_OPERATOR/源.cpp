#include<iostream>
#include<string.h>
using namespace std;
#define NAME_LEN 100
#define PEOPLE_NUM 45
#define B_NUM 45
class Hospital
{
private:
    // �������֣������Ա�ҽ�����֣�ҽ���Ա�
    char patientName[PEOPLE_NUM][NAME_LEN], patientSex[PEOPLE_NUM], doctorName[PEOPLE_NUM][NAME_LEN], doctorSex[PEOPLE_NUM];
    // �������䣬ҽ���Һ�������Сʱ�����ӣ�ʱ�䣩
    int patientAge[PEOPLE_NUM], doctorRegisteredNum[PEOPLE_NUM]{ 0 }, hour[PEOPLE_NUM], minute[PEOPLE_NUM];
    // ��¼���˿��Ҽ���ҽ��
    int patientRegisteredRoom[PEOPLE_NUM], patientRegisteredDoctor[PEOPLE_NUM];
    // b���������֣������Ա�
    char bPatientName[PEOPLE_NUM][NAME_LEN], bPatientSex[PEOPLE_NUM];
    // �������䣬B��ԤԼ������Сʱ�����ӣ�ʱ�䣩
    int bPatientAge[PEOPLE_NUM], bBookingNum[B_NUM]{ 0 }, bHour[PEOPLE_NUM], bMinute[PEOPLE_NUM];
    // ����ԤԼ�Ļ��������洢
    int patientBookingMachine[PEOPLE_NUM];
    bool registeredJudge[PEOPLE_NUM] = { 0 }, bookingJudge[PEOPLE_NUM] = { 0 };
public:
    // ��ʾ����ҽ�������㲡��ѡȡ
    void doctorShow(int x)
    {
        for (int i = 0; i < 3; i++)
            // �˴�ӦΪҽ����������δ¼��                              // �˴�ӦΪ����ҽ����Ϣ���Ա�(δ¼��)
            cout << "����" << i + 1 << ":" << "ҽ��������Ϊ��" << /*doctorName[x * (i + 1)][100]*/"?" << " " << "�Ա�Ϊ��" << /*doctorSex[x * (i + 1)]*/"?" << " " << "�ѹҺ�����Ϊ��" << doctorRegisteredNum[x * (i + 1)] << '\n' << '\n';
    }
    // �Һż�¼������Ϣ
    void patientRegistered(int room, int doctor);
    // ԤԼ��¼������Ϣ
    void bBooking(int bChoose);
    // ��ʾ����ԤԼ��Ϣ
    void bShow()
    {
        for (int i = 0; i < 3; i++) cout << "����" << i + 1 << ":" << " " << "��ԤԼ����Ϊ��" << bBookingNum[i + 1] << '\n' << '\n';
    }
    void doctorRegisteredShow(int room);
    void bBookingShow();
};
// �Һż�¼������Ϣ
void Hospital::patientRegistered(int room, int doctor)
{
    int i;
    for (i = 0;registeredJudge[i] == 1;i++);
    registeredJudge[i] = !registeredJudge[i];
    cout << "����������������";
    cin >> patientName[i];cout << '\n';
    while (1)
    {
        cout << "�����������Ա�(��_m;Ů_f)��";
        cin >> patientSex[i];
        cout << '\n';
        if (patientSex[i] == 'f' || patientSex[i] == 'm')
            break;
        else cout << "�����Ա��������������������Ա�" << '\n' << '\n';
    }
    cout << "�������������䣺";cin >> patientAge[i];
    cout << '\n';
    cout << "�����뵱ǰ�Һ�ʱ�䣺������Сʱ��";cin >> hour[i];
    cout << '\n';
    cout << "��������ӣ�";
    cin >> minute[i];cout << '\n';
    if (minute[i] >= 60) { minute[i] %= 60;++hour[i]; }
    if (hour[i] >= 24) hour[i] %= 24;
    cout << "�Һųɹ���" << '\n' << '\n';
    cout << "������" << patientName[i] << "  " << "�Ա�" << patientSex[i] << "  " << "���䣺" << patientAge[i] << "  " << "�Һ�ʱ�䣺" << hour[i] << " : " << minute[i] << '\n' << '\n';
    patientRegisteredRoom[i] = room;patientRegisteredDoctor[i] = doctor;
    cout << "�Һſ���: " << patientRegisteredRoom[i] << "����" << "    " << "�Һ�ҽ����ҽ��" << patientRegisteredDoctor[i] << "  " << '\n' << '\n';
    doctorRegisteredNum[room * doctor]++;
}
// ԤԼ��¼������Ϣ
void Hospital::bBooking(int bChoose)
{
    int i;
    for (i = 0;registeredJudge[i] == 1;i++);
    bookingJudge[i] = !bookingJudge[i];
    cout << "����������������";
    cin >> bPatientName[i];
    cout << '\n';
    cout << "�����������Ա�(��_m;Ů_f)��";
    do
    {
        cin >> bPatientSex[i];
        cout << '\n';
        if (bPatientSex[i] != 'f' && bPatientSex[i] != 'm')
        {
            cout << "�����Ա��������������������Ա�" << '\n' << '\n';
            cout << "�����������Ա�(��_m;Ů_f)��";
        }
    } while (bPatientSex[i] != 'f' && bPatientSex[i] != 'm');
    cout << "�������������䣺";
    cin >> bPatientAge[i];cout << '\n';
    cout << "�����뵱ǰ�Һ�ʱ�䣺������Сʱ��";
    cin >> bHour[i];cout << '\n';
    cout << "��������ӣ�";
    cin >> bMinute[i];cout << '\n';
    if (bMinute[i] >= 60) { bMinute[i] %= 60;++bHour[i]; }
    if (bHour[i] >= 24)bHour[i] %= 24;
    cout << "ԤԼ�ɹ���" << '\n' << '\n';
    cout << "������" << bPatientName[i] << "  " << "�Ա�" << bPatientSex[i] << "  " << "���䣺" << bPatientAge[i] << "  " << "ԤԼʱ�䣺" << bHour[i] << " : " << bMinute[i] << '\n' << '\n';
    patientBookingMachine[i] = bChoose;
    cout << "ԤԼB��������: " << patientBookingMachine[i] << "�Ż���" << '\n' << '\n';
    bBookingNum[bChoose]++;
    system("pause");
}
// ���ҹҺŲ�ѯ����
void Hospital::doctorRegisteredShow(int room)
{

    int i;
    cout << "����" << room << ":" << '\n';
    //  ҽ��1�ĹҺ���Ϣ
    cout << "ҽ��: " << 1 << "ҽ��" << "   " << "�Һ�����" << doctorRegisteredNum[room * 1] << ":" << '\n' << '\n';
    for (i = 0;registeredJudge[i] == 1;i++)  if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 1)
        cout << "�Һ������֣�" << patientName[i] << "  " << "�Һ�ʱ�䣺" << hour[i] << ":" << minute[i] << '\n';
    cout << '\n' << '\n';
    //  ҽ��2�ĹҺ���Ϣ
    cout << "ҽ��: " << 2 << "ҽ��" << "   " << "�Һ�����" << doctorRegisteredNum[room * 2] << ":" << '\n' << '\n';
    for (i = 0;registeredJudge[i] == 1;i++)
        if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 2)
            cout << "�Һ������֣�" << patientName[i] << "  " << "�Һ�ʱ�䣺" << hour[i] << ":" << minute[i] << '\n';
    cout << '\n' << '\n';
    //  ҽ��3�ĹҺ���Ϣ
    cout << "ҽ��: " << 3 << "ҽ��" << "   " << "�Һ�����" << doctorRegisteredNum[room * 3] << ":" << '\n' << '\n';
    for (i = 0;registeredJudge[i] == 1;i++)
        if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 3)
            cout << "�Һ������֣�" << patientName[i] << "  " << "�Һ�ʱ�䣺" << hour[i] << ":" << minute[i] << '\n';
    cout << '\n' << '\n';
}
// ���B��������ѯ����
void Hospital::bBookingShow()
{
    int i;
    cout << "B����" << 1 << "��" << "   " << "ԤԼ������" << bBookingNum[1] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 1)
            cout << "ԤԼ�����֣�" << bPatientName[i] << "  " << "ԤԼʱ�䣺" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
    cout << "B����" << 2 << "��" << "   " << "ԤԼ������" << bBookingNum[2] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 2)
            cout << "ԤԼ�����֣�" << bPatientName[i] << "  " << "ԤԼʱ�䣺" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
    cout << "B����" << 3 << "��" << "   " << "ԤԼ������" << bBookingNum[3] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 3)
            cout << "ԤԼ�����֣�" << bPatientName[i] << "  " << "ԤԼʱ�䣺" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
}
Hospital Using;
// �����ĸ�����ѡ��,����Ŀ��Һ�,�����ҽ����
int firstOpe, secondeOpe, thirdOpe, room, doctor;
// B��ѡ��
int bChoose;
// ѡ��Һ�ҽ��
void registeredDoctor()
{
    cout << "����������������һ�0����ѡ��Һ�ҽ����1��3��" << '\n' << '\n';
    Using.doctorShow(room);
    cin >> thirdOpe;
    cout << '\n';
    doctor = thirdOpe;
    if (thirdOpe >= 1 && thirdOpe <= 3)
        Using.patientRegistered(room, doctor);
    else if (thirdOpe != 0)cout << "��������ȷ������" << '\n' << '\n';
}
// ѡ��Һſ���
void registeredRoom()
{
    secondeOpe = -1;
    cout << "����������������һ�0����ѡ��Һſ��ң�1��15��" << '\n' << '\n';
    cin >> secondeOpe;
    room = secondeOpe;
    cout << '\n';
    if (secondeOpe <= 15 && secondeOpe >= 1)
    {
        thirdOpe = -1;
        while (thirdOpe != 0)
        {
            registeredDoctor();
        }
    }
    else if (secondeOpe != 0)cout << "��������ȷ������" << '\n' << '\n';
}

void bookingMachine()
{
    cout << "����������������һ�0����ѡ��B������1��3��" << '\n' << '\n';
    Using.bShow();
    cin >> secondeOpe;
    bChoose = secondeOpe;
    cout << '\n';
    if (secondeOpe >= 1 && secondeOpe <= 3) Using.bBooking(bChoose);
    else if (secondeOpe != 0)
        cout << "��������ȷ������" << '\n' << '\n';
}
void inquireRegistered()
{
    cout << "����������������һ�0����ѡ��鿴���ң�1��15��" << '\n' << '\n';
    cin >> thirdOpe;
    cout << '\n';
    if (thirdOpe >= 1 && thirdOpe <= 15)
    {
        room = thirdOpe;
        Using.doctorRegisteredShow(room);
    }
    else if (thirdOpe != 0)cout << "��������ȷ������" << '\n' << '\n';
}
void inquireChoose()
{
    cout << "����������������һ�0�����鿴���ҹҺ������1�����鿴B����ԤԼ�����2)" << '\n' << '\n';
    cin >> secondeOpe;
    cout << '\n';
    if (secondeOpe == 1)
    {
        thirdOpe = -1;
        while (thirdOpe != 0)
        {
            inquireRegistered();
        }
    }
    else if (secondeOpe == 2)
    {
        Using.bBookingShow();
        cout << '\n';
    }
    else if (secondeOpe != 0)  cout << "��������ȷ������" << '\n' << '\n';
}
// �ҺŹ���
void registered()
{
    secondeOpe = -1;
    while (secondeOpe != 0)
    {
        thirdOpe = -1;
        registeredRoom();
    }
}
// B��ԤԼ����
void booking()
{
    secondeOpe = -1;
    while (secondeOpe != 0)
    {
        thirdOpe = -1;
        bookingMachine();
    }
}
// ��Ϣ��ѯ����
void seeInformation()
{
    secondeOpe = -1;
    while (secondeOpe != 0)
    {
        thirdOpe = -1;
        inquireChoose();
    }
}
int main()
{
    // ������ʼֵ����ѭ��
    firstOpe = -1;
    while (firstOpe != 0)
    {
        cout << "�����������˳�����0�������ҹҺţ�1����B��ԤԼ��2�����鿴�Һż�ԤԼ��Ϣ��3��" << '\n' << '\n';
        cin >> firstOpe;
        cout << '\n';
        switch (firstOpe)
        {
        case 1:
            registered();
            break;
        case 2:
            booking();
            break;
        case 3:
            seeInformation();
            break;
        default:
            cout << "��������ȷ������" << '\n';
        }
    }
    cout << "�˳�����" << '\n';
    system("pause");
    return 0;
}
