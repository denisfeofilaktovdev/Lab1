using System;
using System.Text;
using LabForms1;

namespace Lab1
{
    public class Program
    {
        private static Stack Train;

        static void Main()
        {
            Console.OutputEncoding = Encoding.UTF8;

            Train = new Stack();
            
            PrintMenu();
        }

        /// <summary>
        /// Головне меню
        /// </summary>
        static void PrintMenu()
        {
            Console.WriteLine("Лабораторна робота 1 ООП");

            bool work = true;
            while (work)
            {
                Console.WriteLine("~~~~~~~Головне Меню~~~~~~~");
                Console.WriteLine("1. Додати вагон\n2. Видалити останній\n3. Відобразити головний\n4. Сортувати\n5. Вихід");

                Console.Write(">> ");
                string select = Console.ReadLine();
                
                if (select.Equals("1")) Add();
                else if (select.Equals("2")) Delete();
                else if (select.Equals("3")) PrintStack(Train);
                else if (select.Equals("4")) Sort();
                else if (select.Equals("5")) work = false;
                else continue;
            }
        }

        /// <summary>
        /// Додавання вагона в кінець
        /// </summary>
        static void Add()
        {
            Console.WriteLine("Введіть тип, або натисніть Enter щоб задати тип випадково");
            string type = Console.ReadLine();

            if (type.Equals("Пасажирський") || type.Equals("Вантажний"))
            {
                Train.Add(type);
            }
            else
            {
                Train.Add();
            }

            Console.WriteLine("Ви додали вагон...........................................");
            //PrintStack(Train);
        }

        /// <summary>
        /// Видалення вагона з кінця
        /// </summary>
        static void Delete()
        {
            Train.RemoveLast();
            Console.WriteLine("Ви видали останній вагон..................................");

            //PrintStack(Train);
        }

        /// <summary>
        /// Сортування за типом вагона
        /// </summary>
        static void Sort()
        {
            Stack First = new Stack();
            Stack Second = new Stack();

            Carriage carriage = Train.GetLast();

            while (carriage != null)
            {
                if (carriage.GetTypeValue() == "Пасажирський")
                {
                    First.Add(carriage.GetTypeValue());
                    First.GetLast().SetNumber(carriage.GetNumber());
                }

                else if (carriage.GetTypeValue() == "Вантажний")
                {
                    Second.Add(carriage.GetTypeValue());
                    Second.GetLast().SetNumber(carriage.GetNumber());
                }

                carriage = carriage.Previous;
            }

            Console.WriteLine("\nПерший потяг \"Пасажирський\":\n");
            PrintStack(First);
            Console.WriteLine("\nДругий потяг \"Вантажний\":\n");
            PrintStack(Second);
            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }

        /// <summary>
        /// Виведення елементів стека
        /// </summary>
        /// <param name="stack">Стек для отримання данних</param>
        static void PrintStack(Stack stack)
        {
            if (stack != null)
            {
                Carriage carriage = stack.GetLast();
                while (carriage != null)
                {
                    Console.WriteLine("//" + carriage.GetNumber() + " " + carriage.GetTypeValue() + "//");
                    carriage = carriage.Previous;
                }
            }
        }
    }

    
}
