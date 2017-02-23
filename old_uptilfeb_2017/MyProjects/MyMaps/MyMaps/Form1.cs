using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyMaps
{
    public partial class Form1 : Form
    {
        private string mLocalPage;
        public Form1(string page)
        {
            InitializeComponent();
            mLocalPage = page;
            loadMyPage();
        }

        public  void loadMyPage()
        {
            webBrowser1.ScriptErrorsSuppressed = true;
            webBrowser1.Navigate(mLocalPage);
        }
    }
}
