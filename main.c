/*����� ��������� - �������� �� ������������ ������������ ���������� ����� ��������� � ��������� (k), �� ������ ����� ��� ����������� ������� ����� �� ������ ������������� �������.
��������� ��� k ����� ���������� �������, �� ����������� ��������� ����� - ��� ����������� �������� ��������, ������������� ������� �������� �������� ���������� ��� � 5 �������������.
����� ����������� ����������� ����� (�������).
������� � ���� ��������, ��������� ������ �������� - ���� ����� ������ ���� ���� ��� ���� ������� A ������ � A �����, ��������������.
��� �������� ��������� (����� ����� ���) ���������� ������������� ���� �����, �������� ������� � ��������� ��������.
��� �� ����������� �������������� ������ �����. ��� ���������� ����� ����� �����, ���������� �������� ���������� ������������� � ����������� ������� � ��������� ���������.
��� ����������� �������� ���������� ������� �� ������� ��������.
����� ����������� ������ ������� - ��� ������ ����� ������ ���������� � ���� C �/��� ���� B �� ���� ������� �� ����������� �����.
��� �������� ��������� ���������� ������������� �����, �������� ������� � �������� ������� ��������, ����� �������� ������� ��������.
��� ����������� �������� ���������� ������� � �������� ��������.
������ ������� - ����� ���������������� ����� �������� ������������ ��� ��������� ������� ������.
��� ����������� �������� ���������� ������� � ��������� �������, ��������� ���������� WINAPI.
����� ���������� ��������� ���������� ����������� ���� (����������), ���������� ������������ ����, ���������� � ����� ������� -> bin -> Debug*/



#include <stdio.h> // ����������� ���������� ��� ��������� �������� �� C
#include <time.h> // ���������� ��� ������������� ���������� ��������������� �����
#include <windows.h> // ���������� WINAPI ��� �������� ������������ ����������, ��������� ��������
#include <locale.h> // ���������� ��� ������������� �������� �����

                        /* ���������� ��������� �����. ��������� ��������� ���������� ������ ������ ��� ������� ����� � ������ �������� �������� */
void zapoln(int k, int mass[], int props, int kol, int takt)
{
    for(int z = 0; z < k - 6; z++)
    {
        mass[z] = rand() %(kol + 1); //������� ����������� �������� �� rand, ����� % ������������ �������� ������ (���������) = x + min
    }
    if(takt == 3 || takt == -1)
    {
        for(int z = k - 6; z < k; z++)
        {
            if(props == 1 && z == k - 6)
            {
                mass[z] = rand() %(kol - 5);
            }
            if(props == 1 && z > k - 6)
            {
                mass[z] = rand() %(kol - mass[z - 1] - k + z + 2);
                if(mass[z] == 0)
                {
                    mass[z] = 1;
                }
                mass[z] += mass[z - 1];
            }
            if(props == 0 && z == k - 6)
            {
                mass[z] = rand() %(kol - 5);
                mass[z] += 5;
            }
            if(props == 0 && z > k - 6)
            {
                mass[z] = rand() %(mass[z - 1] - k + z + 2);
                if(mass[z] == 0)
                {
                    mass[z] = 1;
                }
                mass[z] = mass[z - 1] - mass[z];
            }
        }
    takt = 0;
    }
}
int opr(int mass[], int k)
{
    int opred;
    opred = mass[0];
    for(int r = 1; r < k; r++)
    {
        if(mass[r] > opred)
        {
            opred = mass[r];
        }
    }
    return (opred);
}
int opr1(int mass[], int k)
{
    for(int r = 1; r < k; r++)
    {
        if(abs(mass[r] - mass[r - 1]) > 13)
        {
            return(1);
            break;
        }
        else
        {
            return(2);
        }
    }
}
                /* ���������� ��������� �����. ��������� ��������� ���������� ������ ������ ��� ������� ����� � ������ �������� ��������, ����� */

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Rus");
    float znach_mid = 0, znach_top, znach_bot, razm_mid = 0, razm_top, znach_top2, znach_bot2, znach_top1, znach_bot1;
    unsigned int kol, kolt = 0, flag = 0, flag1 = 0;
    int mill = rand() %5, k = 0, *mass = malloc(k *sizeof(int)), maxmin = 0, milld = rand() %10, ypravl = 1, props, takt = -1, maxo = 0;

    /* ���� �������� ������������ */
    while(kol < 14 || kol > 320)
    {
    printf("������� ������������ ��������� �������� ������� 13 � ������� 321\n");
    scanf("%u", &kol);
    }
    while(kolt < 18)
    {
        printf("������� ����������� ���������� �����, �� ������� 18\n");
        scanf("%u", &kolt);
    }
    k = kolt + mill + milld;
    milld = (milld + kolt - 18) / (1 + rand() %4);
    float ver = 320 / kol, gor = 600 / (k + 10);
    /* ���� �������� ������������, ����� */

    /* �������� ��������� ��� ����� ������� � WinAPI */
    float masxt[k], masyt[k], masxb[k], masyb[k], masxt1[k], masyt1[k], masxb1[k], masyb1[k];
    /* �������� ��������� ��� ����� ������� � WinAPI, ����� */

    printf("���������� �����: %u \n", k);

    /* ���������� ������� ��������� ���������� ���������� � ����������� �������� �������� */
    props = rand() %2;
    zapoln(k, mass, props, kol, takt);
    printf("\n");
    /* ���������� ������� ��������� ���������� ���������� � ����������� �������� ��������, ����� */

    clock_t start = clock();
    while(1)
    {
        props = rand() %2;
        while(opr < 13 && opr1 == 2) // ���������� ����� � WINAPI
        {
            takt = -1;
            zapoln(k, mass, props, kol, takt);
            opr(mass, k);
            opr1(mass, k);
        }

    /* ������� ������� */
        for(int r = 0; r < k; r++)
        {
            znach_mid += mass[r];
            if(r > 0)
            {
                razm_mid += abs(mass[r] - mass[r-1]);
            }
        }
        if(ypravl == 1)
        {
            razm_mid = razm_mid / (k - 1);
            razm_top = 3.267 * razm_mid;
            znach_mid = znach_mid / k;
            znach_top = znach_mid + 2.66 * razm_mid;
            znach_bot = znach_mid - 2.66 * razm_mid;
            znach_bot2 = (znach_mid - znach_bot) / 3 * 2 + znach_bot;
            znach_top2 = (znach_top - znach_mid) / 3 + znach_mid;
            znach_bot1 = (znach_mid - znach_bot) / 3 + znach_bot;
            znach_top1 = (znach_top - znach_mid) / 3 * 2 + znach_mid;
        }

    /* ������� �������, ����� */

    /* �������� �� ������������� ��������� ����� ����� */
        for(int r = 1; r < 3 + mill; r++)
        {
            if(mass[r] > mass[r - 1])
            {
                flag += 1;
            }
            if(mass[r] < mass[r - 1])
            {
                flag1 += 1;
            }
        }
        if(flag == 2 + mill || flag1 == 2 + mill)
        {
            zapoln(k, mass, props, kol, takt);
            ypravl = 1;
            takt += 1;
        }
        else
        {
            flag = 0;
            flag1 = 0;
        }
        for(int r = mill + 4 + milld; r < mill + 3 + milld + 8; r++)
        {
            if(mass[r] > mass[r - 1])
            {
                flag += 1;
            }
            if(mass[r] < mass[r - 1])
            {
                flag1 += 1;
            }
        }
        if(flag == 8 || flag1 == 8)
        {
            zapoln(k, mass, props, kol, takt);
            ypravl = 1;
            takt += 1;
        }
        else
        {
            ypravl = 0;
            maxmin = 0;
            flag = 0;
            flag1 = 0;
        }
    /* �������� �� ������������� ��������� ����� �����, ����� */

    /* ������� ��������� */
        for(int r = 0; r < k; r++)
        {

    /* �������� ������� �������� */
            if ((r < 3 + mill && mass[r] > znach_top) || (r < mill + 3 && mass[r] < znach_bot))
            {
                maxmin += 1;
            }
            if (maxmin != 1 && r == mill + 3)
            {
                zapoln(k, mass, props, kol, takt);
                ypravl = 1;
                takt += 1;
            }
    /* �������� ������� ��������, ����� */

    /* �������� ������� �������� */
            if(ypravl == 0 && r >= mill + 3 + milld && r <= mill + 3 + milld + 8 )
            {
                if((mass[r] < znach_mid && mass[r] > znach_bot1 && mass[r - 1] < znach_mid && mass[r - 1] > znach_bot1) || (mass[r] > znach_mid && mass[r] < znach_top1 && mass[r - 1] > znach_mid && mass[r - 1] < znach_top1))
                {

                }
                else
                {
                    zapoln(k, mass, props, kol, takt);
                    ypravl = 1;
                    takt += 1;
                }
            }
    /* �������� ������� ��������, ����� */

    /* �������� �������� �������� */
            if(ypravl == 0 && r >= k - 7)
            {
                if(mass[r] < znach_bot)
                {
                    flag += 1;
                }
                if(mass[r] > znach_top)
                {
                    flag1 += 1;
                }
                if((flag == 1 && r == k - 1) || (flag1 == 1 && r == k - 1))
                {
                    takt = -1;
                    zapoln(k, mass, props, kol, takt);
                    ypravl = 1;
                    flag = 0;
                    flag1 = 0;
                }
            }
    /* �������� �������� ��������, ����� */

            if(ypravl == 1) // ��� �� ���������� ���� ��������� ������������ ������� � ������������� � �������� ������� � ������� ��������
            {
                r = k;
            }
        }

    /* ������� ���������, �����*/

    /* ����� �������� ���������, ���������� �������� �� ���������*/
        if(ypravl == 0)
        {
            printf("���� �����: ");
            for(int r = 0; r < k; r++)
            {
                printf("%u ", mass[r]);
                masxt[r] = 85 + r * gor + 4;
                masyt[r] = 600 - ver * mass[r] - 4;
                masxb[r] = 85 + r * gor - 4;
                masyb[r] = 600 - ver * mass[r] + 4;
                if(r > 0)
                {
                    if(abs(mass[r] - mass[r - 1]) > maxo)
                    {
                        maxo = abs(mass[r] - mass[r - 1]);
                    }
                    masxt1[r] = 200 + gor * (k + 9) + r * gor + 4;
                    masyt1[r] = 600 - ver * abs(mass[r] - mass[r - 1]) - 4;
                    masxb1[r] = 200 + gor * (k + 9) + r * gor - 4;
                    masyb1[r] = 600 - ver * abs(mass[r] - mass[r - 1]) + 4;
                }
            }
            printf("  \n");
            printf("� �������   %f\n", znach_top);
            printf("� �������   %f\n", znach_top1);
            printf("� �������   %f\n", znach_top2);
            printf("�������   %f\n", znach_mid);
            printf("� ������   %f\n", znach_bot2);
            printf("� ������   %f\n", znach_bot1);
            printf("� ������   %f\n", znach_bot);
            clock_t end = clock();
            float second = (float)(end - start) / 1000;
            printf("����� �� ������ �������������� ����������: %f", second);
            break;
        }
    /* ����� �������� ���������, ���������� �������� �� ���������, �����*/

    /* ������ � WINAPI */
    }
    char tex[4], tex2[29];
    WNDCLASSA wcl;
    memset(&wcl, 0, sizeof(WNDCLASSA));
    wcl.lpszClassName = "my Window";
    wcl.lpfnWndProc = DefWindowProcA;
    RegisterClassA(&wcl);
    HWND hwnd;
    hwnd = CreateWindow("my Window", "Window Name", WS_OVERLAPPEDWINDOW, 10, 10, 1920, 1080, NULL, NULL, NULL, NULL);
    HDC dc = GetDC(hwnd);
    ShowWindow(hwnd, SW_SHOWNORMAL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        DispatchMessage(&msg);
        HPEN hpen2, hpen3;
        HBRUSH hbrush2, hbrush3;
        hpen2 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        hpen3 = SelectObject(dc, hpen2);
        hbrush2 = CreateSolidBrush(RGB(0, 0, 0));
        hbrush3 = SelectObject(dc, hbrush2);
    /* ������� ������ ��������� �� ������ */
        Rectangle(dc, 85 + gor * 0, 600 - ver * znach_mid + 1 , 55 + gor * (k + 10), 600 - ver * znach_mid - 1 );
        Rectangle(dc, 85 + gor * 0, 600 - ver * znach_bot + 1, 55 + gor * (k + 10), 600 - ver * znach_bot  - 1);
        Rectangle(dc, 85 + gor * 0, 600 - ver * znach_top + 1, 55 + gor *(k + 10), 600 - ver * znach_top  - 1);
        Rectangle(dc, 85 + gor * 0, 600 - ver * znach_top2 + 1, 55 + gor * (k + 10), 600 - ver * znach_top2  - 1);
        Rectangle(dc, 85 + gor * 0, 600 - ver * znach_bot2 + 1, 55 + gor * (k + 10), 600 - ver * znach_bot2  - 1);
        Rectangle(dc, 85 + gor * 0, 600 - ver * znach_mid + 1, 55 + gor * (k + 10), 600 - ver * znach_mid  - 1);
        Rectangle(dc, 85 + gor * 0, 600 - ver * znach_bot1 + 1, 55 + gor * (k + 10), 600 - ver * znach_bot1  - 1);
        Rectangle(dc, 85 + gor * 0, 600 - ver * znach_top1 + 1, 55 + gor * (k + 10), 600 - ver * znach_top1  - 1);

        Rectangle(dc, 200 + gor * (k + 10), 600 - ver * razm_mid + 1 , 200 + gor * (k * 2 + 20), 600 - ver * razm_mid - 1 );
        Rectangle(dc, 200 + gor * (k + 10), 600 - ver * 0 + 1, 200 + gor * (k * 2 + 20), 600 - ver * 0  - 1);
        Rectangle(dc, 200 + gor * (k + 10), 600 - ver * razm_top + 1, 200 + gor * (k * 2 + 20), 600 - ver * razm_top  - 1);

    /* ������� ������ ��������� �� ������, ����� */

    /* ������� ������������ ������ �� ������ � ������� */
        MoveToEx(dc, 85 , 600, NULL);
        LineTo(dc, 85 + gor * (k - 1) + 70 + 50, 600);
        LineTo(dc, 85 + gor * (k - 1) + 55 + 50, 605);
        MoveToEx(dc, 85 + gor * (k - 1) + 70 + 50, 600, NULL);
        LineTo(dc, 85 + gor * (k - 1) + 55 + 50, 595);

        MoveToEx(dc, 200 + gor * (k + 10) , 600, NULL);
        LineTo(dc, 25 + 200 + gor * ((k - 1) * 2 + 20) + 60, 600);
        LineTo(dc, 25 + 200 + gor * ((k - 1) * 2 + 20) + 60 - 15, 605);
        MoveToEx(dc, 25 + 200 + gor * ((k - 1) * 2 + 20) + 60, 600, NULL);
        LineTo(dc, 25 + 200 + gor * ((k - 1) * 2 + 20) + 60 - 15, 595);

        if(znach_bot < 0)
        {
            MoveToEx(dc, 85 , 600 - ver * znach_bot + 20, NULL);
        }
        else
        {
            MoveToEx(dc, 85 , 600, NULL);
        }
        if(znach_top > kol)
        {
            LineTo(dc, 85,  600 - ver * znach_top - 40);
            LineTo(dc, 80, 600 - ver * znach_top - 25);
            MoveToEx(dc, 85,  600 - ver * znach_top - 40, NULL);
            LineTo(dc, 90, 600 - ver * znach_top - 25);
        }
        if(znach_top < kol)
        {
            LineTo(dc, 85,  600 - ver * kol - 40);
            LineTo(dc, 80, 600 - ver * kol - 25);
            MoveToEx(dc, 85,  600 - ver * kol - 40, NULL);
            LineTo(dc, 90, 600 - ver * kol - 25);
        }
        if(znach_bot < 0)
        {
            MoveToEx(dc, 200 + gor * (k + 10) , 600 - ver * znach_bot + 20, NULL);
        }
        else
        {
            MoveToEx(dc, 200 + gor * (k + 10) , 600, NULL);
        }
        if(znach_top > kol)
        {
            LineTo(dc, 200 + gor * (k + 10),  600 - ver * znach_top - 40);
            LineTo(dc, 200 + gor * (k + 10) - 5, 600 - ver * znach_top - 25);
            MoveToEx(dc, 200 + gor * (k + 10),  600 - ver * znach_top - 40, NULL);
            LineTo(dc, 200 + gor * (k + 10) + 5, 600 - ver * znach_top - 25);
        }
        if(znach_top < kol)
        {
            LineTo(dc, 200 + gor * (k + 10),  600 - ver * kol - 40);
            LineTo(dc, 200 + gor * (k + 10) - 5, 600 - ver * kol - 25);
            MoveToEx(dc, 200 + gor * (k + 10),  600 - ver * kol - 40, NULL);
            LineTo(dc, 200 + gor * (k + 10) + 5, 600 - ver * kol - 25);
        }
        for(int r = 0; r < k; r++)
        {
            MoveToEx(dc, 85 + gor * r, 605, NULL);
            LineTo(dc, 85 + gor * r, 595);
        }
        for(int r = 0; r < k; r+=5)
        {
            sprintf(tex2, "%u", r);
            TextOutA(dc, 85 + gor * r, 610, tex2, strlen(tex2) + 1);
        }

        for(int r = 0; r < k - 1; r++)
        {
            MoveToEx(dc, 200 + gor * (k + 10) + gor * r, 605, NULL);
            LineTo(dc, 200 + gor * (k + 10) + gor * r, 595);
        }
        for(int r = 0; r < k - 1; r+=5)
        {
            sprintf(tex2, "%u", r);
            TextOutA(dc, 200 + gor * (k + 10) + gor * r, 610, tex2, strlen(tex2) + 1);
        }
        if(kol > znach_top)
        {
            for(float r = kol / 10; r <= kol + kol / 10; r += kol / 10)
            {
                MoveToEx(dc, 80, 600 - r * ver, NULL);
                LineTo(dc, 90, 600 - r * ver);
                sprintf(tex2, "%.1f", r);
                TextOutA(dc, 40, 600 - r * ver, tex2, strlen(tex2) + 1);
            }
        }
        if(kol <= znach_top)
        {
            for(float r = znach_top / 10; r <= znach_top + znach_top / 10; r += znach_top / 10)
            {
                MoveToEx(dc, 80, 600 - r * ver, NULL);
                LineTo(dc, 90, 600 - r * ver);
                sprintf(tex2, "%.1f", r);
                TextOutA(dc, 40, 600 - r * ver, tex2, strlen(tex2) + 1);
            }
        }
        if(maxo > razm_top)
        {
            for(float r = maxo / 10; r <= maxo + maxo / 10; r += maxo / 10)
            {
                MoveToEx(dc, 195 + gor * (k + 10), 600 - r * ver, NULL);
                LineTo(dc, 205 + gor * (k + 10), 600 - r * ver);
                sprintf(tex2, "%.3f", r);
                TextOutA(dc, 140 + gor * (k + 10), 600 - r * ver, tex2, strlen(tex2) + 1);
            }
        }
        if(maxo <= razm_top)
        {
            for(float r = razm_top / 10; r <= razm_top + razm_top / 10; r += razm_top / 10)
            {
                MoveToEx(dc, 195 + gor * (k + 10), 600 - r * ver, NULL);
                LineTo(dc, 205 + gor * (k + 10), 600 - r * ver);
                sprintf(tex2, "%.3f", r);
                TextOutA(dc, 140 + gor * (k + 10), 600 - r * ver, tex2, strlen(tex2) + 1);
            }
        }
        DeleteObject(hbrush2);
        DeleteObject(hpen2);
        DeleteObject(hbrush3);
        DeleteObject(hpen3);
    /* ������� ������������ ������ �� ������ � �������, ����� */

    /* ������� ����� �� ������ � ������ ������, ����������� �� */
        HPEN hpen, hpen1;
        HBRUSH hbrush, hbrush1;
        hpen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
        hpen1 = SelectObject(dc, hpen);
        hbrush = CreateSolidBrush(RGB(0, 255, 0));
        hbrush1 = SelectObject(dc, hbrush);
        MoveToEx(dc, masxt[0] - 4,  masyt[0] + 4, NULL);
        Ellipse(dc, masxt[0], masyt[0], masxb[0], masyb[0]);
        for(int r = 1; r < k; r++)
        {
            LineTo(dc, masxb[r] + 4, masyb[r] - 4);
            Ellipse(dc, masxt[r], masyt[r], masxb[r], masyb[r]);
        }

        MoveToEx(dc, masxt1[1] - 4,  masyt1[1] + 4, NULL);
        Ellipse(dc, masxt1[1], masyt1[1], masxb1[1], masyb1[1]);
        for(int r = 1; r < k; r++)
        {
            LineTo(dc, masxb1[r] + 4, masyb1[r] - 4);
            Ellipse(dc, masxt1[r], masyt1[r], masxb1[r], masyb1[r]);
        }
        DeleteObject(hbrush);
        DeleteObject(hpen);
        DeleteObject(hbrush1);
        DeleteObject(hpen1);
    /* ������� ����� �� ������, ����� */

    /* ������� �������� �� ������ */
        sprintf(tex, "�+");
        TextOutA(dc, 10, 590 - ver * znach_top1 - ver * (znach_top - znach_top1) / 2, tex, strlen(tex) + 1);
        sprintf(tex, "�+");
        TextOutA(dc, 10, 590 - ver * znach_top2 - ver * (znach_top1 - znach_top2) / 2, tex, strlen(tex) + 1);
        sprintf(tex, "�+");
        TextOutA(dc, 10, 590 - ver * znach_mid - ver * (znach_top2 - znach_mid) / 2, tex, strlen(tex) + 1);
        sprintf(tex, "X");
        TextOutA(dc, 120 + gor * k, 590 - ver * znach_mid - 10, tex, strlen(tex) + 1);
        sprintf(tex, "�");
        TextOutA(dc, 120 + gor * k, 590 - ver * znach_mid - 25, tex, strlen(tex) + 1);
        sprintf(tex, "�-");
        TextOutA(dc, 10, 590 - ver * znach_mid + ver * (znach_mid - znach_bot2) / 2, tex, strlen(tex) + 1);
        sprintf(tex, "B-");
        TextOutA(dc, 10, 590 - ver * znach_bot2 - ver * (znach_bot2 - znach_mid) / 2, tex, strlen(tex) + 1);
        sprintf(tex, "�-");
        TextOutA(dc, 10, 590 - ver * znach_bot1 - ver * (znach_bot1 - znach_bot2) / 2, tex, strlen(tex) + 1);
        sprintf(tex, "Ucl");
        TextOutA(dc, 120 + gor * k, 590 - ver * znach_top - 10, tex, strlen(tex) + 1);
        sprintf(tex, "Lcl");
        TextOutA(dc, 120 + gor * k, 590 - ver * znach_bot - 10, tex, strlen(tex) + 1);

        sprintf(tex, "Ucl");
        TextOutA(dc, 200 + gor * (k * 2 + 20) - 45, 600 - ver * razm_top - 1 - 20, tex, strlen(tex) + 1);
        sprintf(tex, "R");
        TextOutA(dc,  200 + gor * (k * 2 + 20) - 45, 600 - ver * razm_mid  - 1 - 20, tex, strlen(tex) + 1);
        sprintf(tex, "�");
        TextOutA(dc,  200 + gor * (k * 2 + 20) - 45, 600 - ver * razm_mid  - 1 - 20 - 15, tex, strlen(tex) + 1);
        sprintf(tex, "Lcl");
        TextOutA(dc,  200 + gor * (k * 2 + 20) - 45, 600 - 20, tex, strlen(tex) + 1);
    /* ������� �������� �� ������, ����� */

    /* ������� ������� �� ������ (�������� ���� � �������������� ��������) */
        sprintf(tex2, "���������");
        TextOutA(dc, 100 + gor * k + 80, 615, tex2, strlen(tex2) + 1);
        sprintf(tex2, "���������");
        TextOutA(dc, 200 + gor * (k * 2 + 20) + 45, 615, tex2, strlen(tex2) + 1);
        sprintf(tex2, "�������������� ��������");
        if(znach_top > kol)
        {
            TextOutA(dc, 45, 600 - ver * znach_top - 60, tex2, strlen(tex2) + 1);
        }
        else
        {
            TextOutA(dc, 45, 600 - ver * kol - 60, tex2, strlen(tex2) + 1);
        }
        sprintf(tex2, "���������� �������");
        if(znach_top > kol)
        {
            TextOutA(dc, 200 + gor * (k + 10) - 40, 600 - ver * znach_top - 60, tex2, strlen(tex2) + 1);
        }
        else
        {
            TextOutA(dc, 200 + gor * (k + 10) - 40, 600 - ver * kol - 60, tex2, strlen(tex2) + 1);
        }
        sprintf(tex2, "����� �������������� ��������");
        TextOutA(dc, 250, 100, tex2, strlen(tex2) + 1);
        sprintf(tex2, "����� ���������� ��������");
        TextOutA(dc, 1000, 100, tex2, strlen(tex2) + 1);
    /* ������� ������� �� ������ (�������� ���� � �������������� ��������), ����� */

    /* �������� �������� �� ������� */
        HPEN hpen4, hpen5;
        hpen4 = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
        hpen5 = SelectObject(dc, hpen4);
        MoveToEx(dc, 85,  700, NULL);
        LineTo(dc, 85, 600);
        MoveToEx(dc, 85,  700, NULL);
        LineTo(dc, 85 + gor * (3 + mill + milld - 0.5),  700);
        LineTo(dc, 85 + gor * (3 + mill + milld + 8 + 0.5),  700);
        LineTo(dc, 85 + gor * (k - 6 - 0.5),  700);
        LineTo(dc, 85 + gor * (3 + mill + 0.5),  700);
        LineTo(dc, 85 + gor * k,  700);
        LineTo(dc, 85 + gor * k,  600 - ver * znach_top);
        MoveToEx(dc, 85 + gor * (3 + mill + milld - 0.5),  700, NULL);
        LineTo(dc, 85 + gor * (3 + mill + milld - 0.5), 600 - ver * znach_top);
        MoveToEx(dc, 85 + gor * (3 + mill + milld + 8 + 0.5),  700, NULL);
        LineTo(dc, 85 + gor * (3 + mill + milld + 8 + 0.5), 600 - ver * znach_top);
        MoveToEx(dc, 85 + gor * (k - 6 - 0.5),  700, NULL);
        LineTo(dc, 85 + gor * (k - 6 - 0.5), 600 - ver * znach_top);
        MoveToEx(dc, 85 + gor * (3 + mill + 0.5),  700, NULL);
        LineTo(dc, 85 + gor * (3 + mill + 0.5), 600 - ver * znach_top);
        sprintf(tex, "1");
        TextOutA(dc, 100,  680, tex, strlen(tex) + 1);
        sprintf(tex, "2");
        TextOutA(dc, 100 + gor * (3 + mill + milld - 0.5), 680, tex, strlen(tex) + 1);
        sprintf(tex, "3");
        TextOutA(dc, 100 + gor * (k - 6 - 0.5), 680, tex, strlen(tex) + 1);
        DeleteObject(hpen4);
        DeleteObject(hpen5);
    /* �������� �������� �� �������, ����� */
    }
    /* ������ � WINAPI, ����� */
    free(&masxt[k]);
    free(&masyt[k]);
    free(&masxb[k]);
    free(&masyb[k]);
    free(&masxt1[k]);
    free(&masyt1[k]);
    free(&masyb1[k]);
    free(&masxb1[k]);
    system("pause");
}
