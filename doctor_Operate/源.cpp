#include<iostream>
#include<string.h>
using namespace std;
class Hospital
{
private:
    char patientName[45][100], patientSex[45], doctorName[46][100], doctorSex[46];  //病人名字，病人性别，医生名字，医生性别
    int patientAge[100], doctorRegisteredNum[46]{ 0 }, hour[46], minute[46];               //病人年龄，医生挂号人数，小时，分钟（时间）
    int patientRegisteredRoom[45], patientRegisteredDoctor[45];                                       //记录病人科室及其医生；
    char bPatientName[45][100], bPatientSex[45];                                     //b超病人名字，病人性别
    int bPatientAge[100], bBookingNum[4]{ 0 }, bHour[44], bMinute[44];                //病人年龄，B超预约人数，小时，分钟（时间）
    int patientBookingMachine[45];                                                 //病人预约的机器号数存储
    bool registeredJudge[45] = { 0 }, bookingJudge[45] = { 0 };                                   
public:
    void doctorShow(int x)
    {
        for (int i = 0; i < 3; i++) cout << "操作" << i + 1 << ":" << "医生的名字为：" << doctorName[x * (i + 1)][100] << " " << "性别为：" << doctorSex[x * (i + 1)] << " " << "已挂号人数为：" << doctorRegisteredNum[x * (i+1)] << '\n' << '\n';
    }
    //显示科室医生，方便病人选取
    void patientRegistered(int room, int doctor);        //挂号记录病人信息
    void bBooking(int bChoose);                               //预约记录病人信息
    void bShow()                                           //显示机器预约信息
    {
        for (int i = 0; i < 3; i++) cout << "机器" << i+1 << ":" <<" " << "已预约人数为：" << bBookingNum[i+1] << '\n' << '\n';
    }                  
    void doctorRegisteredShow(int room);
    void bBookingShow();
};
void Hospital::patientRegistered(int room, int doctor)    //挂号记录病人信息
{
    int i = 0;
    while (registeredJudge[i] == 1)i++;
    registeredJudge[i] = !registeredJudge[i];
    cout << "请输入您的姓名：";cin >> patientName[i];cout << '\n';
    while (1)
    {
        cout << "请输入您的性别(男_m;女_f)：";cin >> patientSex[i];cout << '\n';
        if (patientSex[i] == 'f' || patientSex[i] == 'm')break;
        else cout << "您的性别输入有误，请重新输入性别。" << '\n' << '\n';;
    }
    cout << "请输入您的年龄：";cin >> patientAge[i];cout << '\n';
    cout << "请输入当前挂号时间：请输入小时：";cin >> hour[i];cout << '\n';cout << "请输入分钟："; cin >> minute[i];cout << '\n';
    if (minute[i] >= 60) { minute[i] %= 60;++hour[i]; }
    if (hour[i] >= 24) hour[i] %= 24;
    cout << "挂号成功：" << '\n' << '\n';
    cout << "姓名：" << patientName[i] << "  " << "性别：" << patientSex[i] << "  " << "年龄：" << patientAge[i] << "  " << "挂号时间：" << hour[i] << " : " << minute[i] << '\n' << '\n';
    patientRegisteredRoom[i] = room;patientRegisteredDoctor[i] = doctor;
    cout << "挂号科室: " << patientRegisteredRoom[i] << "科室" << "    " << "挂号医生：医生" << patientRegisteredDoctor[i] << "  " << '\n' << '\n';
    doctorRegisteredNum[room * doctor]++;
}
void Hospital::bBooking(int bChoose)           //预约记录病人信息
{
    int i = 0;
    while (bookingJudge[i] == 1)i++;
    bookingJudge[i] = !bookingJudge[i];
    cout << "请输入您的姓名：";cin >> bPatientName[i];cout << '\n';
    cout << "请输入您的性别(男_m;女_f)：";
    do 
    {
        cin >> bPatientSex[i];cout << '\n';
        if (bPatientSex[i] != 'f' && bPatientSex[i] != 'm')
        {
            cout << "您的性别输入有误，请重新输入性别。" << '\n' << '\n';
            cout << "请输入您的性别(男_m;女_f)：";
        }
    } while (bPatientSex[i] != 'f' && bPatientSex[i] != 'm');
    cout << "请输入您的年龄：";cin >> bPatientAge[i];cout << '\n';
    cout << "请输入当前挂号时间：请输入小时：";cin >> bHour[i];cout << '\n';cout << "请输入分钟："; cin >> bMinute[i];cout << '\n';
    if (bMinute[i] >= 60) { bMinute[i] %= 60;++bHour[i]; }
    if (bHour[i] >= 24) bHour[i] %= 24;
    cout << "预约成功：" << '\n' << '\n';
    cout << "姓名：" << bPatientName[i] << "  " << "性别：" << bPatientSex[i] << "  " << "年龄：" << bPatientAge[i] << "  " << "预约时间：" << bHour[i] << " : " << bMinute[i] << '\n' << '\n';
    patientBookingMachine[i] = bChoose;
    cout << "预约B超机器号: " << patientBookingMachine[i] << "号机器" << '\n' << '\n';
    bBookingNum[bChoose]++;
}
void Hospital::doctorRegisteredShow(int room)                      //科室挂号查询功能
{
    int i;
    cout << "科室" << room << ":" << '\n';
    cout << "医生: " << 1 << "医生" << "   " << "挂号人数" << doctorRegisteredNum[room * 1] << ":" << '\n' << '\n';
    i = 0;
    while (registeredJudge[i]==1)
    {
        if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 1)cout << "挂号人名字：" <<patientName[i]<< "  " << "挂号时间：" << hour[i] << ":" << minute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
    cout << "医生: " << 2 << "医生" << "   " << "挂号人数" << doctorRegisteredNum[room * 2] << ":" << '\n' << '\n';
    i = 0;
    while (registeredJudge[i] == 1)
    {
        if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 2)cout << "挂号人名字：" << patientName[i] << "  " << "挂号时间：" << hour[i] << ":" << minute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
    cout << "医生: " << 3 << "医生" << "   " << "挂号人数" << doctorRegisteredNum[room * 3] << ":" << '\n' << '\n';
    i = 0;
    while (registeredJudge[i] == 1)
    {
        if (patientRegisteredRoom[i] == room && patientRegisteredDoctor[i] == 3)cout << "挂号人名字：" << patientName[i] << "  " << "挂号时间：" << hour[i] << ":" << minute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
}
void Hospital::bBookingShow()                        //完成B超机器查询功能
{
    int i;
    cout << "B超机" << 1 << "：" << "   " << "预约人数：" << bBookingNum[1] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 1)cout << "预约人名字：" << bPatientName[i] << "  " << "预约时间：" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
    cout << "B超机" << 2 << "：" << "   " << "预约人数：" << bBookingNum[2] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 2)cout << "预约人名字：" << bPatientName[i] << "  " << "预约时间：" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
    cout << "B超机" << 3 << "：" << "   " << "预约人数：" << bBookingNum[3] << '\n' << '\n';
    i = 0;
    while (bookingJudge[i] == 1)
    {
        if (patientBookingMachine[i] == 3)cout << "预约人名字：" << bPatientName[i] << "  " << "预约时间：" << bHour[i] << ":" << bMinute[i] << '\n';
        i++;
    }
    cout << '\n' << '\n';
}
Hospital Using;
int choose[3], room, doctor;        //操作的各部分选择，储存的科室号，储存的医生号；
int bChoose;


void registeredDoctor()    //选择挂号医生
{
    cout << "请输入操作项：返回上一项（0），选择挂号医生（1—3）" << '\n' << '\n';
    Using.doctorShow(room);
    cin >> choose[2];
    cout << '\n';
    doctor = choose[2];
    if (choose[2] >= 1 && choose[2] <= 3) Using.patientRegistered(room, doctor);
    else if(choose[2]!=0)cout << "请输入正确操作项" << '\n' << '\n';
}
void registeredRoom()        //选择挂号科室
{
    cout << "请输入操作项：返回上一项（0），选择挂号科室（1—15）" << '\n' << '\n';
    cin >> choose[1];
    room = choose[1];
    cout << '\n';
    if (choose[1] <= 15 && choose[1] >= 1)
    {
        choose[2] = -1;
        while (choose[2] != 0)
        {
            registeredDoctor();
        }
    }
    else if (choose[1] != 0)cout << "请输入正确操作项" << '\n' << '\n';
}
void bookingMachine()
{
    cout << "请输入操作项：返回上一项（0），选择B超机（1—3）" << '\n' << '\n';
    Using.bShow();
    cin >> choose[1];
    bChoose = choose[1];
    cout << '\n';
    if (choose[1] >= 1 && choose[1] <= 3) Using.bBooking(bChoose);
    else if(choose[1] != 0)cout << "请输入正确操作项" << '\n' << '\n';
}
void inquireRegistered()
{
    cout << "请输入操作项：返回上一项（0），选择查看科室（1—15）" << '\n' << '\n';
    cin >> choose[2];
    cout << '\n';
    if (choose[2] >= 1 && choose[2] <= 15)
    {
        room = choose[2];
        Using.doctorRegisteredShow(room);
    }
    else if (choose[2] != 0)cout << "请输入正确操作项" << '\n' << '\n';
}
void inquireChoose()
{
    cout << "请输入操作项：返回上一项（0），查看科室挂号情况（1），查看B超机预约情况（2)" << '\n' << '\n';
    cin >> choose[1];
    cout << '\n';
    if (choose[1] == 1)
    {
        choose[2] = -1;
        while (choose[2] != 0)
        {
            inquireRegistered();
        }
    }
    else if (choose[1] == 2)
    {
        Using.bBookingShow();
        cout << '\n';
    }
    else if (choose[1] != 0)  cout << "请输入正确操作项" << '\n' << '\n';
}
int main()
{
    choose[0] = -1;             //调整初始值进入循环
    while (choose[0]!=0)                        
    {
        cout << "请输入操作项：退出程序（0），科室挂号（1），B超预约（2），查看挂号及预约信息（3）" << '\n' << '\n';
        cin >> choose[0];
        cout << '\n';
        if (choose[0] == 1)
        {
            choose[1] = -1;
            while (choose[1] != 0)
            {
                choose[2] == -1;
                registeredRoom();
            }
        }
        else if (choose[0] == 2)
        {
            choose[1] = -1;
            while (choose[1] != 0)
            {
                choose[2] = -1;
                bookingMachine();
            }
        }
        else if (choose[0] == 3)
        {
            choose[1] = -1;
            while (choose[1]!=0)
            {
                choose[2] = -1;
                inquireChoose();
            }
        }
        else if (choose[0] != 0)  cout << "请输入正确操作项" << '\n';
    }
    cout << "退出程序。" << '\n';system("pause");return 0;
}
