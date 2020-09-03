using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DesktopWindowDllTest
{

    public partial class DesktopWIndowDllTest : Form
    {

        [DllImport("DesktopWindowDll.dll")]
        public static extern bool Test();

        [DllImport("DesktopWindowDll.dll")]
        public static extern bool SetDesktopWindow(IntPtr hwnd);

        [DllImport("DesktopWindowDll.dll")]
        public static extern bool RecoverDesktopWindow(IntPtr hwnd);


        public DesktopWIndowDllTest()
        {
            InitializeComponent();
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            if (Test())
            {
                SetDesktopWindow(this.Handle);
                timer1.Start();
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            RecoverDesktopWindow(this.Handle);
        }

        private static readonly int pixStep = 2;
        private bool left = true;
        private bool top = true;
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (top)
                pictureBox1.Top -= pixStep;
            else
                pictureBox1.Top += pixStep;
            if (left)
                pictureBox1.Left -= pixStep;
            else
                pictureBox1.Left += pixStep;
            if (pictureBox1.Left <= 0)
                left = false;
            else if (pictureBox1.Right>=this.Width)
                left = true;
            if (pictureBox1.Top <= 0)
                top = false;
            else if (pictureBox1.Bottom >= this.Height)
                top = true;
        }
    }
}
