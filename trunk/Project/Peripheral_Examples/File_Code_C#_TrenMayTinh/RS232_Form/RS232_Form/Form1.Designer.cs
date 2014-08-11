namespace RS232_Form
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.btConnect = new System.Windows.Forms.Button();
            this.btExit = new System.Windows.Forms.Button();
            this.btDel = new System.Windows.Forms.Button();
            this.btDisconnect = new System.Windows.Forms.Button();
            this.btSend = new System.Windows.Forms.Button();
            this.txtReceive = new System.Windows.Forms.TextBox();
            this.txtSend = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.status = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.bt_back = new System.Windows.Forms.Button();
            this.txt_vitri = new System.Windows.Forms.TextBox();
            this.txt_vantoc = new System.Windows.Forms.TextBox();
            this.bt_HOME = new System.Windows.Forms.Button();
            this.bt_tien = new System.Windows.Forms.Button();
            this.bt_lui = new System.Windows.Forms.Button();
            this.bt_coduoi = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.cbCom = new System.Windows.Forms.ComboBox();
            this.btReScan = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.bảngMãLệnhToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox2.SuspendLayout();
            this.status.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btConnect
            // 
            this.btConnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btConnect.Location = new System.Drawing.Point(15, 13);
            this.btConnect.Name = "btConnect";
            this.btConnect.Size = new System.Drawing.Size(84, 24);
            this.btConnect.TabIndex = 0;
            this.btConnect.Text = "Connect";
            this.btConnect.UseVisualStyleBackColor = true;
            this.btConnect.Click += new System.EventHandler(this.btConnect_Click);
            // 
            // btExit
            // 
            this.btExit.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btExit.Location = new System.Drawing.Point(123, 43);
            this.btExit.Name = "btExit";
            this.btExit.Size = new System.Drawing.Size(84, 25);
            this.btExit.TabIndex = 1;
            this.btExit.Text = "Exit";
            this.btExit.UseVisualStyleBackColor = true;
            this.btExit.Click += new System.EventHandler(this.btExit_Click);
            // 
            // btDel
            // 
            this.btDel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btDel.Location = new System.Drawing.Point(15, 43);
            this.btDel.Name = "btDel";
            this.btDel.Size = new System.Drawing.Size(84, 25);
            this.btDel.TabIndex = 2;
            this.btDel.Text = "Clear";
            this.btDel.UseVisualStyleBackColor = true;
            this.btDel.Click += new System.EventHandler(this.btDel_Click);
            // 
            // btDisconnect
            // 
            this.btDisconnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btDisconnect.Location = new System.Drawing.Point(123, 13);
            this.btDisconnect.Name = "btDisconnect";
            this.btDisconnect.Size = new System.Drawing.Size(84, 24);
            this.btDisconnect.TabIndex = 3;
            this.btDisconnect.Text = "Disconnect";
            this.btDisconnect.UseVisualStyleBackColor = true;
            this.btDisconnect.Click += new System.EventHandler(this.btDisconnect_Click);
            // 
            // btSend
            // 
            this.btSend.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btSend.Location = new System.Drawing.Point(572, 396);
            this.btSend.Name = "btSend";
            this.btSend.Size = new System.Drawing.Size(70, 47);
            this.btSend.TabIndex = 9;
            this.btSend.Text = "SEND";
            this.btSend.UseVisualStyleBackColor = true;
            this.btSend.Click += new System.EventHandler(this.btSend_Click);
            // 
            // txtReceive
            // 
            this.txtReceive.Location = new System.Drawing.Point(278, 63);
            this.txtReceive.Multiline = true;
            this.txtReceive.Name = "txtReceive";
            this.txtReceive.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtReceive.Size = new System.Drawing.Size(364, 97);
            this.txtReceive.TabIndex = 10;
            // 
            // txtSend
            // 
            this.txtSend.Location = new System.Drawing.Point(278, 396);
            this.txtSend.Multiline = true;
            this.txtSend.Name = "txtSend";
            this.txtSend.Size = new System.Drawing.Size(275, 47);
            this.txtSend.TabIndex = 11;
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.Color.Transparent;
            this.groupBox2.Controls.Add(this.btConnect);
            this.groupBox2.Controls.Add(this.btExit);
            this.groupBox2.Controls.Add(this.btDel);
            this.groupBox2.Controls.Add(this.btDisconnect);
            this.groupBox2.Location = new System.Drawing.Point(12, 107);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(220, 76);
            this.groupBox2.TabIndex = 18;
            this.groupBox2.TabStop = false;
            // 
            // status
            // 
            this.status.BackColor = System.Drawing.Color.Transparent;
            this.status.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.status.Location = new System.Drawing.Point(0, 449);
            this.status.Name = "status";
            this.status.Size = new System.Drawing.Size(660, 22);
            this.status.TabIndex = 21;
            this.status.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(118, 17);
            this.toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // groupBox4
            // 
            this.groupBox4.BackColor = System.Drawing.Color.Transparent;
            this.groupBox4.Controls.Add(this.label3);
            this.groupBox4.Controls.Add(this.label2);
            this.groupBox4.Controls.Add(this.bt_back);
            this.groupBox4.Controls.Add(this.txt_vitri);
            this.groupBox4.Controls.Add(this.txt_vantoc);
            this.groupBox4.Controls.Add(this.bt_HOME);
            this.groupBox4.Controls.Add(this.bt_tien);
            this.groupBox4.Controls.Add(this.bt_lui);
            this.groupBox4.Controls.Add(this.bt_coduoi);
            this.groupBox4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox4.ForeColor = System.Drawing.Color.Blue;
            this.groupBox4.Location = new System.Drawing.Point(278, 166);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(363, 224);
            this.groupBox4.TabIndex = 23;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Remote Control";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label3.ForeColor = System.Drawing.Color.Black;
            this.label3.Location = new System.Drawing.Point(124, 113);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(80, 16);
            this.label3.TabIndex = 27;
            this.label3.Text = "Giá trị: 00-99";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label2.ForeColor = System.Drawing.Color.Black;
            this.label2.Location = new System.Drawing.Point(124, 29);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(108, 16);
            this.label2.TabIndex = 26;
            this.label2.Text = "Giá trị: 0000-1500";
            // 
            // bt_back
            // 
            this.bt_back.BackColor = System.Drawing.Color.Yellow;
            this.bt_back.Location = new System.Drawing.Point(275, 21);
            this.bt_back.Name = "bt_back";
            this.bt_back.Size = new System.Drawing.Size(64, 72);
            this.bt_back.TabIndex = 6;
            this.bt_back.Text = "DỪNG";
            this.bt_back.UseVisualStyleBackColor = false;
            this.bt_back.Click += new System.EventHandler(this.bt_back_Click);
            // 
            // txt_vitri
            // 
            this.txt_vitri.Location = new System.Drawing.Point(127, 132);
            this.txt_vitri.Multiline = true;
            this.txt_vitri.Name = "txt_vitri";
            this.txt_vitri.Size = new System.Drawing.Size(108, 22);
            this.txt_vitri.TabIndex = 25;
            // 
            // txt_vantoc
            // 
            this.txt_vantoc.Location = new System.Drawing.Point(127, 48);
            this.txt_vantoc.Multiline = true;
            this.txt_vantoc.Name = "txt_vantoc";
            this.txt_vantoc.Size = new System.Drawing.Size(108, 22);
            this.txt_vantoc.TabIndex = 24;
            // 
            // bt_HOME
            // 
            this.bt_HOME.BackColor = System.Drawing.Color.Lime;
            this.bt_HOME.Location = new System.Drawing.Point(275, 132);
            this.bt_HOME.Name = "bt_HOME";
            this.bt_HOME.Size = new System.Drawing.Size(64, 64);
            this.bt_HOME.TabIndex = 8;
            this.bt_HOME.Text = "HOME";
            this.bt_HOME.UseVisualStyleBackColor = false;
            this.bt_HOME.Click += new System.EventHandler(this.bt_ok_Click);
            // 
            // bt_tien
            // 
            this.bt_tien.BackColor = System.Drawing.Color.Red;
            this.bt_tien.ForeColor = System.Drawing.Color.Yellow;
            this.bt_tien.Location = new System.Drawing.Point(6, 21);
            this.bt_tien.Name = "bt_tien";
            this.bt_tien.Size = new System.Drawing.Size(108, 33);
            this.bt_tien.TabIndex = 5;
            this.bt_tien.Text = "TIẾN";
            this.bt_tien.UseVisualStyleBackColor = false;
            this.bt_tien.Click += new System.EventHandler(this.bt_up_Click);
            // 
            // bt_lui
            // 
            this.bt_lui.BackColor = System.Drawing.Color.Red;
            this.bt_lui.ForeColor = System.Drawing.Color.Yellow;
            this.bt_lui.Location = new System.Drawing.Point(6, 60);
            this.bt_lui.Name = "bt_lui";
            this.bt_lui.Size = new System.Drawing.Size(108, 33);
            this.bt_lui.TabIndex = 4;
            this.bt_lui.Text = "LÙI";
            this.bt_lui.UseVisualStyleBackColor = false;
            this.bt_lui.Click += new System.EventHandler(this.bt_down_Click);
            // 
            // bt_coduoi
            // 
            this.bt_coduoi.BackColor = System.Drawing.Color.Red;
            this.bt_coduoi.ForeColor = System.Drawing.Color.Yellow;
            this.bt_coduoi.Location = new System.Drawing.Point(6, 127);
            this.bt_coduoi.Name = "bt_coduoi";
            this.bt_coduoi.Size = new System.Drawing.Size(108, 33);
            this.bt_coduoi.TabIndex = 3;
            this.bt_coduoi.Text = "CO - DUỖI";
            this.bt_coduoi.UseVisualStyleBackColor = false;
            this.bt_coduoi.Click += new System.EventHandler(this.bt_right_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.Control;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Black;
            this.label1.Location = new System.Drawing.Point(19, 60);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 16);
            this.label1.TabIndex = 12;
            this.label1.Text = "COM Port";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // cbCom
            // 
            this.cbCom.FormattingEnabled = true;
            this.cbCom.Location = new System.Drawing.Point(88, 57);
            this.cbCom.Name = "cbCom";
            this.cbCom.Size = new System.Drawing.Size(121, 24);
            this.cbCom.TabIndex = 4;
            this.cbCom.SelectedIndexChanged += new System.EventHandler(this.cbCom_SelectedIndexChanged);
            // 
            // btReScan
            // 
            this.btReScan.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btReScan.ForeColor = System.Drawing.Color.Black;
            this.btReScan.Location = new System.Drawing.Point(23, 21);
            this.btReScan.Name = "btReScan";
            this.btReScan.Size = new System.Drawing.Size(186, 30);
            this.btReScan.TabIndex = 17;
            this.btReScan.Text = "ReScan";
            this.btReScan.UseVisualStyleBackColor = true;
            this.btReScan.Click += new System.EventHandler(this.button1_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Transparent;
            this.groupBox1.Controls.Add(this.btReScan);
            this.groupBox1.Controls.Add(this.cbCom);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.groupBox1.ForeColor = System.Drawing.Color.Blue;
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(220, 89);
            this.groupBox1.TabIndex = 17;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Settings";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Yellow;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label4.ForeColor = System.Drawing.Color.Black;
            this.label4.Location = new System.Drawing.Point(275, 40);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(178, 16);
            this.label4.TabIndex = 28;
            this.label4.Text = "Trạng thái hiện tại của Robot";
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.AutoSize = true;
            this.panel1.BackgroundImage = global::RS232_Form.Properties.Resources._Logo_hcmut_svg;
            this.panel1.Location = new System.Drawing.Point(12, 213);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(220, 220);
            this.panel1.TabIndex = 24;
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.Color.Chartreuse;
            this.menuStrip1.Dock = System.Windows.Forms.DockStyle.None;
            this.menuStrip1.Font = new System.Drawing.Font("Segoe UI", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bảngMãLệnhToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(517, 21);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(120, 28);
            this.menuStrip1.TabIndex = 29;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.menuStrip1_ItemClicked);
            // 
            // bảngMãLệnhToolStripMenuItem
            // 
            this.bảngMãLệnhToolStripMenuItem.BackColor = System.Drawing.Color.Lime;
            this.bảngMãLệnhToolStripMenuItem.Name = "bảngMãLệnhToolStripMenuItem";
            this.bảngMãLệnhToolStripMenuItem.Size = new System.Drawing.Size(112, 24);
            this.bảngMãLệnhToolStripMenuItem.Text = "Bảng mã lệnh";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(660, 471);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.status);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.txtSend);
            this.Controls.Add(this.txtReceive);
            this.Controls.Add(this.btSend);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "RS232 Form";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox2.ResumeLayout(false);
            this.status.ResumeLayout(false);
            this.status.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btConnect;
        private System.Windows.Forms.Button btExit;
        private System.Windows.Forms.Button btDel;
        private System.Windows.Forms.Button btDisconnect;
        private System.Windows.Forms.Button btSend;
        private System.Windows.Forms.TextBox txtReceive;
        private System.Windows.Forms.TextBox txtSend;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.StatusStrip status;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button bt_lui;
        private System.Windows.Forms.Button bt_coduoi;
        private System.Windows.Forms.Button bt_HOME;
        private System.Windows.Forms.Button bt_back;
        private System.Windows.Forms.Button bt_tien;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cbCom;
        private System.Windows.Forms.Button btReScan;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txt_vitri;
        private System.Windows.Forms.TextBox txt_vantoc;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem bảngMãLệnhToolStripMenuItem;
    }
}

