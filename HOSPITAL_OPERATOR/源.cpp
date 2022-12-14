#include<iostream>
#include<string.h>
using namespace std;
#define NAME_LEN 100
#define PEOPLE_NUM 45
#define B_NUM 45
class Hospital
{
private:
    // 病人名字，病人性别，医生名字，医生性别
    char patientName[PEOPLE_NUM][NAME_LEN], patientSex[PEOPLE_NUM], doctorName[PEOPLE_NUM][NAME_LEN], doctorSex[PEOPLE_NUM];
    // 病人年龄，医生挂号人数，小时，分钟（时间）
    int patientAge[PEOPLE_NUM], doctorRegisteredNum[PEOPLE_NUM]{ 0 }, hour[PEOPLE_NUM], minute[PEOPLE_NUM];
    // 记录病人科室及其医生
    int patientRegisteredRoom[PEOPLE_NUM], patientRegisteredDoctor[PEOPLE_NUM];
    // b超病人名字，病人性别
    char bPatientName[PEOPLE_NUM][NAME_LEN], bPatientSex[PEOPLE_NUM];
    // 病人年龄，B超预约人数，小时，分钟（时间）
    int bPatientAge[PEOPLE_NUM], bBookingNum[B_NUM]{ 0 }, bHour[PEOPLE_NUM], bMinute[PEOPLE_NUM];
    // 病人预约的机器号数存储
    int patientBookingMachine[PEOPLE_NUM];
    bool registeredJudge[PEOPLE_NUM] = { 0 }, bookingJudge[PEOPLE_NUM] = { 0 };
public:
    // 显示科室医生，方便病人选取
    void doctorShow(int x)
    {
        for (int i = 0; i < 3; i++)
            // 此处应为医生姓名但是未录入                              // 此处应为储存医生信息的性别(未录入)
            cout << "操作" << i + 1 << ":" << "医生的名字为：" << /*doctorName[x * (i + 1)][100]*/"?" << " " << "性别为：" << /*doctorSex[x * (i + 1)]*/"?" << " " << "已挂号人数为：" << doctorRegisteredNum[x * (i + 1)] << '\n' << '\n';
    }
    // 挂号记录病人信息
    void patientRegistered(int room, int doctor);
    // 预约记录病人信息
    void bBooking(int bChoose);
    // 显示机器预约信息
    void bShow()
    {
        for (int i = 0; i < 3; i++) cout << "机器" << i + 1 << ":" << " " << "已预约人数为：" << bBookingNum[i + 1] << '\n' << '\n';
    }
    void doctorRegisteredShow(int room);
    void bBookingShow();
};
// 挂号记录病人信息
void Hospital::patientRegistered(int room, int doctor)
{
    int i;
    for (i = 0;registeredJudge[i] == 1;i++);
    registeredJudge[i] = !registeredJudge[i];
    cout << "请输入您的姓名：";
    cin >> patientName[i];cout << '\n';
    while (1)
    {
        cout << "请输入您的性别(男_m;女_f)：";
        cin >> patientSex[i];
        cout << '\n';
        if (patientSex[i] == 'f' || patientSex[i] == 'm')
            break;
        else cout << "您的性别输入有误，请重新输入性别。" << '\n' << '\n';
    }
    cout << "请输入您的年龄：";cin >> patientAge[i];
    cout << '\n';
    cout << "请输入当前挂号时间：请输入小时：";cin >> hour[i];
    cout << '\n';
    cout << "请输入分钟：";
    cin >> minute[i];cout << '\n';
    if (minute[i] >= 60) { minute[i] %= 60;++hour[i]; }
    if (hour[i] >= 24) hour[i] %= 24;
    cout << "挂号成功：" << '\n' << '\n';
    cout << "姓名：" << patientName[i] << "  " << "性别：" << patientSex[i] << "  " << "年龄：" << patientAge[i] << "  " << "挂号时间：" << hour[i] << " : " << minute[i] << '\n' << '\n';
    patientRegisteredRoom[i] = room;patientRegisteredDoctor[i] = doctor;
    cout << "挂号科室: " << patientRegisteredRoom[i] << "科室" << "    " << "挂号医生：医生" << patientRegisteredDoctor[i] << "  " << '\n' << '\n';
    doctorRegisteredNum[room * doctor]++;
}
// 预约记录病人信息
void Hospital::bBooking(int bChoose)
{
    int i;
    for (i = 0;registeredJudge[i] == 1;i++);
    bookingJudge[i] = !bookingJudge[i];
    cout << "请输入您的姓名：";
    cin >> bPatientName[i];
    cout << '\n';
    cout << "请输入您的性别(男_m;女_f)：";
    do
    {
        cin >> bPatientSex[i];
        cout << '\n';
        if (bPatientSex[i] != 'f' && bPatientSex[i] != 'm')
        {
            cout << "您的性别输入有误，请重新输入性别。" << '\n' << '\n';
            cout << "请输入您的性别(男_m;女_f)：";
        }
    } while (bPatientSex[i] != 'f' && bPatientSex[i] != 'm');
    cout << "请输入您的年龄：";
    cin >> bPatientAge[i];cout << '\n';
    cout << "请输入当前挂号时间：请输入小时：";
    cin >> bHour[i];cout << '\n';
    cout << "请输入分钟：";
    cin >> bMinute[i];cout << '\n';
    if (bMinute[i] >= 60) { bMinute[i] %= 60;++bHour[i]; }
    if (bHour[i] >= 24)bHour[i] %= 24;
    cout << "预约成功：" << '\n' << '\n';
    cout << "姓名：" << bPatientName[i] << "  " << "性别：" << bPatientSex[i] << "  " << "年龄：" << bPatientAge[i] << "  " << "预约时间：" << bHour[i] << " : " << bMinute[i] << '\n' << '\n';
    patientBookingMachine[i] = bChoose;
    cout << "预约B超机器号: " << patientBookingMachine[i] << "号机器" << '\n' << '\n';
    bBookingNum[bChoose]++;
    system("pause");
}
// 科室挂号查询功能
void Hospital::doctorRegisteredShow(int room)
{

    int i;
    cout << "科室" << room << ":" << '\n';
    //  医生1的挂号信息
    cout << "医生: " << 1 << "医生" << "   " << "挂号人数" << doctorRegisteredNum[room * 1] << ":" << '\n' << '\n';
    for (i = 0;registeredJudge[i] == 1;i++)  if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 1)
        cout << "挂号人名字：" << patientName[i] << "  " << "挂号时间：" << hour[i] << ":" << minute[i] << '\n';
    cout << '\n' << '\n';
    //  医生2的挂号信息
    cout << "医生: " << 2 << "医生" << "   " << "挂号人数" << doctorRegisteredNum[room * 2] << ":" << '\n' << '\n';
    for (i = 0;registeredJudge[i] == 1;i++)
        if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 2)
            cout << "挂号人名字：" << patientName[i] << "  " << "挂号时间：" << hour[i] << ":" << minute[i] << '\n';
    cout << '\n' << '\n';
    //  医生3的挂号信息
    cout << "医生: " << 3 << "医生" << "   " << "挂号人数" << doctorRegisteredNum[room * 3] << ":" << '\n' << '\n';
    for (i = 0;registeredJudge[i] == 1;i++)
        if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 3)
            cout << "挂号人名字：" << patientName[i] << "  " << "挂号时间：" << hour[i] << ":" << minute[i] << '\n';
    cout << '\n' << '\n';
}
// 完成B超机器查询功能
void Hospital::bBookingShow()
{
    int i;
    cout << "B超机" << 1 << "：" << "   " << "预约人数：" << bBookingNum[1] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 1)
            cout << "预约人名字：" << bPatientName[i] << "  " << "预约时间：" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
    cout << "B超机" << 2 << "：" << "   " << "预约人数：" << bBookingNum[2] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 2)
            cout << "预约人名字：" << bPatientName[i] << "  " << "预约时间：" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
    cout << "B超机" << 3 << "：" << "   " << "预约人数：" << bBookingNum[3] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 3)
            cout << "预约人名字：" << bPatientName[i] << "  " << "预约时间：" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
}
Hospital Using;
// 操作的各部分选择,储存的科室号,储存的医生号
int firstOpe, secondeOpe, thirdOpe, room, doctor;
// B超选择
int bChoose;
// 选择挂号医生
void registeredDoctor()
{
    cout << "请输入操作项：返回上一项（0），选择挂号医生（1—3）" << '\n' << '\n';
    Using.doctorShow(room);
    cin >> thirdOpe;
    cout << '\n';
    doctor = thirdOpe;
    if (thirdOpe >= 1 && thirdOpe <= 3)
        Using.patientRegistered(room, doctor);
    else if (thirdOpe != 0)cout << "请输入正确操作项" << '\n' << '\n';
}
// 选择挂号科室
void registeredRoom()
{
    secondeOpe = -1;
    cout << "请输入操作项：返回上一项（0），选择挂号科室（1—15）" << '\n' << '\n';
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
    else if (secondeOpe != 0)cout << "请输入正确操作项" << '\n' << '\n';
}

void bookingMachine()
{
    cout << "请输入操作项：返回上一项（0），选择B超机（1—3）" << '\n' << '\n';
    Using.bShow();
    cin >> secondeOpe;
    bChoose = secondeOpe;
    cout << '\n';
    if (secondeOpe >= 1 && secondeOpe <= 3) Using.bBooking(bChoose);
    else if (secondeOpe != 0)
        cout << "请输入正确操作项" << '\n' << '\n';
}
void inquireRegistered()
{
    cout << "请输入操作项：返回上一项（0），选择查看科室（1—15）" << '\n' << '\n';
    cin >> thirdOpe;
    cout << '\n';
    if (thirdOpe >= 1 && thirdOpe <= 15)
    {
        room = thirdOpe;
        Using.doctorRegisteredShow(room);
    }
    else if (thirdOpe != 0)cout << "请输入正确操作项" << '\n' << '\n';
}
void inquireChoose()
{
    cout << "请输入操作项：返回上一项（0），查看科室挂号情况（1），查看B超机预约情况（2)" << '\n' << '\n';
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
    else if (secondeOpe != 0)  cout << "请输入正确操作项" << '\n' << '\n';
}
// 挂号功能
void registered()
{
    secondeOpe = -1;
    while (secondeOpe != 0)
    {
        thirdOpe = -1;
        registeredRoom();
    }
}
// B超预约功能
void booking()
{
    secondeOpe = -1;
    while (secondeOpe != 0)
    {
        thirdOpe = -1;
        bookingMachine();
    }
}
// 信息查询功能
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
    // 调整初始值进入循环
    firstOpe = -1;
    while (firstOpe != 0)
    {
        cout << "请输入操作项：退出程序（0），科室挂号（1），B超预约（2），查看挂号及预约信息（3）" << '\n' << '\n';
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
            cout << "请输入正确操作项" << '\n';
        }
    }
    cout << "退出程序。" << '\n';
    system("pause");
    return 0;
}
