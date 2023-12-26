#include <iostream>
using namespace std;
// import maths;
int main()
{
    cout << endl;
    cout << "Concrete Mix Design Calculator" << endl
         << endl;
    cout << "As per annexure of relevant excerpts,formulas and data tables from IS456:2000 & IS 10262:2019" << endl
         << endl;

    // Target Mean Compressive Strength
    double f;
    cout << "Enter Your Required Strength" << endl;
    cin >> f;
    double x, s;
    if (f == 10 || f == 15)
    {
        x = 5;
        s = 3.5;
    }
    else if (f == 20 || f == 25)
    {
        x = 5.5;
        s = 4.0;
    }
    else if (f == 30 || f == 35 || f == 40 || f == 45 || f == 50 || f == 55 || f == 60)
    {
        x = 6.5;
        s = 5.0;
    }
    else if (f >= 65)
    {
        x = 8.0;
        s = 6.0;
    }
    // cout << x << s;
    double f1;
    f1 = max((f + 1.65 * s), (f + x));
    // cout << f1 << endl;

    // Graph w/c ratio calculator
    char ans;
    double wcr, x1, x2, y1, y2;
    cout << "Do you wish to enter tentative strength y/n " << endl;
    cin >> ans;
    if (ans == 'y')
    {
        cout << "Enter observation 1 of water cement ratio and strength respectively considering tentative 28 days compressive strenth test " << endl;
        cin >>
            x1 >> y1;
        cout << "Enter observation 2 of water cement ratio and strength respectively considering tentative 28 days compressive strenth test " << endl;
        cin >>
            x2 >> y2;
    }
    else
    {
        x1 = 0.5;
        x2 = 0.6;
        y1 = 30;
        y2 = 22;
    }
    wcr = ((x2 - x1) / (y2 - y1)) * (f1 - y1) + x1;

    // Air Content
    double ag, ar;
    cout << "Enter the nominal size of the aggregate in mm" << endl;
    cin >> ag;
    if (ag == 10)
    {
        ar = 1.5;
    }
    else if (ag == 20)
    {
        ar = 1.0;
    }
    else if (ag == 40)
    {
        ar = 0.8;
    }

    // Water Content
    double sl, icdc, wc;
    cout << "Enter the Slump Height" << endl;
    cin >> sl;
    icdc = sl - 50;
    if (ag == 10)
    {
        wc = 208 + ((icdc * 208 * 3) / 2500);
    }
    else if (ag == 20)
    {
        wc = 186 + ((icdc * 186 * 3) / 2500);
    }
    else if (ag == 40)
    {
        wc = 165 + ((icdc * 165 * 3) / 2500);
    }

    // cement Content
    double cm;
    cm = wc / wcr;

    // Coarse Aggregate vs Total Aggregate
    int z;
    double r, fr, ro;
    cout << "Enter the zone" << endl;
    cin >> z;
    if (ag == 10)
    {
        if (z == 1)
        {
            r = 0.48;
        }
        else if (z == 2)
        {
            r = 0.50;
        }
        else if (z == 3)
        {
            r = 0.52;
        }
        else if (z == 4)
        {
            r = 0.54;
        }
    }
    else if (ag == 20)
    {
        if (z == 1)
        {
            r = 0.60;
        }
        else if (z == 2)
        {
            r = 0.62;
        }
        else if (z == 3)
        {
            r = 0.64;
        }
        else if (z == 4)
        {
            r = 0.66;
        }
    }
    else if (ag == 40)
    {
        if (z == 1)
        {
            r = 0.69;
        }
        else if (z == 2)
        {
            r = 0.71;
        }
        else if (z == 3)
        {
            r = 0.72;
        }
        else if (z == 4)
        {
            r = 0.73;
        }
    }
    fr = -(0.50 - wcr);
    ro = r + (fr / 5);

    // Total Volume of aggregate
    double vag, spc;
    cout << "Enter th specific gravity ofcement " << endl;
    cin >> spc;
    vag = 1 - (cm / (spc * 1000) + ar + wc / 1000);

    // Volume of coarse aggregate and fine aggregate

    double vca, vfa;
    vca = vag * ro;
    vfa = vag - vca;

    // Mass of fine and coarse aggregate
    double sca, sfa, mfa, mca;
    cout << "Specify the specific gravity of coarse and fine aggregate respectively " << endl;
    cin >> sca >> sfa;
    mca = sca * vca * 1000;
    mfa = sfa * vfa * 1000;

    // Field Aggregate Contents
    // Coarse aggregate
    double waca, mcca, fca;
    cout << "Enter the water absorption and moisture content percentage of coarse aggregate " << endl;
    cin >> waca >> mcca;
    fca = (mca * (1 + mca / 100)) / (1 + waca / 100);
    // Fine aggregate
    double wafa, mcfa, ffa;
    cout << "Enter the water absorption and moisture content percentage of fine aggregate " << endl;
    cin >> wafa >> mcfa;
    ffa = (mfa * (1 + mfa / 100)) / (1 + wafa / 100);

    // Water adjustment
    double efa, eca, wca;
    efa = mfa - ffa;
    eca = mca - fca;
    wca = wc - efa - eca;

    cout << "In 1 metric cube of RCC concrete amount of components are" << endl
         << endl;
    cout << "Water quantity = " << wc << endl;
    cout << "Cement Content = " << cm << endl;
    cout << "Coarse-aggregate content = " << fca << endl;
    cout << "Fine-aggregate content = " << ffa << endl;

    return 0;
}