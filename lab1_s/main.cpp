#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <numeric>

const std::string FILEPATH = "xd/file.txt";
//std::ifstream fin("");
std::ofstream fout(FILEPATH);
struct student {
    std::string nume, prenume;
    char id[6];   // id student
    double note[5]; // aici se salveaza notele obtinute in semestrul anterior
};

std::vector<student> generate_random_student(
        const std::array<std::string, 70>& names,
        const std::array<int, 11>& notes,
        const int number_of_randoms
) {
    //std::srand(static_cast<unsigned int>(std::time(nullptr)));
    srand((unsigned int)time(NULL));
    //srand(time(0));
    std::vector<student> S(number_of_randoms);  // Resize the vector


    int indice;
    for(int i = 0 ; i < number_of_randoms ; ++i)
    {
        indice = rand() % names.size();
        S[i].nume = names[i];
        indice = rand() % names.size();
        S[i].prenume = names[i];
    }
    // generare de note
    for(int indice_student = 0 ; indice_student < number_of_randoms ; ++indice_student)
    {
        for (int i = 0; i < 5; ++i) {
            indice = rand() % notes.size();
            S[indice_student].note[i] = notes[indice];
        }
    }
    // generare id
    for(int indice_student = 0 ; indice_student < number_of_randoms ; ++indice_student) {
        for (int i = 0; i < 5; ++i) {
            S[indice_student].id[i] = 'A' + rand() % 26;
        }
        S[indice_student].id[5] = '\n';
    }


    return S;
}
bool has_restanta(const student& s)
{
    double sum = 0.0;
    sum = std::accumulate(s.note, s.note + 5, 0.0);
    double mean = sum / 5.0;
    return mean < 5.0;
}
void remove_students_with_restanta(std::vector<student>& students)
{
    //students.erase(std::remove_if(students.begin(), students.end(), has_restanta), students.end());
    auto iterator = std::remove_if(students.begin(), students.end(), has_restanta);
    students.erase(iterator, students.end());
}

void afiseaza_student_fisier(const student& student)
{
    fout << "Name: " << student.nume << " " << student.prenume << "\n";
    fout <<"ID: " << student.id;
    fout << "Notes: ";
    for (int i = 0; i < 5; ++i)
        fout << student.note[i] << " ";
    fout << "\n\n";
}
void afiseaza_student_consola(const student& student)
{
    std::cout << "Name: " << student.nume << " " << student.prenume << "\n";
    std::cout << "ID: " << student.id << "\n";
    std::cout << "Notes: ";
    for (int i = 0; i < 5; ++i)
        std::cout << student.note[i] << " ";
    std::cout << "\n\n";
}
template<typename T>
std::vector<T> insereaza_la_pozitie(int index, std::vector<T>& vector_t, const T& new_obj)
{
    // Verificăm dacă index este în limitele vectorului
    if (index >= 0 && index <= vector_t.size()) {
        // Adăugăm noul obiect la sfârșitul vectorului
        vector_t.push_back(new_obj);

        // Mutăm elementele după index pentru a face loc noului obiect
        for (int i = vector_t.size() - 1; i > index; --i) {
            vector_t[i] = vector_t[i - 1];
        }

        // Așezăm noul obiect la poziția specificată
        vector_t[index] = new_obj;
    } else {
        std::cerr << "Index invalid!\n";
    }

    return vector_t;
}
int main() {
    /*
     * In main, declarati un vector de student alocat dinamic.
     * Populati-l cu date aleatoare (aveti un vector static de nume si prenume si
     * faceti combinatii aleatorea asigurandu-va ca numele complet nu se repeta,
     * asigurati-va ca id-ul generat este unic, generati note aleatoare
     */
    if (!fout.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1; // Exit with an error code
    }
    const size_t sizeArray = 70;
    std::array<std::string, sizeArray> names = {
            "Alexandru", "Andrei", "Lazar", "Buga", "Adelin", "Razvan", "Dragos", "Theo"
    };
    std::array<int, 11> notes = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};



    std::vector<student> vector_students;
    vector_students = generate_random_student(names , notes , 5);

    //Cerinta 2
    // Scrieti o functie care scrie intr-un fisier studentii cu restanta astfel
    //pe fiecare linie: id, nume, prenume, nr de restante
    for (const auto& student : vector_students) {

        afiseaza_student_consola(student);

        int sum = std::accumulate(student.note, student.note + 5, 0.0);
        std::cout << "Sum of Notes: " << sum << "\n\n";
        if(sum / 5 < 5)
        {
            //bagam in fisier studentul prost
            afiseaza_student_fisier(student);
        }

    }
    //cerinta 3
    //Realizati o functie care sterge din vector toti studentii care
    //au macar o restanta (realocand spatiul ocupat). Afisati vectorul rezultat.
    remove_students_with_restanta(vector_students);
    for(const auto& student : vector_students)
    {
        afiseaza_student_fisier(student);
    }
    //cerinta 4
    //Realizati o functie care adauga in vector un student nou,
    //pe o anumita pozitie (realocand spatiul ocupat). Afisati vectorul rezultat.
    std::vector<student>stundets;
    student new_student = {"Student1", "Prenume1", {'A', 'B', 'C', 'D', 'E', '\0'}, {7, 6, 8, 9, 7}};

    stundets = insereaza_la_pozitie(2 , vector_students , new_student);

    for(const auto& student : vector_students)
    {
        afiseaza_student_fisier(student);
    }


    fout.close();
    return 0;
}
