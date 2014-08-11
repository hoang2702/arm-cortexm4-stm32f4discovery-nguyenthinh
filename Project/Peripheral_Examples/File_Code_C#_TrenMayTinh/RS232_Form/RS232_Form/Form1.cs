using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.IO;
using System.IO.Ports;
using System.Xml; 

namespace RS232_Form
{
    public partial class Form1 : Form
    {
        SerialPort P = new SerialPort();
        string InputData = String.Empty;
        delegate void SetTextCallback(string text);

        public Form1()
        {
            InitializeComponent();
            string[] ports = SerialPort.GetPortNames(); 
 
            // Thêm toàn bộ các COM đã tìm được vào combox cbCom 
            cbCom.Items.AddRange(ports); // Sử dụng AddRange thay vì dùng foreach 
            P.ReadTimeout = 1000; 
            // Khai báo hàm delegate bằng phương thức DataReceived của Object SerialPort; 
            // Cái này khi có sự kiện nhận dữ liệu sẽ nhảy đến phương thức DataReceive 
            // Nếu ko hiểu đoạn này bạn có thể tìm hiểu về Delegate. 
            P.DataReceived += new SerialDataReceivedEventHandler(DataReceive); 
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void btConnect_Click(object sender, EventArgs e)
        {
            //===============================
            if (P.IsOpen)
            {
                P.Close(); // Nếu đang mở Port thì phải đóng lại 
            }
            //===============================
            P.BaudRate = 115200;
            //===============================
            P.DataBits = 8; 
            //===============================
            P.Parity = Parity.None;
            //===============================
            P.StopBits = StopBits.One; 
            //===============================

            try 
            { 
                P.Open(); 
                btDisconnect.Enabled = true; 
                btConnect.Enabled = false;
                btReScan.Enabled = false;
                // Hiện thị Status 
                toolStripStatusLabel1.Text = "Connected " + cbCom.SelectedItem.ToString();
            } 
            catch (Exception ex) 
            { 
                MessageBox.Show("Can't open COM port.","Try again!",MessageBoxButtons.OK,MessageBoxIcon.Error); 
            }
        }

        private void cbCom_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (P.IsOpen)  
            { 
                P.Close(); // Nếu đang mở Port thì phải đóng lại 
            } 
            P.PortName = cbCom.SelectedItem.ToString(); // Gán PortName bằng COM đã chọn 
        }
        //==============================================================
        private void DataReceive(object obj, SerialDataReceivedEventArgs e) 
        { 
            InputData = P.ReadExisting(); 
            if (InputData != String.Empty) 
            { 
                // txtIn.Text = InputData; // Ko dùng đc như thế này vì khác threads . 
                SetText(InputData); // Chính vì vậy phải sử dụng ủy quyền tại đây. Gọi delegate đã khai báo trước đó. 
            } 
        } 
        // Hàm của em nó là ở đây.
        private void SetText(string text) 
        {
            if (this.txtReceive.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText); // khởi tạo 1 delegate mới gọi đến SetText 
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.txtReceive.Text += text;
                //==========================
                txtReceive.SelectionStart = txtReceive.Text.Length;
                txtReceive.ScrollToCaret();
                txtReceive.Refresh();
                //==========================
            }
        }

        private void btSend_Click(object sender, EventArgs e)
        {
            if (P.IsOpen) 
            { 
                if (txtSend.Text == "") MessageBox.Show("Chưa có dữ liệu!","Thông Báo"); 
                else P.Write(txtSend.Text); 
            } 
            else MessageBox.Show("COM chưa mở.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error); 
            //txtSend.Clear(); 
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //cbCom.SelectedIndex = 1; // chọn COM được tìm thấy đầu tiên 
            // Hiện thị Status cho Pro tí 
            toolStripStatusLabel1.Text = "Select a COM port!";
        }

        private void btDisconnect_Click(object sender, EventArgs e)
        {
            P.Close();
            btConnect.Enabled = true;
            btDisconnect.Enabled = false;
            btReScan.Enabled = true;
            // Hiện thị Status 
            toolStripStatusLabel1.Text = "Disconnected";
        }

        private void btExit_Click(object sender, EventArgs e)
        {
            DialogResult kq = MessageBox.Show("Bạn thực sự muốn thoát", "Measseage!", MessageBoxButtons.YesNo, MessageBoxIcon.Question); 
            if (kq == DialogResult.Yes) 
            {
                this.Close(); 
            }
        }

        private void btDel_Click(object sender, EventArgs e)
        {
            txtReceive.Text = "";
            txtSend.Text = "";
        }

        private void nguyễnXuânThịnh21003218ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 frm = new Form2();
            frm.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();

            // Thêm toàn bộ các COM đã tìm được vào combox cbCom 
            cbCom.Items.Clear();
            cbCom.Text = "";
            cbCom.Items.AddRange(ports); // Sử dụng AddRange thay vì dùng foreach
            toolStripStatusLabel1.Text = "Select a COM port!";
        }

        private void bt_ok_Click(object sender, EventArgs e)
        {
            if (P.IsOpen)
            {
                P.Write("40000e");
            }
            else MessageBox.Show("COM chưa mở.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
            txtSend.Clear(); 
        }

        private void bt_back_Click(object sender, EventArgs e)
        {
            if (P.IsOpen)
            {
                P.Write("20000e");
            }
            else MessageBox.Show("COM chưa mở.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void bt_left_Click(object sender, EventArgs e)
        {
            if (P.IsOpen)
            {
                P.Write("*/*4" + '\0');
            }
            else MessageBox.Show("COM chưa mở.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
            txtSend.Clear(); 
        }

        private void bt_right_Click(object sender, EventArgs e)
        {
            if (txt_vitri.TextLength == 2)
            {
                if (P.IsOpen)
                {
                    P.Write('5'+"00"+txt_vitri.Text + 'e');
                }
                else MessageBox.Show("COM chưa mở.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtSend.Clear();
            }
            else
                MessageBox.Show("Dữ liệu phải có 2 chữ số !!!", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void bt_up_Click(object sender, EventArgs e)
        {
            if (txt_vantoc.TextLength == 4)
            {
                if (P.IsOpen)
                {
                    P.Write('2'+txt_vantoc.Text + 'e');
                }
                else MessageBox.Show("COM chưa mở.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
                MessageBox.Show("Dữ liệu phải có 4 chữ số !!!", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void bt_down_Click(object sender, EventArgs e)
        {
            if (txt_vantoc.TextLength == 4)
            {
                if (P.IsOpen)
                {
                    P.Write('6'+txt_vantoc.Text + 'e');
                }
                else MessageBox.Show("COM chưa mở.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
                MessageBox.Show("Dữ liệu phải có 4 chữ số !!!", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            Form2 frm = new Form2();
            frm.ShowDialog();
        }
    }
}
