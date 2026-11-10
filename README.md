# Hospital Management System (C++ OOP)

A comprehensive, highly modular, console-based Hospital Management System built entirely using Object-Oriented Programming (OOP) principles in C++. This project simulates real-world hospital operations, managing patients, departments, and internal workflows through a clean, scalable architecture.

## Project Overview
This system is designed to handle the complex data relationships within a hospital environment. It ensures data persistence using text files and strictly follows the Separation of Concerns principle, decoupling the user interface (Screens) from the business logic (Entities).

## Key Features
- Secure Login: Role-based access control for hospital staff.
- Patient Management: Full CRUD operations (Create, Read, Update, Delete) for patients, including medical history and personal info.
- Department Management: Manage hospital departments, assign heads, and handle internal department operations.
- Internal Workflows: Handle daily rounds, patient analyses, and department-specific tasks.
- Data Persistence: Uses text files (e.g., Patients.txt, Departments.txt) to save and load data, ensuring no data is lost between sessions.

## Architecture & Technical Highlights
- Object-Oriented Design: Heavy use of Encapsulation, Inheritance (e.g., clsPerson -> clsPatient), and Polymorphism.
- Modular UI: Dedicated screen classes (clsShowAllPatientInfo, clsUpdateDepartmentInfo) that inherit from a base clsScreen to maintain a consistent look and feel.
- Validation Layer: Utilizes clsInputValidate and clsString for robust data handling and preventing user errors.

## Project Structure (Core Classes)
1. Core Entities:
- clsPerson: The base class for individuals.
- clsPatient: Inherits from clsPerson, handles patient-specific data.
- clsDepartment: Manages department details.
- clsDepartmentLeaderTour: Handles leadership and internal operations.

2. User Interface (Screens):
- clsScreen: The base UI class.
- clsLoginScreen, clsMainScreen.
- Action screens like clsAddNewPatient, clsDeletePatient, clsShowPatientsListSystem.

## How to Run
1. Clone this repository or download it as a ZIP file.
2. Open the Hospital System2.sln file in Visual Studio.
3. Ensure the data text files (Patients.txt, Departments.txt) are in the same directory as the .sln file.
4. Press F5 or Ctrl + F5 to build and run the application.

## License
This project is open-source and available under the MIT License.
