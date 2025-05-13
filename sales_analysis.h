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
//constructor con valores predeterminados para pDepartmentName (string vacio) y pEmployeeCount (0)
    TSalesDepartment(std::string pDepartmentName = "", int pEmployeeCount = 0);
    ~TSalesDepartment(); 
    //añade ventas
    void AddEmployeeSales(double pSale);
    //calcula el promedio de ventas
    double CalculateAverageSales() const;
    //metodo que compara si el promedio supero cierta cifra (50000)
    bool MeetsPerformanceThreshold() const;
    //devuelve el indice del mejor empleados (venta mas alta)
    int FindTopPerformingEmployeeIndex() const;

    std::string GetDepartmentName() const;
};

typedef TSalesDepartment SalesDepartment;

#endif// :)
