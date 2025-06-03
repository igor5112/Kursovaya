#include "ScheduleDatabase.h"
#include "Lesson.h"

ScheduleDatabase::ScheduleDatabase() {
    loadInitialData();
}

QList<Subject> ScheduleDatabase::getSubjects() const {
    return m_subjects;
}

QList<Teacher> ScheduleDatabase::getTeachers() const {
    return m_teachers;
}

QList<Group> ScheduleDatabase::getGroups() const {
    return m_groups;
}

QList<Classroom> ScheduleDatabase::getClassrooms() const {
    return m_classrooms;
}


QList<Lesson> ScheduleDatabase::loadLessons() {

    QList<Lesson> loadedLessons;

    return loadedLessons;
}

void ScheduleDatabase::loadInitialData() {
    // Загрузка тестовых данных
    m_subjects.append(Subject(1, "Математика"));
    m_subjects.append(Subject(2, "Физика"));
    m_subjects.append(Subject(3, "Программирование"));
    m_subjects.append(Subject(4, "Базы данных"));
    m_subjects.append(Subject(5, "Компьютерные сети"));
    m_subjects.append(Subject(6, "Операционные системы"));
    m_subjects.append(Subject(7, "Дискретная математика"));
    m_subjects.append(Subject(8, "Алгоритмы и структуры данных"));
    m_subjects.append(Subject(9, "Иностранный язык (Английский)"));
    m_subjects.append(Subject(10, "История"));
    m_subjects.append(Subject(11, "Философия"));
    m_subjects.append(Subject(12, "Экономика"));
    m_subjects.append(Subject(13, "Правоведение"));
    m_subjects.append(Subject(14, "Экология"));
    m_subjects.append(Subject(15, "Менеджмент"));
    m_subjects.append(Subject(16, "Психология"));
    m_subjects.append(Subject(17, "Социология"));
    m_subjects.append(Subject(18, "Основы электроники"));
    m_subjects.append(Subject(19, "Веб-программирование"));
    m_subjects.append(Subject(20, "Моделирование систем"));

    m_teachers.append(Teacher(1, "Иванов", "И.И."));
    m_teachers.append(Teacher(2, "Петров", "П.П."));
    m_teachers.append(Teacher(3, "Сидорова", "А.В."));
    m_teachers.append(Teacher(4, "Козлова", "Е.Н."));
    m_teachers.append(Teacher(5, "Смирнов", "Д.О."));
    m_teachers.append(Teacher(6, "Васильева", "О.С."));
    m_teachers.append(Teacher(7, "Кузнецов", "С.А."));
    m_teachers.append(Teacher(8, "Новикова", "М.Д."));
    m_teachers.append(Teacher(9, "Морозов", "А.Г."));
    m_teachers.append(Teacher(10, "Волкова", "Н.Л."));
    m_teachers.append(Teacher(11, "Павлов", "В.К."));
    m_teachers.append(Teacher(12, "Зайцева", "С.И."));
    m_teachers.append(Teacher(13, "Белов", "А.Ф."));
    m_teachers.append(Teacher(14, "Орлова", "Т.Б."));
    m_teachers.append(Teacher(15, "Григорьев", "Н.М."));
    m_teachers.append(Teacher(16, "Федорова", "И.В."));
    m_teachers.append(Teacher(17, "Михайлов", "К.Р."));
    m_teachers.append(Teacher(18, "Соколова", "Л.А."));
    m_teachers.append(Teacher(19, "Лебедев", "Г.В."));
    m_teachers.append(Teacher(20, "Попова", "Ж.Ю."));


    m_groups.append(Group(1, "ИВТ-11", 25));
    m_groups.append(Group(2, "ИВТ-12", 20));
    m_groups.append(Group(3, "ПИ-21", 30));
    m_groups.append(Group(4, "ПИ-22", 28));
    m_groups.append(Group(5, "АСУ-31", 22));
    m_groups.append(Group(6, "АСУ-32", 24));
    m_groups.append(Group(7, "ЭКО-41", 18));
    m_groups.append(Group(8, "ЮР-11", 35));
    m_groups.append(Group(9, "ИНФ-01", 15));
    m_groups.append(Group(10, "МАТ-11", 27));
    m_groups.append(Group(11, "ФИН-11", 20));
    m_groups.append(Group(12, "АРХ-21", 23));
    m_groups.append(Group(13, "ДИЗ-31", 19));
    m_groups.append(Group(14, "ЛИНГ-11", 26));
    m_groups.append(Group(15, "МЕД-21", 32));
    m_groups.append(Group(16, "ЭЛТ-11", 21));
    m_groups.append(Group(17, "ПР-11", 29));
    m_groups.append(Group(18, "МАР-21", 24));
    m_groups.append(Group(19, "ЭНЕР-31", 26));
    m_groups.append(Group(20, "ГЕО-11", 17));

    m_classrooms.append(Classroom(1, "Аудитория 101", 30));
    m_classrooms.append(Classroom(2, "Аудитория 102", 50));
    m_classrooms.append(Classroom(3, "Лаборатория 205", 20));
    m_classrooms.append(Classroom(4, "Аудитория 201", 40));
    m_classrooms.append(Classroom(5, "Лаборатория 310", 25));
    m_classrooms.append(Classroom(6, "Поточная аудитория 1", 100));
    m_classrooms.append(Classroom(7, "Семинарская 103", 25));
    m_classrooms.append(Classroom(8, "Аудитория 404", 35));
    m_classrooms.append(Classroom(9, "Лаборатория 115", 15));
    m_classrooms.append(Classroom(10, "Аудитория 501", 60));
    m_classrooms.append(Classroom(11, "Лекционный зал А", 150));
    m_classrooms.append(Classroom(12, "Лаборатория 401", 22));
    m_classrooms.append(Classroom(13, "Аудитория 303", 30));
    m_classrooms.append(Classroom(14, "Мультимедиа класс 202", 28));
    m_classrooms.append(Classroom(15, "Спортивный зал", 80));
    m_classrooms.append(Classroom(16, "Аудитория 111", 30));
    m_classrooms.append(Classroom(17, "Лаборатория 222", 20));
    m_classrooms.append(Classroom(18, "Аудитория 333", 45));
    m_classrooms.append(Classroom(19, "Конференц-зал", 70));
    m_classrooms.append(Classroom(20, "Мастерская 1", 10));
}
