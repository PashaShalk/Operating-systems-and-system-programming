using System;
using System.Diagnostics;
using System.Windows.Forms;
using System.Windows.Threading;
using System.Threading;
using ClassLibrary1;

namespace lab3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public const string PAINT_PATH = "C://Windows//System32//mspaint.exe";
        public const string CALC_PATH = "C://Windows//System32//calc.exe";
        public const string CALC_NAME = "Calculator";
        public const string FILE1_PATH = "C://Users//vanya//Desktop//Osi//test1.txt";
        public const string FILE2_PATH = "C://Users//vanya//Desktop//Osi//test2.txt";
        public const string TEXTBOX_EMPTY_VALUE = "";
        public const string MESSAGEBOX_LEVEL = "Error";

        private string ticker = "The first thing you learn in life is you're a fool. The last thing you learn in life is you're the same fool.";

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (Process.GetProcessesByName(CALC_NAME).Length > 0)
            {
                Process.GetProcessesByName(CALC_NAME)[0].Kill();
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            ticker = ticker.Substring(1) + ticker[0];
            textBox1.Text = ticker;
        }

        private void button2_Click(object sender, EventArgs e)
        {

            Dispatcher dispatcher = Dispatcher.CurrentDispatcher;
            Thread thread1 = new Thread(() => {

                string result = new FileReader(FILE1_PATH).getCountDigitsInFile().ToString();
                dispatcher.Invoke(() => textBox2.Text = result);
            });  
            thread1.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox2.Text= new FileReader(FILE1_PATH).getCountDigitsInFile().ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {

            Dispatcher dispatcher = Dispatcher.CurrentDispatcher;
            Thread thread1 = new Thread(()=> {
                string result1 = new FileReader(FILE1_PATH).getCountDigitsInFile().ToString();
                dispatcher.Invoke(() => textBox2.Text = result1);
            });
            Thread thread2 = new Thread(()=> {
                string result2 = new FileReader(FILE1_PATH).getCountDigitsInFile().ToString();
                dispatcher.Invoke(() => textBox3.Text = result2);
            });
            thread1.Priority = ThreadPriority.Lowest;
            thread2.Priority = ThreadPriority.Highest;
            thread1.Start();
            thread2.Start();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Process.Start(PAINT_PATH);
            Process.Start(CALC_PATH);
            timer1.Start();
        }
    }
}
