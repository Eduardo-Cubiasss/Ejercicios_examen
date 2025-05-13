#ifndef SALES_ANALYSIS_H
#define SALES_ANALYSIS_H

#include <string>
#include <vector>

class TSalesDepartment {
private:
    std::string aDepartmentName;
    int aEmployeeCount;
    std::vector<double> aSales;

public:
    TSalesDepartment(std::string pDepartmentName = "", int pEmployeeCount = 0);
    ~TSalesDepartment();

    void AddEmployeeSales(double pSale);
    double CalculateAverageSales() const;
    bool MeetsPerformanceThreshold() const;
    int FindTopPerformingEmployeeIndex() const;

    std::string GetDepartmentName() const;
};

typedef TSalesDepartment SalesDepartment;

#endif
