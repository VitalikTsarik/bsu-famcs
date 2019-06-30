using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Windows.Forms;

namespace _11
{
    [Serializable]
    public class item
    {
        public string Code { get; set; }
        public string Name { get; set; }
        public int Quantity { get; set; }
        public string AgeFrom { get; set; }
        public string AgeTo { get; set; }
        public string UnitPrice { get; set; }
        public int Day { get; set; }
        public int Month { get; set; }
        public int Year { get; set; }
        public string Provider { get; set; }
        public item()
        {
            Day = DateTime.Now.Day;
            Month = DateTime.Now.Month;
            Year = DateTime.Now.Year;
        }
        public item(string Code, string Name, int Quantity, string AgeFrom, string AgeTo,
            string UnitPrice, int Day, int Month, int Year, string Provider)
        {
            this.Code = Code;
            this.Name = Name;
            this.Quantity = Quantity;
            this.AgeFrom = AgeFrom;
            this.AgeTo = AgeTo;
            this.UnitPrice = UnitPrice;
            this.Day = Day;
            this.Month = Month;
            this.Year = Year;
            this.Provider = Provider;
        }

        public override string ToString()
        {
            return Code + " " + Name + " " + Quantity + AgeFrom + "-" + AgeTo + " "
                + UnitPrice + " " + Day + "/" + Month + "/" + Year + " " + Provider;
        }

    };

    public class data
    {
        private ArrayList Toys = new ArrayList();

        public string Current_filename { get; set; }
        public int CurrentItemIndex { get; set; }
        public int lastIndex => Toys.Count - 1;
        public bool SavedToFile { get; set; }

        public data()
        {
            CurrentItemIndex = -1;
            SavedToFile = false;
        }

        public data(string filename)
        {
            ReadData(filename);
            SavedToFile = true;
        }

        public void Add(item toy)
        {
            Toys.Add(toy);
            CurrentItemIndex = lastIndex;
        }
        public void Delete(int index)
        {
            Toys.RemoveAt(index);
        }
        public void Clear()
        {
            Toys.Clear();
            CurrentItemIndex = -1;
            Current_filename = null;
            SavedToFile = false;
        }

        public item this[int index]
        {
            get
            {
                return (item)Toys[index];
            }
        }


        public void WriteData(string filename)
        {
            try
            {
                using (FileStream file = new FileStream(filename, FileMode.Create))
                {
                    BinaryFormatter bf = new BinaryFormatter();
                    foreach(item T in Toys)
                        bf.Serialize(file, T);
                }
                SavedToFile = true;
            }
            catch (Exception e)
            {
                Console.WriteLine("Ошибка записи {0}: {1}", filename, e.Message);
            }
        }
        public void ReadData(string filename)
        {
            try
            {
                Toys.Clear();
                using (FileStream file = new FileStream(filename, FileMode.Open))
                {
                    BinaryFormatter bf = new BinaryFormatter();
                    item T = new item();
                    while (true)
                    {
                        T = (item)bf.Deserialize(file);
                        if (T == null)
                            break;
                        Toys.Add(T);
                    }
                }
            }
            catch (Exception e)
            //исключение при чтении из файла
            {
                Console.WriteLine("Ошибка чтения {0}: {1}", filename, e.Message);
            }
            SavedToFile = true;
            CurrentItemIndex = 0;
            
        }
        

    }

    static class Program
        {
            [STAThread]
            static void Main()
            {
                 
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                Application.Run(new Form1());
            }
        }
    }
