#include <iostream>
#include <iomanip>
#include "sales_analysis.h"

/* Compilar con:
   g++ -std=c++11 sales_analysis.cpp main.cpp -o sales_analysis
   ./sales_analysis
*/

int main() {
    try {
        // Crear departamentos de ventas
        SalesDepartment departamento1("Ventas Tecnología", 15);
        SalesDepartment departamento2("Ventas Automotriz", 20);
        SalesDepartment departamento3("Ventas Farmacéutica", 12);

        // Agregar ventas por empleado en cada departamento
        departamento1.AddEmployeeSales(65000.50);
        departamento1.AddEmployeeSales(55000.75);   
        departamento1.AddEmployeeSales(48000.25);

        departamento2.AddEmployeeSales(72000.90);
        departamento2.AddEmployeeSales(60000.60);
        departamento2.AddEmployeeSales(55000.30);

        departamento3.AddEmployeeSales(45000.20);
        departamento3.AddEmployeeSales(52000.80);
        departamento3.AddEmployeeSales(38000.45);

        // Arreglo de departamentos para procesamiento
        SalesDepartment departamentos[] = {departamento1, departamento2, departamento3};

        // Análisis de resultados
        std::cout << "Análisis de Rendimiento de Ventas\n";
        std::cout << "==================================\n";

        for (const auto& departamento : departamentos) {
            std::cout << "Departamento: " << departamento.GetDepartmentName() << std::endl;
            
            // Calcular y mostrar promedio de ventas redondeado a 2 decimales
            double avgSales = departamento.CalculateAverageSales();
            std::cout << "Promedio de Ventas: $" 
                      << std::fixed << std::setprecision(2) 
                      << avgSales << std::endl;

            // Verificar umbral de rendimiento (si el promedio de ventas supera lo esperado )
            std::cout << "Cumple Umbral de Rendimiento: "
            //opera con ternarios si la funcion devulve true se muestra si en caso de que devuelva false imprime No 
                      << (departamento.MeetsPerformanceThreshold() ? "Sí" : "No") << std::endl;

            // Encontrar mejor empleado
            int topPerformerIndex = departamento.FindTopPerformingEmployeeIndex();
            std::cout << "Mejor Empleado (índice): " << topPerformerIndex << std::endl;
            std::cout << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
