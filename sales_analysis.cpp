// #include "sales_analysis.h"

TSalesDepartment::TSalesDepartment(std::string pDepartmentName, int pEmployeeCount) {
    aDepartmentName = pDepartmentName;
    aEmployeeCount = (pEmployeeCount >= 0) ? pEmployeeCount : 0;
}

TSalesDepartment::~TSalesDepartment() {}

void TSalesDepartment::AddEmployeeSales(double pSale) {
    if (pSale >= 0) {
        aSales.push_back(pSale);
    }
}

double TSalesDepartment::CalculateAverageSales() const {
    if (aSales.empty()) return 0.0;

    double total = 0.0;
    for (double sale : aSales) {
        total += sale;
    }
    return total / aSales.size();
}

bool TSalesDepartment::MeetsPerformanceThreshold() const {
    double average = CalculateAverageSales();
    return average >= 50000.0;
}

int TSalesDepartment::FindTopPerformingEmployeeIndex() const {
    if (aSales.empty()) return -1;

    double maxSale = aSales[0];
    int index = 0;

    for (size_t i = 1; i < aSales.size(); ++i) {
        if (aSales[i] > maxSale) {
            maxSale = aSales[i];
            index = i;
        }
    }
    return index;
}

std::string TSalesDepartment::GetDepartmentName() const {
    return aDepartmentName;
}
