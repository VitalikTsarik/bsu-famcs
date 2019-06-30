using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace _11
{
    public partial class Form1 : Form
    {
        public data Data = new data();
        public Form1()
        {
            InitializeComponent();
        }

        private void ShowItem(int index)
        {
            NameBox.Text = Data[index].Name;
            CodeBox.Text = Data[index].Code;
            ProviderBox.Text = Data[index].Provider;
            UnitPriceBox.Text = Data[index].UnitPrice;
            QuantityBox.Value = Data[index].Quantity;
            AgeFrom.Text = Data[index].AgeFrom;
            AgeTo.Text = Data[index].AgeTo;
            DateBox.Value = new DateTime(Data[index].Year, Data[index].Month, Data[index].Day);
        }
        private void ShowItem()
        {
            NameBox.Text = "";
            CodeBox.Text = "";
            ProviderBox.Text = "";
            UnitPriceBox.Text = "";
            QuantityBox.Value = 0;
            AgeFrom.Text = "";
            AgeTo.Text = "";
            DateBox.Value = DateTime.Now;
        }

        private void Enable()
        {
            Menu_Close.Enabled = true;
            Menu_Save.Enabled = true;
            Menu_SaveAs.Enabled = true;
            CodeBox.Enabled = true;
            NameBox.Enabled = true;
            ProviderBox.Enabled = true;
            UnitPriceBox.Enabled = true;
            QuantityBox.Enabled = true;
            DateBox.Enabled = true;
            AgeFrom.Enabled = true;
            AgeTo.Enabled = true;
            btnAdd.Enabled = true;
            btnDelete.Enabled = true;
            if (Data.CurrentItemIndex > 0)
                btnPrevious.Enabled = true;
            if (Data.CurrentItemIndex != Data.lastIndex)
                btnNext.Enabled = true;
        }
        private void Disable()
        {
            Menu_Close.Enabled = false;
            Menu_Save.Enabled = false;
            Menu_SaveAs.Enabled = false;
            CodeBox.Enabled = false;
            NameBox.Enabled = false;
            ProviderBox.Enabled = false;
            UnitPriceBox.Enabled = false;
            QuantityBox.Enabled = false;
            DateBox.Enabled = false;
            AgeFrom.Enabled = false;
            AgeTo.Enabled = false;
            btnAdd.Enabled = false;
            btnDelete.Enabled = false;
            btnPrevious.Enabled = false;
            btnNext.Enabled = false;
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Задание №11 вариант 13\n" + "Царик Виталий 1-й курс 2-я группа",
                "About...", // message tittle
                MessageBoxButtons.OK, // message buttons
                MessageBoxIcon.Information); // message icon
        }

        private void openToolStripMenuItem_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Open an existing file...";

        private void openToolStripMenuItem_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void toolStripMenuItem1_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Close current file";

        private void toolStripMenuItem1_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void saveToolStripMenuItem_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Save current file";

        private void saveToolStripMenuItem_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void saveAsToolStripMenuItem_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Save current file with new name...";

        private void saveAsToolStripMenuItem_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void exitToolStripMenuItem_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Exit the application";

        private void exitToolStripMenuItem_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void aboutToolStripMenuItem_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Show information about the programm...";

        private void aboutToolStripMenuItem_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void btnNext_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Next item";

        private void btnNext_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void btnPrevious_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Previous item";

        private void btnPrevious_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void btnAdd_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Add a new item";

        private void btnAdd_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void btnDelete_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Delete current item";

        private void btnDelete_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void Menu_New_MouseEnter(object sender, EventArgs e) => StatusLabel.Text = "Create new list";

        private void Menu_New_MouseLeave(object sender, EventArgs e) => StatusLabel.Text = "";

        private void NameBox_Leave(object sender, EventArgs e)
        {
            Data[Data.CurrentItemIndex].Name = NameBox.Text;
        }

        private void CodeBox_Leave(object sender, EventArgs e)
        {
            Data[Data.CurrentItemIndex].Code = CodeBox.Text;
        }

        private void QuantityBox_Leave(object sender, EventArgs e)
        {
            Data[Data.CurrentItemIndex].Quantity = (int)QuantityBox.Value;
        }

        private void AgeFrom_Leave(object sender, EventArgs e)
        {
            Data[Data.CurrentItemIndex].AgeFrom = AgeFrom.Text;
            Data.SavedToFile = false;
        }

        private void AgeTo_Leave(object sender, EventArgs e)
        {
            Data[Data.CurrentItemIndex].AgeTo = AgeTo.Text;
            Data.SavedToFile = false;
        }

        private void UnitPriceBox_Leave(object sender, EventArgs e)
        {
            Data[Data.CurrentItemIndex].UnitPrice = UnitPriceBox.Text;
            Data.SavedToFile = false;
        }

        private void DateBox_Leave(object sender, EventArgs e)
        {
            Data[Data.CurrentItemIndex].Day = DateBox.Value.Day;
            Data[Data.CurrentItemIndex].Month = DateBox.Value.Month;
            Data[Data.CurrentItemIndex].Year = DateBox.Value.Year;
            Data.SavedToFile = false;
        }

        private void ProviderBox_Leave(object sender, EventArgs e)
        {
            Data[Data.CurrentItemIndex].Provider = ProviderBox.Text;
            Data.SavedToFile = false;
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            Data.ReadData(openFileDialog1.FileName);
            Data.Current_filename = openFileDialog1.FileName;
            Enable();
            ShowItem(Data.CurrentItemIndex);
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Disable();
            Enable();
            Data.WriteData(Data.Current_filename);
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Disable();
            Enable();
            saveFileDialog1.ShowDialog();
        }

        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            Data.WriteData(saveFileDialog1.FileName);
            Data.Current_filename = saveFileDialog1.FileName;
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            Data.Add(new item());
            Data.SavedToFile = false;
            ShowItem();
            btnNext.Enabled = false;
            btnPrevious.Enabled = true;
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            Data.Delete(Data.CurrentItemIndex);
            Data.SavedToFile = false;
            if (Data.CurrentItemIndex > 0)
                Data.CurrentItemIndex--;
            if (Data.lastIndex > -1)
                ShowItem(Data.CurrentItemIndex);
            else
            {
                Disable();
                ShowItem();
            }
            if (Data.CurrentItemIndex == 0)
                btnPrevious.Enabled = false;
            if (Data.CurrentItemIndex == Data.lastIndex)
                btnNext.Enabled = false;
        }

        private void Menu_Close_Click(object sender, EventArgs e)
        {
            Disable();
            Data.Clear();
            ShowItem();
        }

        private void btnPrevious_Click(object sender, EventArgs e)
        {
            if (btnNext.Enabled == false)
                btnNext.Enabled = true;
            Data.CurrentItemIndex--;
            ShowItem(Data.CurrentItemIndex);
            if (Data.CurrentItemIndex == 0)
                btnPrevious.Enabled = false;
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            if (btnPrevious.Enabled == false)
                btnPrevious.Enabled = true;
            Data.CurrentItemIndex++;
            ShowItem(Data.CurrentItemIndex);
            if (Data.CurrentItemIndex == Data.lastIndex)
                btnNext.Enabled = false;
        }

        private void Menu_New_Click(object sender, EventArgs e)
        {
            Disable();
            Data.Clear();
            Data.Add(new item());
            Enable();
            Menu_Save.Enabled = false;
            Data.CurrentItemIndex = 0;
            ShowItem();
        }



        private void Menu_Exit_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (Data.SavedToFile == false && Data.lastIndex != -1)
                if (MessageBox.Show("Exit with unsaved changes?", Text,
                    MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.Cancel)
                {
                    e.Cancel = true;
                }
        }
    }
}
