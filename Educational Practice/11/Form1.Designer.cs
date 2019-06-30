namespace _11
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_New = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Open = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Close = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.Menu_Save = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_SaveAs = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.Menu_Exit = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_Help = new System.Windows.Forms.ToolStripMenuItem();
            this.Menu_About = new System.Windows.Forms.ToolStripMenuItem();
            this.statusBar = new System.Windows.Forms.StatusStrip();
            this.StatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.panel1 = new System.Windows.Forms.Panel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.QuantityBox = new System.Windows.Forms.NumericUpDown();
            this.DateBox = new System.Windows.Forms.DateTimePicker();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.Age = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.AgeTo = new System.Windows.Forms.TextBox();
            this.AgeFrom = new System.Windows.Forms.TextBox();
            this.ProviderBox = new System.Windows.Forms.TextBox();
            this.UnitPriceBox = new System.Windows.Forms.TextBox();
            this.CodeBox = new System.Windows.Forms.TextBox();
            this.NameBox = new System.Windows.Forms.TextBox();
            this.btnPrevious = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnNext = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.menuStrip1.SuspendLayout();
            this.statusBar.SuspendLayout();
            this.panel1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.QuantityBox)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.Menu_Help});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(381, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Menu_New,
            this.Menu_Open,
            this.Menu_Close,
            this.toolStripSeparator1,
            this.Menu_Save,
            this.Menu_SaveAs,
            this.toolStripSeparator2,
            this.Menu_Exit});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // Menu_New
            // 
            this.Menu_New.Name = "Menu_New";
            this.Menu_New.Size = new System.Drawing.Size(121, 22);
            this.Menu_New.Text = "New";
            this.Menu_New.Click += new System.EventHandler(this.Menu_New_Click);
            this.Menu_New.MouseEnter += new System.EventHandler(this.Menu_New_MouseEnter);
            this.Menu_New.MouseLeave += new System.EventHandler(this.Menu_New_MouseLeave);
            // 
            // Menu_Open
            // 
            this.Menu_Open.Name = "Menu_Open";
            this.Menu_Open.Size = new System.Drawing.Size(121, 22);
            this.Menu_Open.Text = "Open...";
            this.Menu_Open.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            this.Menu_Open.MouseEnter += new System.EventHandler(this.openToolStripMenuItem_MouseEnter);
            this.Menu_Open.MouseLeave += new System.EventHandler(this.openToolStripMenuItem_MouseLeave);
            // 
            // Menu_Close
            // 
            this.Menu_Close.Enabled = false;
            this.Menu_Close.Name = "Menu_Close";
            this.Menu_Close.Size = new System.Drawing.Size(121, 22);
            this.Menu_Close.Text = "Close";
            this.Menu_Close.Click += new System.EventHandler(this.Menu_Close_Click);
            this.Menu_Close.MouseEnter += new System.EventHandler(this.toolStripMenuItem1_MouseEnter);
            this.Menu_Close.MouseLeave += new System.EventHandler(this.toolStripMenuItem1_MouseLeave);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(118, 6);
            // 
            // Menu_Save
            // 
            this.Menu_Save.Enabled = false;
            this.Menu_Save.Image = global::_11.Properties.Resources.save;
            this.Menu_Save.Name = "Menu_Save";
            this.Menu_Save.Size = new System.Drawing.Size(121, 22);
            this.Menu_Save.Text = "Save";
            this.Menu_Save.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            this.Menu_Save.MouseEnter += new System.EventHandler(this.saveToolStripMenuItem_MouseEnter);
            this.Menu_Save.MouseLeave += new System.EventHandler(this.saveToolStripMenuItem_MouseLeave);
            // 
            // Menu_SaveAs
            // 
            this.Menu_SaveAs.Enabled = false;
            this.Menu_SaveAs.Name = "Menu_SaveAs";
            this.Menu_SaveAs.Size = new System.Drawing.Size(121, 22);
            this.Menu_SaveAs.Text = "Save as...";
            this.Menu_SaveAs.Click += new System.EventHandler(this.saveAsToolStripMenuItem_Click);
            this.Menu_SaveAs.MouseEnter += new System.EventHandler(this.saveAsToolStripMenuItem_MouseEnter);
            this.Menu_SaveAs.MouseLeave += new System.EventHandler(this.saveAsToolStripMenuItem_MouseLeave);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(118, 6);
            // 
            // Menu_Exit
            // 
            this.Menu_Exit.Image = global::_11.Properties.Resources.exit;
            this.Menu_Exit.Name = "Menu_Exit";
            this.Menu_Exit.Size = new System.Drawing.Size(121, 22);
            this.Menu_Exit.Text = "Exit";
            this.Menu_Exit.Click += new System.EventHandler(this.Menu_Exit_Click);
            this.Menu_Exit.MouseEnter += new System.EventHandler(this.exitToolStripMenuItem_MouseEnter);
            this.Menu_Exit.MouseLeave += new System.EventHandler(this.exitToolStripMenuItem_MouseLeave);
            // 
            // Menu_Help
            // 
            this.Menu_Help.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Menu_About});
            this.Menu_Help.Name = "Menu_Help";
            this.Menu_Help.Size = new System.Drawing.Size(44, 20);
            this.Menu_Help.Text = "&Help";
            // 
            // Menu_About
            // 
            this.Menu_About.Name = "Menu_About";
            this.Menu_About.Size = new System.Drawing.Size(116, 22);
            this.Menu_About.Text = "About...";
            this.Menu_About.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            this.Menu_About.MouseEnter += new System.EventHandler(this.aboutToolStripMenuItem_MouseEnter);
            this.Menu_About.MouseLeave += new System.EventHandler(this.aboutToolStripMenuItem_MouseLeave);
            // 
            // statusBar
            // 
            this.statusBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusLabel});
            this.statusBar.Location = new System.Drawing.Point(0, 314);
            this.statusBar.Name = "statusBar";
            this.statusBar.Size = new System.Drawing.Size(381, 22);
            this.statusBar.SizingGrip = false;
            this.statusBar.TabIndex = 1;
            // 
            // StatusLabel
            // 
            this.StatusLabel.Name = "StatusLabel";
            this.StatusLabel.Size = new System.Drawing.Size(0, 17);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.groupBox1);
            this.panel1.Controls.Add(this.btnPrevious);
            this.panel1.Controls.Add(this.btnDelete);
            this.panel1.Controls.Add(this.btnNext);
            this.panel1.Controls.Add(this.btnAdd);
            this.panel1.Location = new System.Drawing.Point(0, 27);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(377, 284);
            this.panel1.TabIndex = 2;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.pictureBox1);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.QuantityBox);
            this.groupBox1.Controls.Add(this.DateBox);
            this.groupBox1.Controls.Add(this.label8);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.Age);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.AgeTo);
            this.groupBox1.Controls.Add(this.AgeFrom);
            this.groupBox1.Controls.Add(this.ProviderBox);
            this.groupBox1.Controls.Add(this.UnitPriceBox);
            this.groupBox1.Controls.Add(this.CodeBox);
            this.groupBox1.Controls.Add(this.NameBox);
            this.groupBox1.Location = new System.Drawing.Point(24, 15);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(326, 215);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Toy";
            // 
            // pictureBox1
            // 
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox1.Image = global::_11.Properties.Resources.toy;
            this.pictureBox1.Location = new System.Drawing.Point(228, 16);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(88, 92);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 8;
            this.pictureBox1.TabStop = false;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(97, 149);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(16, 13);
            this.label5.TabIndex = 5;
            this.label5.Text = "to";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(32, 150);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(27, 13);
            this.label4.TabIndex = 4;
            this.label4.Text = "from";
            // 
            // QuantityBox
            // 
            this.QuantityBox.Enabled = false;
            this.QuantityBox.Location = new System.Drawing.Point(103, 89);
            this.QuantityBox.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.QuantityBox.Name = "QuantityBox";
            this.QuantityBox.Size = new System.Drawing.Size(43, 20);
            this.QuantityBox.TabIndex = 2;
            this.QuantityBox.Leave += new System.EventHandler(this.QuantityBox_Leave);
            // 
            // DateBox
            // 
            this.DateBox.Enabled = false;
            this.DateBox.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.DateBox.Location = new System.Drawing.Point(188, 146);
            this.DateBox.Name = "DateBox";
            this.DateBox.Size = new System.Drawing.Size(114, 20);
            this.DateBox.TabIndex = 6;
            this.DateBox.Value = new System.DateTime(2018, 6, 8, 0, 45, 40, 0);
            this.DateBox.Leave += new System.EventHandler(this.DateBox_Leave);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(185, 169);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(46, 13);
            this.label8.TabIndex = 1;
            this.label8.Text = "Provider";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(185, 130);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(68, 13);
            this.label7.TabIndex = 1;
            this.label7.Text = "Receipt date";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(32, 169);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(52, 13);
            this.label6.TabIndex = 1;
            this.label6.Text = "Unit price";
            // 
            // Age
            // 
            this.Age.AutoSize = true;
            this.Age.Location = new System.Drawing.Point(32, 130);
            this.Age.Name = "Age";
            this.Age.Size = new System.Drawing.Size(26, 13);
            this.Age.TabIndex = 1;
            this.Age.Text = "Age";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(100, 72);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 13);
            this.label3.TabIndex = 1;
            this.label3.Text = "Quantity";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(32, 73);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(32, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Code";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(32, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Name";
            // 
            // AgeTo
            // 
            this.AgeTo.Enabled = false;
            this.AgeTo.Location = new System.Drawing.Point(114, 146);
            this.AgeTo.MaxLength = 2;
            this.AgeTo.Name = "AgeTo";
            this.AgeTo.Size = new System.Drawing.Size(32, 20);
            this.AgeTo.TabIndex = 4;
            this.AgeTo.Leave += new System.EventHandler(this.AgeTo_Leave);
            // 
            // AgeFrom
            // 
            this.AgeFrom.Enabled = false;
            this.AgeFrom.Location = new System.Drawing.Point(59, 146);
            this.AgeFrom.MaxLength = 2;
            this.AgeFrom.Name = "AgeFrom";
            this.AgeFrom.Size = new System.Drawing.Size(32, 20);
            this.AgeFrom.TabIndex = 3;
            this.AgeFrom.Leave += new System.EventHandler(this.AgeFrom_Leave);
            // 
            // ProviderBox
            // 
            this.ProviderBox.Enabled = false;
            this.ProviderBox.Location = new System.Drawing.Point(188, 185);
            this.ProviderBox.MaxLength = 18;
            this.ProviderBox.Name = "ProviderBox";
            this.ProviderBox.Size = new System.Drawing.Size(114, 20);
            this.ProviderBox.TabIndex = 7;
            this.ProviderBox.Leave += new System.EventHandler(this.ProviderBox_Leave);
            // 
            // UnitPriceBox
            // 
            this.UnitPriceBox.Enabled = false;
            this.UnitPriceBox.Location = new System.Drawing.Point(35, 185);
            this.UnitPriceBox.MaxLength = 18;
            this.UnitPriceBox.Name = "UnitPriceBox";
            this.UnitPriceBox.Size = new System.Drawing.Size(114, 20);
            this.UnitPriceBox.TabIndex = 5;
            this.UnitPriceBox.Leave += new System.EventHandler(this.UnitPriceBox_Leave);
            // 
            // CodeBox
            // 
            this.CodeBox.Enabled = false;
            this.CodeBox.Location = new System.Drawing.Point(35, 89);
            this.CodeBox.MaxLength = 18;
            this.CodeBox.Name = "CodeBox";
            this.CodeBox.Size = new System.Drawing.Size(56, 20);
            this.CodeBox.TabIndex = 1;
            this.CodeBox.Leave += new System.EventHandler(this.CodeBox_Leave);
            // 
            // NameBox
            // 
            this.NameBox.Enabled = false;
            this.NameBox.Location = new System.Drawing.Point(35, 50);
            this.NameBox.MaxLength = 18;
            this.NameBox.Name = "NameBox";
            this.NameBox.Size = new System.Drawing.Size(114, 20);
            this.NameBox.TabIndex = 0;
            this.NameBox.Leave += new System.EventHandler(this.NameBox_Leave);
            // 
            // btnPrevious
            // 
            this.btnPrevious.BackgroundImage = global::_11.Properties.Resources.arrow_to_left;
            this.btnPrevious.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnPrevious.Enabled = false;
            this.btnPrevious.Location = new System.Drawing.Point(24, 245);
            this.btnPrevious.Name = "btnPrevious";
            this.btnPrevious.Size = new System.Drawing.Size(35, 23);
            this.btnPrevious.TabIndex = 8;
            this.btnPrevious.UseVisualStyleBackColor = true;
            this.btnPrevious.Click += new System.EventHandler(this.btnPrevious_Click);
            this.btnPrevious.MouseEnter += new System.EventHandler(this.btnPrevious_MouseEnter);
            this.btnPrevious.MouseLeave += new System.EventHandler(this.btnPrevious_MouseLeave);
            // 
            // btnDelete
            // 
            this.btnDelete.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnDelete.Enabled = false;
            this.btnDelete.Location = new System.Drawing.Point(139, 245);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(48, 23);
            this.btnDelete.TabIndex = 10;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            this.btnDelete.MouseEnter += new System.EventHandler(this.btnDelete_MouseEnter);
            this.btnDelete.MouseLeave += new System.EventHandler(this.btnDelete_MouseLeave);
            // 
            // btnNext
            // 
            this.btnNext.BackgroundImage = global::_11.Properties.Resources.arrow_to_right;
            this.btnNext.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnNext.Enabled = false;
            this.btnNext.Location = new System.Drawing.Point(315, 245);
            this.btnNext.Name = "btnNext";
            this.btnNext.Size = new System.Drawing.Size(35, 23);
            this.btnNext.TabIndex = 9;
            this.btnNext.UseVisualStyleBackColor = true;
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            this.btnNext.MouseEnter += new System.EventHandler(this.btnNext_MouseEnter);
            this.btnNext.MouseLeave += new System.EventHandler(this.btnNext_MouseLeave);
            // 
            // btnAdd
            // 
            this.btnAdd.Enabled = false;
            this.btnAdd.Location = new System.Drawing.Point(200, 245);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(48, 23);
            this.btnAdd.TabIndex = 11;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            this.btnAdd.MouseEnter += new System.EventHandler(this.btnAdd_MouseEnter);
            this.btnAdd.MouseLeave += new System.EventHandler(this.btnAdd_MouseLeave);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            this.openFileDialog1.Filter = "Data|*.dat|All files|*.*";
            this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog1_FileOk);
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.Filter = "Data|*.dat|All files|*.*";
            this.saveFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.saveFileDialog1_FileOk);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(381, 336);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.statusBar);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Record editor";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.statusBar.ResumeLayout(false);
            this.statusBar.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.QuantityBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.StatusStrip statusBar;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem Menu_Open;
        private System.Windows.Forms.ToolStripMenuItem Menu_Close;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem Menu_Save;
        private System.Windows.Forms.ToolStripMenuItem Menu_SaveAs;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem Menu_Exit;
        private System.Windows.Forms.ToolStripMenuItem Menu_Help;
        private System.Windows.Forms.ToolStripMenuItem Menu_About;
        private System.Windows.Forms.ToolStripStatusLabel StatusLabel;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btnPrevious;
        private System.Windows.Forms.Button btnNext;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label Age;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox ProviderBox;
        private System.Windows.Forms.TextBox UnitPriceBox;
        private System.Windows.Forms.TextBox CodeBox;
        private System.Windows.Forms.TextBox NameBox;
        private System.Windows.Forms.DateTimePicker DateBox;
        private System.Windows.Forms.NumericUpDown QuantityBox;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.ToolStripMenuItem Menu_New;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox AgeTo;
        private System.Windows.Forms.TextBox AgeFrom;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

