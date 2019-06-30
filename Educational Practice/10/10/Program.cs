using System;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace ExamGraph2
{
    static class Program
    {
        private const int GraphX = 700;
        private const int GraphY = 675;
        [STAThread] //<-Required for WinForms
        static void Main(string[] args)
        {
           
            try
                {
                    Application.EnableVisualStyles();
                    Application.Run(
                       new AppWindow(strAppTitle,
                           GraphX, GraphY));
                }
                catch (Exception e)
                {
                    MessageBox.Show(
                         "Error: " + e.Message,
                         strAppTitle,
                         MessageBoxButtons.OK,
                         MessageBoxIcon.Error
                    );
                }
        }

        static readonly string strAppTitle =
           "Graph";
        
    }
    // class of application Window:
    class AppWindow : Form
    {
        Size NcSize;
        Random Rand;
        Bitmap Bmp;
        Graphics Buffer;

        float X_value;
        List<int> data = new List<int>();

        public AppWindow(string title,
                         int width, int height)
        {
            Rand = new Random();
            // Buffer:
            Bmp = new Bitmap(width, height);
            Buffer = Graphics.FromImage(Bmp);
            Buffer.FillRectangle(
                new SolidBrush(Color.Black),
                0, 0, Bmp.Width, Bmp.Height);
            // set application title:
            Text = title;
            // set required client area and size
            NcSize = new Size(
                Width - ClientSize.Width,
                Height - ClientSize.Height);
            ClientSize = new Size(width, height);
            MinimumSize = new Size(
                NcSize.Width + width,
                NcSize.Height + height);
            MaximumSize = MinimumSize;
            BackColor = Color.White;
            //InitDraw();
            // setup event handler:
            Paint += AppWindow_Paint;
            // Center window:
            CenterToScreen();
        }

        private void AppWindow_Paint(object sender, PaintEventArgs pe)
        {
            Graphics g = pe.Graphics;
            Draw(g);
            
        }

        private void Draw(Graphics g)
        {
            string str;
            try
            {
                using (StreamReader sr = new StreamReader("Data.txt"))
                {
                    str = sr.ReadLine();
                    X_value = float.Parse(str);
                    while (true)
                    {
                        str = sr.ReadLine();
                        if (str == null)
                            break;
                        data.Add(int.Parse(str));                        
                    }
                }
            }
            catch (Exception e) // исключение при чтении
            {
                Console.WriteLine(
                      "Ошибка при чтении файла: {1}", e.Message);
            }

            Buffer.Flush();
            
            Pen bold_pen = new Pen(Brushes.Black, 3);
            Pen medium_pen = new Pen(Brushes.Black, 2);
            Pen thin_pen = new Pen(Brushes.Gray, 1);
            SolidBrush brush = new SolidBrush(Color.Black);

            // Масштаб
            int scale = ClientSize.Height / 15;
            float max_Y = data[data.Count - 1];
            int Y_scale = (int)Math.Ceiling(max_Y / 12);

            // начало координат
            str = data[data.Count - 1].ToString();
            Point OXY = new Point((str.Length+2)* (int)Font.SizeInPoints, ClientSize.Height - scale);


            // Координатная сетка и подписи
            for (int i = 1; i * scale <= ClientSize.Height - 2*scale; i++)
            {
                str = (i * Y_scale).ToString();
                g.DrawLine(thin_pen, new Point(OXY.X, OXY.Y - i * scale), new Point(Width, OXY.Y - i * scale));
                g.DrawString(str, Font, brush, new Point(OXY.X - (str.Length + 1) * (int)Font.SizeInPoints, OXY.Y - scale/5  - i * scale));
            }
            for (int i = 1; i * scale < ClientSize.Width; i++)
            {
                g.DrawLine(thin_pen, new Point(OXY.X + i * scale, scale), new Point(OXY.X + i * scale, OXY.Y));
                g.DrawString(i.ToString(), Font, brush, new Point(OXY.X - scale/5 + i * scale, OXY.Y + scale/4));
            }
            g.DrawString("0", Font, brush, OXY.X - scale/4, OXY.Y + scale / 4);
            g.DrawString("График зависимости числа итераций от точности вычисления суммы бесконечного ряда при x = " + X_value.ToString(),
               Font, brush, new Point(OXY.X + scale / 4, scale / 4));

            // OX, OY
            g.DrawLine(bold_pen, OXY, new Point(ClientSize.Width, OXY.Y));
            g.DrawLine(bold_pen, OXY, new Point(OXY.X, scale));

            // График
            float x, y, y1, x1;
            for (int i = 1; i < 13; i++)
            {
                x = OXY.X + i * scale;
                y = OXY.Y - (float)data[i - 1]/Y_scale * scale;
                x1 = OXY.X + (i + 1) * scale;
                y1 = OXY.Y - (float)data[i] / Y_scale * scale;
                g.DrawLine(medium_pen, x, y, x1, y1);
            }
        }
        

    }
}
