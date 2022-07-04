cmake_minimum_required(VERSION 3.22)
project(VacOp)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        VacOp
        main.cpp main.h
        Address.cpp Address.h
        Person.cpp Person.h
        Vaccinee.cpp Vaccinee.h
        VaccineeWorker.cpp VaccineeWorker.h
        MedicalWorker.cpp MedicalWorker.h
        VaccinationOperation.cpp VaccinationOperation.h
        Appointment.cpp Appointment.h
        Clinic.cpp Clinic.h
        PrivateClinic.cpp PrivateClinic.h
        Date.cpp Date.h
)
