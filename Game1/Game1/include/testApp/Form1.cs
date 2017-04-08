using System;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using DMathLib;
using Collision;

namespace testApp
{
    using HALF = System.UInt16;

    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void btColor_Click(object sender, EventArgs e)
        {

            Memo.Clear();
            // XMColorSRGBToRGB
            Memo.AppendText("\r\nXMColorSRGBToRGB\r\n");
            dmXMVECTOR colorIn = DMathClass.XMVectorSet(0.5f, 0.1f, 0.4f, 0.0f);

            string s = String.Format("sRGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR colorOut = DMathClass.XMColorSRGBToRGB(colorIn);
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorRGBToSRGB
            Memo.AppendText("\r\nXMColorRGBToSRGB\r\n");
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorRGBToSRGB(colorIn);
            s = String.Format("sRGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorAdjustContrast
            colorIn.dmXMVECTOR_f32.w = 0.1f;
            Memo.AppendText("\r\nXMColorAdjustContrast, with 0.4 contrast\r\n");
            s = String.Format("Color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorAdjustContrast(colorIn, 0.4f);
            s = String.Format("Resulting color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorAdjustSaturation
            Memo.AppendText("\r\nXMColorAdjustSaturation, with 0.4 saturation\r\n");
            s = String.Format("Color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorAdjustSaturation(colorIn, 0.4f);
            s = String.Format("Resulting color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorEqual
            Memo.AppendText("\r\nXMColorEqual\r\n");
            s = String.Format("Color1 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Color2 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool colorBool = DMathClass.XMColorEqual(colorIn, colorIn);
            s = String.Format("Colors equal? {0}\r\n", colorBool);
            Memo.AppendText(s);

            // XMColorGreater
            Memo.AppendText("\r\nXMColorGreater\r\n");
            s = String.Format("Color1 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Color2 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorBool = DMathClass.XMColorGreater(colorIn, colorIn);
            s = String.Format("Color1 Greater? {0}\r\n", colorBool);
            Memo.AppendText(s);

            // XMColorGreaterOrEqual
            Memo.AppendText("\r\nXMColorGreaterOrEqual\r\n");
            s = String.Format("Color1 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Color2 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorBool = DMathClass.XMColorGreaterOrEqual(colorIn, colorIn);
            s = String.Format("Greater or Equal? {0}\r\n", colorBool);
            Memo.AppendText(s);

            // XMColorHSLToRGB
            Memo.AppendText("\r\nXMColorHSLToRGB\r\n");
            s = String.Format("HSL color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorHSLToRGB(colorIn);
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorIsInfinite
            Memo.AppendText("\r\nXMColorIsInfinite\r\n");
            s = String.Format("Color1 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorBool = DMathClass.XMColorIsInfinite(colorIn);
            s = String.Format("Is infinite? {0}\r\n", colorBool);
            Memo.AppendText(s);

            // XMColorModulate
            Memo.AppendText("\r\nXMColorModulate\r\n");
            s = String.Format("Color1 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Color2 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorModulate(colorIn, colorIn);
            s = String.Format("Resulting color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorNegative
            Memo.AppendText("\r\nXMColorNegative\r\n");
            s = String.Format("Color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorNegative(colorIn);
            s = String.Format("Resulting color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorNotEqual
            Memo.AppendText("\r\nXMColorNotEqual\r\n");
            s = String.Format("Color1 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Color2 vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorBool = DMathClass.XMColorNotEqual(colorIn, colorIn);
            s = String.Format("Not Equal? {0}\r\n", colorBool);
            Memo.AppendText(s);

            // XMColorRGBToHSL
            colorIn.dmXMVECTOR_f32.w = 0.0f;
            Memo.AppendText("\r\nXMColorRGBToHSL\r\n");
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorRGBToHSL(colorIn);
            s = String.Format("HSL color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorRGBToHSV
            Memo.AppendText("\r\nXMColorRGBToHSV\r\n");
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorRGBToHSV(colorIn);
            s = String.Format("HSV color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorRGBToXYZ
            Memo.AppendText("\r\nXMColorRGBToXYZ\r\n");
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorRGBToXYZ(colorIn);
            s = String.Format("XYZ color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorRGBToYUV_HD
            colorIn.dmXMVECTOR_f32.w = 0.0f;
            Memo.AppendText("\r\nXMColorRGBToYUV_HD\r\n");
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorRGBToYUV_HD(colorIn);
            s = String.Format("YUV color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorSRGBToXYZ
            Memo.AppendText("\r\nXMColorSRGBToXYZ\r\n");
            s = String.Format("sRGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorSRGBToXYZ(colorIn);
            s = String.Format("XYZ color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorXYZToRGB
            Memo.AppendText("\r\nXMColorXYZToRGB\r\n");
            s = String.Format("XYZ color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorXYZToRGB(colorIn);
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorXYZToSRGB
            Memo.AppendText("\r\nXMColorXYZToSRGB\r\n");
            s = String.Format("XYZ color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorXYZToSRGB(colorIn);
            s = String.Format("SRGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMColorYUVToRGB
            Memo.AppendText("\r\nXMColorYUVToRGB\r\n");
            s = String.Format("YUV color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorIn.dmXMVECTOR_f32.x, colorIn.dmXMVECTOR_f32.y, colorIn.dmXMVECTOR_f32.z, colorIn.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            colorOut = DMathClass.XMColorYUVToRGB(colorIn);
            s = String.Format("RGB color vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", colorOut.dmXMVECTOR_f32.x, colorOut.dmXMVECTOR_f32.y, colorOut.dmXMVECTOR_f32.z, colorOut.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
        }

        private void btVectorLoad_Click(object sender, EventArgs e)
        {
            Memo.Clear();
            // XMLoadByte2
            Memo.AppendText("XMLoadByte2\r\n");
            dmXMBYTE2 xmbyte2 = new dmXMBYTE2(3.0f, -2.0f);
            //
            string s = String.Format("Input: Signed 8-bit x={0}, signed 8-bit y={1}\r\n", xmbyte2.x, xmbyte2.y);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMLoadByte2(xmbyte2);
            s = String.Format("Resulting vector:  {0:0.00},{1:0.00},{2:0.00},{3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadByteN2
            Memo.AppendText("\r\nXMLoadByteN2\r\n");
            dmXMBYTEN2 xmbyten2 = new dmXMBYTEN2(100, -122);
            s = String.Format("Input: Signed 8-bit x={0}, signed 8-bit y={1}\r\n", xmbyten2.x, xmbyten2.y);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadByteN2(xmbyten2);
            s = String.Format("Resulting vector:  {0:0.00},{1:0.00},{2:0.00},{3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadByte4
            Memo.AppendText("\r\nXMLoadByte4\r\n");
            dmXMBYTE4 xmbyte4 = new dmXMBYTE4(33, -125, 123, -2);
            s = String.Format("Input, signed 8-bit: x={0}, y={1}, z={2}, w={3}\r\n", xmbyte4.x, xmbyte4.y, xmbyte4.z, xmbyte4.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadByte4(xmbyte4);
            s = String.Format("Resulting vector:  {0:0.00},{1:0.00},{2:0.00},{3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadColor
            Memo.AppendText("\r\nXMLoadColor\r\n");
            dmXMCOLOR xmcolor = new dmXMCOLOR(0.3f, 0.4f, 0.5f, 0.6f);
            s = String.Format("Input Color: c={0:X}\r\n", xmcolor.c);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadColor(xmcolor);
            s = String.Format("Resulting vector:  {0:0.00},{1:0.00},{2:0.00},{3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadFloat3PK
            Memo.AppendText("\r\nXMLoadFloat3PK\r\n");
            dmXMFLOAT3PK xmfloat3pk = new dmXMFLOAT3PK(12, 3, 13, 4, 14, 5);
            s = String.Format("Input: v=0x{0:X6}\r\n", xmfloat3pk.v);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadFloat3PK(xmfloat3pk);
            s = String.Format("Resulting vector: {0},{1},{2},{3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadFloat3SE
            Memo.AppendText("\r\nXMLoadFloat3SE\r\n");
            dmXMFLOAT3SE xmfloat3se = new dmXMFLOAT3SE(126, 300, 230, 4);
            s = String.Format("Input: v=0x{0:X6}\r\n", xmfloat3se.v);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadFloat3SE(xmfloat3se);
            s = String.Format("Resulting vector: {0},{1},{2},{3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadFloat3x3
            Memo.AppendText("\r\nXMLoadFloat3x3\r\n");
            Memo.AppendText("XMFLOAT3X3:\r\n");
            s = String.Format("m1:  {0:0.00},{1:0.00},{2:0.00}\r\n", 2.2f, -1.2f, 12.72f);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00},{1:0.00},{2:0.00}\r\n", 4.6f, -1.5f, 5.8f);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00},{1:0.00},{2:0.00}\r\n", 0.4f, -6.2f, 3.9f);
            Memo.AppendText(s);
            dmXMFLOAT3X3 inFloat3x3 = new dmXMFLOAT3X3(2.2f, -1.2f, 12.7f, 4.6f, -1.5f, 5.8f, 0.4f, -6.2f, 3.9f);
            dmXMMATRIX resMat = DMathClass.XMLoadFloat3x3(inFloat3x3);
            Memo.AppendText("Returned matrix:\r\n");
            s = String.Format("m1:  {0:0.00},{1:0.00},{2:0.00},{3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00},{1:0.00},{2:0.00},{3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00},{1:0.00},{2:0.00},{3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00},{1:0.00},{2:0.00},{3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadHalf2
            Memo.AppendText("\r\nXMLoadHalf2\r\n");
            dmXMHALF2 xmhalf2 = new dmXMHALF2(3.1f, 10.3f);
            s = String.Format("Input: x=0x{0:X} y=0x{1:X}\r\n", xmhalf2.x, xmhalf2.y);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadHalf2(xmhalf2);
            s = String.Format("Resulting vector: {0},{1},{2},{3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadHalf4
            Memo.AppendText("\r\nXMLoadHalf4\r\n");
            dmXMHALF4 xmhalf4 = new dmXMHALF4(0xA020, 0x7050, 0x1111, 0x9853);
            s = String.Format("Input: x=0x{0:X} y=0x{1:X} z=0x{2:X} w=0x{3:X}\r\n", xmhalf4.x, xmhalf4.y, xmhalf4.z, xmhalf4.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadHalf4(xmhalf4);
            s = String.Format("Resulting vector: {0},{1},{2},{3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadInt2
            Memo.AppendText("\r\nXMLoadInt2\r\n");
            s = String.Format("Input: x=0x{0:X} y=0x{1:X}\r\n", 0xB234, 0x7777);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadInt2(new uint[] { 0xB234, 0x7777 });
            s = String.Format("Resulting vector: 0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMLoadInt4
            Memo.AppendText("\r\nXMLoadInt4\r\n");
            s = String.Format("Input: x=0x{0:X} y=0x{1:X} z=0x{2:X} w=0x{3:X}\r\n", 0xB234, 0x7777, 0x3333, 0x002);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadInt4(new uint[] { 0xB234, 0x7777, 0x3333, 2 });
            s = String.Format("Resulting vector: 0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMLoadU555
            Memo.AppendText("\r\nXMLoadU555\r\n");
            dmXMU555 xmu555 = new dmXMU555(12, 3, 13, 11);
            s = String.Format("Input: v=0x{0:X6}\r\n", xmu555.v);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadU555(xmu555);
            s = String.Format("Resulting vector: {0},{1},{2},{3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMLoadUShort4
            Memo.AppendText("\r\nXMLoadUShort4\r\n");
            dmXMUSHORT4 xmushort4 = new dmXMUSHORT4(12.0f, 3.1f, 13.5f, 11.4f);
            s = String.Format("Input: v=0x{0:X6}\r\n", xmushort4.v);
            Memo.AppendText(s);
            resVect = DMathClass.XMLoadUShort4(xmushort4);
            s = String.Format("Resulting vector: {0},{1},{2},{3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
        }

        private void btVectorStore_Click(object sender, EventArgs e)
        {
            Memo.Clear();

            // XMStoreByte2
            Memo.AppendText("XMStoreByte2\r\n");
            dmXMVECTOR inVector = new dmXMVECTOR(11.1f, 3.2f, 5.1f, 1.5f);
            dmXMBYTE2 xmbyte2;// = new dmXMBYTE2();
            string s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreByte2(out xmbyte2, inVector);
            s = String.Format("dmXMBYTE2:  {0}, {1}\r\n", xmbyte2.x, xmbyte2.y);
            Memo.AppendText(s);

            // XMStoreByte4
            Memo.AppendText("\r\nXMStoreByte4\r\n");
            dmXMBYTE4 xmbyte4;// = new dmXMBYTE4();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreByte4(out xmbyte4, inVector);
            s = String.Format("dmXMBYTE4:  {0}, {1}, {2}, {3}\r\n", xmbyte4.x, xmbyte4.y, xmbyte4.z, xmbyte4.w);
            Memo.AppendText(s);

            // XMStoreByte2
            Memo.AppendText("\r\nXMStoreByteN2\r\n");
            dmXMBYTEN2 xmbyten2;// = new dmXMBYTEN2();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreByteN2(out xmbyten2, inVector);
            s = String.Format("dmXMBYTEN2:  {0}, {1}\r\n", xmbyten2.x, xmbyten2.y);
            Memo.AppendText(s);

            // XMStoreColor
            Memo.AppendText("\r\nXMStoreColor\r\n");
            dmXMVECTOR inVectorColor = new dmXMVECTOR(0.1f, 0.2f, 0.3f, 0.8f);
            dmXMCOLOR xmcolor;// = new dmXMCOLOR();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVectorColor.dmXMVECTOR_f32.x, inVectorColor.dmXMVECTOR_f32.y, inVectorColor.dmXMVECTOR_f32.z, inVectorColor.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreColor(out xmcolor, inVectorColor);
            s = String.Format("dmXMCOLOR: r:{0}, g:{1}, b:{2}, a:{3}\r\n", xmcolor.r, xmcolor.g, xmcolor.b, xmcolor.a);
            Memo.AppendText(s);

            // XMStoreFloat
            Memo.AppendText("\r\nXMStoreFloat\r\n");
            float stfloat;
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreFloat(out stfloat, inVector);
            s = String.Format("float:  {0}\r\n", stfloat);
            Memo.AppendText(s);

            // XMStoreFloat2
            Memo.AppendText("\r\nXMStoreFloat2\r\n");
            dmXMFLOAT2 xmfloat2;// = new dmXMFLOAT2();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreFloat2(out xmfloat2, inVector);
            s = String.Format("dmXMFLOAT2:  {0}, {1}\r\n", xmfloat2.x, xmfloat2.y);
            Memo.AppendText(s);

            // XMStoreFloat3
            Memo.AppendText("\r\nXMStoreFloat3\r\n");
            dmXMFLOAT3A xmfloat3a;// = new dmXMFLOAT3A();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreFloat3A(out xmfloat3a, inVector);
            s = String.Format("dmXMFLOAT2:  {0}, {1}, {2}\r\n", xmfloat3a.x, xmfloat3a.y, xmfloat3a.z);
            Memo.AppendText(s);

            // XMStoreFloat3PK
            dmXMVECTOR in3pk = new dmXMVECTOR(0x40e66666, 0x61680000, 0x4134cccd, 0);
            Memo.AppendText("\r\nXMStoreFloat3PK\r\n");
            dmXMFLOAT3PK xmfloat3pk;// = new dmXMFLOAT3PK();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", in3pk.dmXMVECTOR_f32.x, in3pk.dmXMVECTOR_f32.y, in3pk.dmXMVECTOR_f32.z, in3pk.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreFloat3PK(out xmfloat3pk, in3pk);
            uint xm, xe, ym, ye, zm, ze;
            xmfloat3pk.decomposeXMFLOAT3PK(out xm, out xe, out ym, out ye, out zm, out ze);
            s = String.Format("dmXMFLOAT3PK: v:0x{0:X}, xm:0x{1:X} xe:0x{2:X} ym:0x{3:X} ye:0x{4:X} zm:0x{5:X} ze:0x{6:X}\r\n", xmfloat3pk.v, xm, xe, ym, ye, zm, ze);
            Memo.AppendText(s);

            // XMStoreFloat3SE
            dmXMVECTOR in3se = new dmXMVECTOR(7.2f, 14.5f, 11.3f, 6.9f);
            Memo.AppendText("\r\nXMStoreFloat3SE\r\n");
            dmXMFLOAT3SE xmfloat3se;// = new dmXMFLOAT3SE();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", in3se.dmXMVECTOR_f32.x, in3se.dmXMVECTOR_f32.y, in3se.dmXMVECTOR_f32.z, in3se.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreFloat3SE(out xmfloat3se, in3se);
            uint xm3se, ym3se, zm3se, ese;
            xmfloat3se.decomposeXMFLOAT3SE(out xm3se, out ym3se, out zm3se, out ese);
            s = String.Format("dmXMFLOAT3SE: v:0x{0:X}, xm:0x{1:X} xe:0x{2:X} ym:0x{3:X} ye:0x{4:X}\r\n", xmfloat3se.v, xm3se, ym3se, zm3se, ese);
            Memo.AppendText(s);

            // XMStoreFloat3x3
            dmXMVECTOR V1 = DMathClass.XMVectorSet(3.5f, -3.0f, 0.4f, 1.5f);
            dmXMVECTOR V2 = DMathClass.XMVectorSet(4.5f, 4.0f, 1.4f, -1.5f);
            dmXMVECTOR V3 = DMathClass.XMVectorSet(2.5f, 1.0f, -1.4f, 3.1f);
            dmXMVECTOR V4 = DMathClass.XMVectorSet(1.1f, 1.7f, 3.6f, 2.7f);
            dmXMMATRIX M1 = new dmXMMATRIX(V1, V2, V3, V4);

            Memo.AppendText("\r\nXMStoreFloat3x3\r\n");
            dmXMFLOAT3X3 xmfloat3x3;// = new dmXMFLOAT3X3();
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreFloat3x3(out xmfloat3x3, M1);
            s = String.Format("dmXMFLOAT3x3: row1: {0}, {1} {2}\r\n", xmfloat3x3._11, xmfloat3x3._12, xmfloat3x3._13);
            Memo.AppendText(s);
            s = String.Format("dmXMFLOAT3x3: row2: {0}, {1} {2}\r\n", xmfloat3x3._21, xmfloat3x3._22, xmfloat3x3._23);
            Memo.AppendText(s);
            s = String.Format("dmXMFLOAT3x3: row3: {0}, {1} {2}\r\n", xmfloat3x3._31, xmfloat3x3._32, xmfloat3x3._33);
            Memo.AppendText(s);

            // XMStoreFloat4x3
            Memo.AppendText("\r\nXMStoreFloat4x3\r\n");
            dmXMFLOAT4X3 xmfloat4x3;// = new dmXMFLOAT4X3();
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreFloat4x3(out xmfloat4x3, M1);
            s = String.Format("dmXMFLOAT4x3: row1: {0}, {1} {2}\r\n", xmfloat4x3._11, xmfloat4x3._12, xmfloat4x3._13);
            Memo.AppendText(s);
            s = String.Format("dmXMFLOAT4x3: row2: {0}, {1} {2}\r\n", xmfloat4x3._21, xmfloat4x3._22, xmfloat4x3._23);
            Memo.AppendText(s);
            s = String.Format("dmXMFLOAT4x3: row3: {0}, {1} {2}\r\n", xmfloat4x3._31, xmfloat4x3._32, xmfloat4x3._33);
            Memo.AppendText(s);
            s = String.Format("dmXMFLOAT4x3: row4: {0}, {1} {2}\r\n", xmfloat4x3._41, xmfloat4x3._42, xmfloat4x3._43);
            Memo.AppendText(s);


            // XMStoreHalf2
            Memo.AppendText("\r\nXMStoreHalf2\r\n");
            dmXMHALF2 xmhalf2;// = new dmXMHALF2();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreHalf2(out xmhalf2, inVector);
            s = String.Format("dmXMFLOAT2:  {0}, {1}\r\n", xmhalf2.x, xmhalf2.y);
            Memo.AppendText(s);

            // XMStoreHalf4
            Memo.AppendText("\r\nXMStoreHalf4\r\n");
            dmXMHALF4 xmhalf4;// = new dmXMHALF4();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreHalf4(out xmhalf4, inVector);
            s = String.Format("dmXMFLOAT4:  {0}, {1}, {2}, {3}\r\n", xmhalf4.x, xmhalf4.y, xmhalf4.z, xmhalf4.w);
            Memo.AppendText(s);

            // XMStoreInt
            Memo.AppendText("\r\nXMStoreInt\r\n");
            uint stint;
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreInt(out stint, inVector);
            s = String.Format("int:  {0}\r\n", stint);
            Memo.AppendText(s);

            // XMStoreInt2
            Memo.AppendText("\r\nXMStoreInt2\r\n");
            uint[] stint2;// = new uint[2];
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreInt2(out stint2, inVector);
            s = String.Format("int:  {0}, {1}\r\n", stint2[0], stint2[1]);
            Memo.AppendText(s);

            // XMStoreInt3
            Memo.AppendText("\r\nXMStoreInt3\r\n");
            uint[] stint3;//= new uint[3];
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreInt3(out stint3, inVector);
            s = String.Format("int:  {0}, {1}, {2} \r\n", stint3[0], stint3[1], stint3[2]);
            Memo.AppendText(s);

            // XMStoreInt4
            Memo.AppendText("\r\nXMStoreInt4\r\n");
            uint[] stint4;// = new uint[4];
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreInt4(out stint4, inVector);
            s = String.Format("int:  {0}, {1}, {2}, {3} \r\n", stint4[0], stint4[1], stint4[2], stint4[3]);
            Memo.AppendText(s);

            // XMStoreShort4
            Memo.AppendText("\r\nXMStoreShort4\r\n");
            dmXMSHORT4 xmshort4;// = new dmXMSHORT4();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreShort4(out xmshort4, inVector);
            s = String.Format("dmXMSHORT4:  {0}, {1}, {2}, {3}\r\n", xmshort4.x, xmshort4.y, xmshort4.z, xmshort4.w);
            Memo.AppendText(s);

            // XMStoreSInt4
            Memo.AppendText("\r\nXMStoreSInt4\r\n");
            dmXMINT4 xmint4;// = new dmXMINT4();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreSInt4(out xmint4, inVector);
            s = String.Format("dmXMINT4:  {0}, {1}, {2}, {3}\r\n", xmint4.x, xmint4.y, xmint4.z, xmint4.w);
            Memo.AppendText(s);

            // XMStoreU555
            dmXMVECTOR inu5x5 = new dmXMVECTOR(11.1f, 3.2f, 5.1f, 1.5f);
            Memo.AppendText("\r\nXMStoreU555\r\n");
            dmXMU555 xmu555;//= new dmXMU555();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inu5x5.dmXMVECTOR_f32.x, inu5x5.dmXMVECTOR_f32.y, inu5x5.dmXMVECTOR_f32.z, inu5x5.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreU555(out xmu555, inu5x5);
            ushort x, y, z, w;
            xmu555.decomposeXMU555(out x, out y, out z, out w);
            s = String.Format("dmXMU555: v:0x{0:X}, x:{1} y:{2} z:{3} w:{4}\r\n", xmu555.v, x, y, z, w);
            Memo.AppendText(s);

            // XMStoreU565
            Memo.AppendText("\r\nXMStoreU565\r\n");
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inu5x5.dmXMVECTOR_f32.x, inu5x5.dmXMVECTOR_f32.y, inu5x5.dmXMVECTOR_f32.z, inu5x5.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMU565 xmu565;// = new dmXMU565();
            DMathClass.XMStoreU565(out xmu565, inu5x5);
            xmu565.decomposeXMU565(out x, out y, out z);
            s = String.Format("dmXMU565: v:0x{0:X}, x:{1} y:{2} z:{3}\r\n", xmu565.v, x, y, z);
            Memo.AppendText(s);

            // XMStoreUByte2
            Memo.AppendText("\r\nXMStoreUByte2\r\n");
            dmXMUBYTE2 xmubyte2;// = new dmXMUBYTE2();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreUByte2(out xmubyte2, inVector);
            s = String.Format("dmXMUBYTE2:  x={0}, y={1}\r\n", xmubyte2.x, xmubyte2.y);
            Memo.AppendText(s);

            // XMStoreUDec4
            Memo.AppendText("\r\nXMStoreUDec4\r\n");
            dmXMUDEC4 xmudec4;// = new dmXMUDEC4();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreUDec4(out xmudec4, inVector);
            uint ux, uy, uz, uw;
            xmudec4.decomposeXMUDEC4(out ux, out uy, out uz, out uw);
            s = String.Format("dmXMUDEC4 v:0x{0:X}, x:{1} y:{2} z:{3} w:{4}\r\n", xmudec4.v, ux, uy, uz, uw);
            Memo.AppendText(s);

            // XMStoreUInt4
            Memo.AppendText("\r\nXMStoreUInt4\r\n");
            dmXMUINT4 xmuint4;// = new dmXMUINT4();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreUInt4(out xmuint4, inVector);
            s = String.Format("dmXMUINT4 x:{0} y:{1} z:{2} w:{3}\r\n", xmuint4.x, xmuint4.y, xmuint4.z, xmuint4.w);
            Memo.AppendText(s);

            // XMStoreUNibble4
            Memo.AppendText("r\nXMStoreUNibble4\r\n");
            dmXMUNIBBLE4 xmunibble4;// = new dmXMUNIBBLE4();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreUNibble4(out xmunibble4, inVector);
            UInt16 nx, ny, nz, nw;
            xmunibble4.decomposeXMUNIBBLE4(out nx, out ny, out nz, out nw);
            s = String.Format("dmXMUNIBBLE4 v:0x{0:X}, x:{1} y:{2} z:{3} w:{4}\r\n", xmudec4.v, nx, ny, nz, nw);
            Memo.AppendText(s);

            // XMStoreUShort2
            Memo.AppendText("\r\nXMStoreUShort2\r\n");
            dmXMUSHORT2 xmushort2;// = new dmXMUSHORT2();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMStoreUShort2(out xmushort2, inVector);
            s = String.Format("dmXMUSHORT2 x:{0} y:{1}\r\n", xmushort2.x, xmushort2.y);
            Memo.AppendText(s);

            // XMStoreXDecN4
            Memo.AppendText("\r\nXMStoreXDecN4\r\n");
            dmXMXDECN4 xmxdecn4;// = new dmXMXDECN4();
            s = String.Format("Input vector: {0}, {1}, {2}, {3}\r\n", inVector.dmXMVECTOR_f32.x, inVector.dmXMVECTOR_f32.y, inVector.dmXMVECTOR_f32.z, inVector.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            int dx, dy, dz, dw;
            DMathClass.XMStoreXDecN4(out xmxdecn4, inVector);
            xmxdecn4.decomposeXMXDECN4(out dx, out dy, out dz, out dw);
            s = String.Format("dmXMXDECN4 x:{0} y:{1} z:{2} w:{3}\r\n", dx, dy, dz, dw);
            Memo.AppendText(s);
        }

        private void btConversion_Click(object sender, EventArgs e)
        {
            Memo.Clear();
            // XMConvertFloatToHalf
            Memo.AppendText("\r\nXMConvertFloatToHalf\r\n");
            float fFloat = 3.3f;
            string s = String.Format("Input float: {0}\r\n", fFloat);
            Memo.AppendText(s);
            HALF hHalf = DMathClass.XMConvertFloatToHalf(fFloat);
            s = String.Format("HALF:  {0}\r\n", hHalf);
            Memo.AppendText(s);

            // XMConvertFloatToHalfStream
            Memo.AppendText("\r\nXMConvertFloatToHalfStream\r\n");
            HALF[] halfarr1;// = new HALF[4];
            float[] floatarr1 = new float[4] { 1.1f, 2.2f, 3.3f, 4.4f };
            Memo.AppendText("Input floats:");
            for (int i = 0; i < floatarr1.Length; i++) { Memo.AppendText(String.Format("{0} ", floatarr1[i])); }
            DMathClass.XMConvertFloatToHalfStream(out halfarr1, sizeof(HALF), floatarr1, sizeof(float), 4);
            Memo.AppendText("\r\nOutput HALFs:");
            for (int i = 0; i < halfarr1.Length; i++) { Memo.AppendText(String.Format("{0} ", halfarr1[i])); }

            // XMConvertHalfToFloat
            Memo.AppendText("\r\n\r\nXMConvertHalfToFloat\r\n");
            hHalf = 17050;
            s = String.Format("Input HALF: {0}\r\n", hHalf);
            Memo.AppendText(s);
            fFloat = DMathClass.XMConvertHalfToFloat(hHalf);
            s = String.Format("float:  {0:0.00}\r\n", fFloat);
            Memo.AppendText(s);

            // XMConvertHalfToFloatStream
            Memo.AppendText("\r\nXMConvertHalfToFloatStream\r\n");
            float[] floatarr2;// = new float[4];
            HALF[] halfarr2 = new HALF[4] { 15462, 16486, 17050, 17510 };
            Memo.AppendText("Input HALFs:");
            for (int i = 0; i < halfarr2.Length; i++) { Memo.AppendText(String.Format("{0} ", halfarr2[i])); }
            DMathClass.XMConvertHalfToFloatStream(out floatarr2, sizeof(float), halfarr2, sizeof(HALF), 4);
            Memo.AppendText("\r\nOutput floats:");
            for (int i = 0; i < halfarr2.Length; i++) { Memo.AppendText(String.Format("{0:0.00} ", floatarr2[i])); }

            // XMConvertToDegrees
            Memo.AppendText("\r\n\r\nXMConvertToDegrees\r\n");
            float fradians = 3.0f;
            s = String.Format("Input float: {0:0.00}\r\n", fradians);
            Memo.AppendText(s);
            fFloat = DMathClass.XMConvertToDegrees(fradians);
            s = String.Format("Output float:  {0:0.00}\r\n", fFloat);
            Memo.AppendText(s);

            // XMConvertVectorFloatToInt
            dmXMVECTOR V1 = new dmXMVECTOR(3.5f, -3.0f, 0.4f, 1.5f);
            Memo.AppendText("\r\nXMConvertVectorFloatToInt\r\n");
            s = String.Format("Floats Vector:  {0}, {1}, {2}, {3} MulExponent: {4}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w, 2);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMConvertVectorFloatToInt(V1, 2);
            s = String.Format("Converted to Ints vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_i32.x, resVect.dmXMVECTOR_i32.y, resVect.dmXMVECTOR_i32.z, resVect.dmXMVECTOR_i32.w);
            Memo.AppendText(s);

            // XMConvertVectorIntToFloat

            dmXMVECTOR vItoF = new dmXMVECTOR(14, -12, 1, 6);
            Memo.AppendText("\r\nXMConvertVectorIntToFloat\r\n");
            s = String.Format("Ints Vector:  {0}, {1}, {2}, {3} DivExponent: {4}\r\n", vItoF.dmXMVECTOR_i32.x, vItoF.dmXMVECTOR_i32.y, vItoF.dmXMVECTOR_i32.z, vItoF.dmXMVECTOR_i32.w, 2);
            Memo.AppendText(s);
            resVect = DMathClass.XMConvertVectorIntToFloat(vItoF, 2);
            s = String.Format("Converted to floats vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMConvertVectorUIntToFloat
            dmXMVECTOR vUItoF = new dmXMVECTOR(14, -12, 1, 6);
            Memo.AppendText("\r\nXMConvertVectorUIntToFloat\r\n");
            s = String.Format("UInts Vector:  {0}, {1}, {2}, {3} DivExponent: {4}\r\n", vUItoF.dmXMVECTOR_u32.x, vUItoF.dmXMVECTOR_u32.y, vUItoF.dmXMVECTOR_u32.z, vUItoF.dmXMVECTOR_u32.w, 2);
            Memo.AppendText(s);
            resVect = DMathClass.XMConvertVectorUIntToFloat(vUItoF, 2);
            s = String.Format("Converted to floats vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

        }

        private void btMatrix_Click(object sender, EventArgs e)
        {
            // XMMatrixAffineTransformation
            Memo.AppendText("XMMatrixAffineTransformation:\r\n");
            dmXMVECTOR vScaling = new dmXMVECTOR(1.5f, 1.2f, 4.3f, 2.0f);
            String s = String.Format("Scaling vector:  {0}, {1}, {2}, {3}\r\n", vScaling.dmXMVECTOR_f32.x, vScaling.dmXMVECTOR_f32.y, vScaling.dmXMVECTOR_f32.z, vScaling.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR vRotationOrigin = new dmXMVECTOR(1.1f, -1.2f, 1.3f, 0.4f);
            s = String.Format("RotationOrigin vector:  {0}, {1}, {2}, {3}\r\n", vRotationOrigin.dmXMVECTOR_f32.x, vRotationOrigin.dmXMVECTOR_f32.y, vRotationOrigin.dmXMVECTOR_f32.z, vRotationOrigin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR vRotationQuaternion = new dmXMVECTOR(4.1f, -4.2f, 4.3f, 3.4f);
            s = String.Format("RotationQuaternion vector:  {0}, {1}, {2}, {3}\r\n", vRotationQuaternion.dmXMVECTOR_f32.x, vRotationQuaternion.dmXMVECTOR_f32.y, vRotationQuaternion.dmXMVECTOR_f32.z, vRotationQuaternion.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR vTranslation = new dmXMVECTOR(7.1f, 4.6f, 2.3f, 1.4f);
            s = String.Format("Translation vector:  {0}, {1}, {2}, {3}\r\n", vTranslation.dmXMVECTOR_f32.x, vTranslation.dmXMVECTOR_f32.y, vTranslation.dmXMVECTOR_f32.z, vTranslation.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMMATRIX resMat = DMathClass.XMMatrixAffineTransformation(vScaling, vRotationOrigin, vRotationQuaternion, vTranslation);
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixAffineTransformation2D
            Memo.AppendText("\r\nXMMatrixAffineTransformation2D:\r\n");
            s = String.Format("Scaling vector:  {0}, {1}, {2}, {3}\r\n", vScaling.dmXMVECTOR_f32.x, vScaling.dmXMVECTOR_f32.y, vScaling.dmXMVECTOR_f32.z, vScaling.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("RotationOrigin vector:  {0}, {1}, {2}, {3}\r\n", vRotationOrigin.dmXMVECTOR_f32.x, vRotationOrigin.dmXMVECTOR_f32.y, vRotationOrigin.dmXMVECTOR_f32.z, vRotationOrigin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float vRotation = 0.3f;
            s = String.Format("Rotation:  {0}\r\n", vRotation);
            Memo.AppendText(s);
            s = String.Format("Translation vector:  {0}, {1}, {2}, {3}\r\n", vTranslation.dmXMVECTOR_f32.x, vTranslation.dmXMVECTOR_f32.y, vTranslation.dmXMVECTOR_f32.z, vTranslation.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixAffineTransformation2D(vScaling, vRotationOrigin, vRotation, vTranslation);
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixDecompose
            dmXMVECTOR V1 = new dmXMVECTOR(110.10f, 0.20f, 0.3f, 0.4f);
            dmXMVECTOR V2 = new dmXMVECTOR(0.10f, 110.20f, 0.3f, 0.4f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.10f, 0.20f, 110.3f, 0.3f);
            dmXMVECTOR V4 = new dmXMVECTOR(0.10f, 0.20f, 0.4f, 110.5f);
            dmXMMATRIX M1 = new dmXMMATRIX(V1, V2, V3, V4);

            Memo.AppendText("\r\nXMMatrixDecompose:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            bool resBool = DMathClass.XMMatrixDecompose(out vScaling, out vRotationOrigin, out vTranslation, M1);
            if (resBool)
            {
                s = String.Format("Scaling vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", vScaling.dmXMVECTOR_f32.x, vScaling.dmXMVECTOR_f32.y, vScaling.dmXMVECTOR_f32.z, vScaling.dmXMVECTOR_f32.w);
                Memo.AppendText(s);
                s = String.Format("RotationOrigin vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", vRotationOrigin.dmXMVECTOR_f32.x, vRotationOrigin.dmXMVECTOR_f32.y, vRotationOrigin.dmXMVECTOR_f32.z, vRotationOrigin.dmXMVECTOR_f32.w);
                Memo.AppendText(s);
                s = String.Format("Translation vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", vTranslation.dmXMVECTOR_f32.x, vTranslation.dmXMVECTOR_f32.y, vTranslation.dmXMVECTOR_f32.z, vTranslation.dmXMVECTOR_f32.w);
                Memo.AppendText(s);
            }

            // XMMatrixDeterminant
            Memo.AppendText("\r\nXMMatrixDeterminant:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMMatrixDeterminant(M1);
            s = String.Format("Determinat vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixIdentity
            Memo.AppendText("\r\nXMMatrixIdentity\r\n");
            resMat = DMathClass.XMMatrixIdentity();
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixInverse
            dmXMVECTOR VInv1 = new dmXMVECTOR(1.5f, 1.2f, 4.3f, 2.0f);
            dmXMVECTOR VInv2 = new dmXMVECTOR(1.1f, -1.2f, 1.3f, 0.4f);
            dmXMVECTOR VInv3 = new dmXMVECTOR(4.1f, -4.2f, 4.3f, 3.4f);
            dmXMVECTOR VInv4 = new dmXMVECTOR(7.1f, 4.6f, 2.3f, 1.4f);
            dmXMMATRIX MInv = new dmXMMATRIX(VInv1, VInv2, VInv3, VInv4);
            Memo.AppendText("\r\nXMMatrixInverse\r\n");
            Memo.AppendText("Matrix to invert:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m1.dmXMVECTOR_f32.x, MInv.m1.dmXMVECTOR_f32.y, MInv.m1.dmXMVECTOR_f32.z, MInv.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m2.dmXMVECTOR_f32.x, MInv.m2.dmXMVECTOR_f32.y, MInv.m2.dmXMVECTOR_f32.z, MInv.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m3.dmXMVECTOR_f32.x, MInv.m3.dmXMVECTOR_f32.y, MInv.m3.dmXMVECTOR_f32.z, MInv.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m4.dmXMVECTOR_f32.x, MInv.m4.dmXMVECTOR_f32.y, MInv.m4.dmXMVECTOR_f32.z, MInv.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixInverse(out resVect, MInv);
            Memo.AppendText("Inverted Matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Determinat vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixIsInfinite
            Memo.AppendText("\r\nXMMatrixIsInfinite:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMMatrixIsInfinite(M1);
            Memo.AppendText(String.Format("Is infinit?: {0}\n", resBool));

            // XMMatrixLookAtLH
            Memo.AppendText("\r\nXMMatrixLookAtLH:\r\n");
            dmXMVECTOR EyePosition = new dmXMVECTOR(0.5f, 0.2f, 0.3f, 0.0f);
            s = String.Format("EyePosition vector:  {0}, {1}, {2}, {3}\r\n", EyePosition.dmXMVECTOR_f32.x, EyePosition.dmXMVECTOR_f32.y, EyePosition.dmXMVECTOR_f32.z, EyePosition.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR FocusPosition = new dmXMVECTOR(0.1f, 0.2f, 0.3f, 0.0f);
            s = String.Format("FocusPosition vector:  {0}, {1}, {2}, {3}\r\n", FocusPosition.dmXMVECTOR_f32.x, FocusPosition.dmXMVECTOR_f32.y, FocusPosition.dmXMVECTOR_f32.z, FocusPosition.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR UpDirection = new dmXMVECTOR(0.2f, 0.43f, 0.34f, 0.24f);
            s = String.Format("UpDirection vector:  {0}, {1}, {2}, {3}\r\n", UpDirection.dmXMVECTOR_f32.x, UpDirection.dmXMVECTOR_f32.y, UpDirection.dmXMVECTOR_f32.z, UpDirection.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixLookAtLH(EyePosition, FocusPosition, UpDirection);
            Memo.AppendText("View matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixLookToRH
            Memo.AppendText("\r\nXMMatrixLookToRH:\r\n");
            s = String.Format("EyePosition vector:  {0}, {1}, {2}, {3}\r\n", EyePosition.dmXMVECTOR_f32.x, EyePosition.dmXMVECTOR_f32.y, EyePosition.dmXMVECTOR_f32.z, EyePosition.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR EyeDirection = new dmXMVECTOR(0.1f, 0.2f, 0.3f, 0.0f);
            s = String.Format("EyeDirection vector:  {0}, {1}, {2}, {3}\r\n", EyeDirection.dmXMVECTOR_f32.x, EyeDirection.dmXMVECTOR_f32.y, EyeDirection.dmXMVECTOR_f32.z, EyeDirection.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("UpDirection vector:  {0}, {1}, {2}, {3}\r\n", UpDirection.dmXMVECTOR_f32.x, UpDirection.dmXMVECTOR_f32.y, UpDirection.dmXMVECTOR_f32.z, UpDirection.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixLookToRH(EyePosition, EyeDirection, UpDirection);
            Memo.AppendText("View matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixMultiply
            Memo.AppendText("\r\nXMMatrixMultiply\r\n");
            Memo.AppendText("First matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Second matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m1.dmXMVECTOR_f32.x, MInv.m1.dmXMVECTOR_f32.y, MInv.m1.dmXMVECTOR_f32.z, MInv.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m2.dmXMVECTOR_f32.x, MInv.m2.dmXMVECTOR_f32.y, MInv.m2.dmXMVECTOR_f32.z, MInv.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m3.dmXMVECTOR_f32.x, MInv.m3.dmXMVECTOR_f32.y, MInv.m3.dmXMVECTOR_f32.z, MInv.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m4.dmXMVECTOR_f32.x, MInv.m4.dmXMVECTOR_f32.y, MInv.m4.dmXMVECTOR_f32.z, MInv.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixMultiply(M1, MInv);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixMultiply
            Memo.AppendText("\r\nXMMatrixMultiplyTranspose\r\n");
            Memo.AppendText("First matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Second matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m1.dmXMVECTOR_f32.x, MInv.m1.dmXMVECTOR_f32.y, MInv.m1.dmXMVECTOR_f32.z, MInv.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m2.dmXMVECTOR_f32.x, MInv.m2.dmXMVECTOR_f32.y, MInv.m2.dmXMVECTOR_f32.z, MInv.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m3.dmXMVECTOR_f32.x, MInv.m3.dmXMVECTOR_f32.y, MInv.m3.dmXMVECTOR_f32.z, MInv.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", MInv.m4.dmXMVECTOR_f32.x, MInv.m4.dmXMVECTOR_f32.y, MInv.m4.dmXMVECTOR_f32.z, MInv.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixMultiplyTranspose(M1, MInv);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixOrthographicLH
            Memo.AppendText("\r\nXMMatrixOrthographicLH\r\n");
            float ViewWidth = 600.0f;
            float ViewHeight = 300.0f;
            float NearZ = 0.1f;
            float FarZ = 0.9f;
            s = String.Format("ViewWidth={0:0.00}, ViewHeight={1:0.00}, NearZ={2:0.00}, FarZ={3:0.00}\r\n", ViewWidth, ViewHeight, NearZ, FarZ);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixOrthographicLH(ViewWidth, ViewHeight, NearZ, FarZ);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixOrthographicOffCenterLH
            Memo.AppendText("\r\nXMMatrixOrthographicOffCenterLH\r\n");
            float ViewLeft = 0.0f;
            float ViewRigth = 600.0f;
            float ViewBottom = 0.0f;
            float ViewTop = 10.0f;
            s = String.Format("ViewLeft={0:0.00}, ViewRight={1:0.00}, ViewBottom={2:0.00}, ViewTop={3:0.00}, NearZ={4:0.00} FarZ={5:0.00} \r\n", ViewLeft, ViewRigth, ViewBottom, ViewTop, NearZ, FarZ);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixOrthographicOffCenterLH(ViewLeft, ViewRigth, ViewBottom, ViewTop, NearZ, FarZ);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixPerspectiveFovLH
            Memo.AppendText("\r\nXMMatrixPerspectiveFovLH\r\n");
            float FovAngleY = 1.1f;
            float AspectHByW = 1.2f;
            s = String.Format("FovAngleY={0:0.00}, AspectHByW={1:0.00}, NearZ={2:0.00} FarZ={3:0.00} \r\n", FovAngleY, AspectHByW, NearZ, FarZ);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixPerspectiveFovLH(FovAngleY, AspectHByW, NearZ, FarZ);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixReflect
            Memo.AppendText("\r\nXMMatrixReflect:\r\n");
            dmXMVECTOR ReflectionPlane = new dmXMVECTOR(0.5f, 0.2f, 0.3f, 0.0f);
            s = String.Format("Reflection Plane:  {0}, {1}, {2}, {3}\r\n", ReflectionPlane.dmXMVECTOR_f32.x, ReflectionPlane.dmXMVECTOR_f32.y, ReflectionPlane.dmXMVECTOR_f32.z, ReflectionPlane.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixReflect(ReflectionPlane);
            Memo.AppendText("View matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixRotationNormal
            Memo.AppendText("\r\nXMMatrixRotationNormal:\r\n");
            dmXMVECTOR NormalAxis = new dmXMVECTOR(0.5f, 0.2f, 0.3f, 0.0f);
            float nAngle = 0.6f;
            s = String.Format("Normal Axis:  {0}, {1}, {2}, {3} Angle: {4}\r\n", NormalAxis.dmXMVECTOR_f32.x, NormalAxis.dmXMVECTOR_f32.y, NormalAxis.dmXMVECTOR_f32.z, NormalAxis.dmXMVECTOR_f32.w, nAngle);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixRotationNormal(NormalAxis, nAngle);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixRotationQuaternion
            Memo.AppendText("\r\nXMMatrixRotationQuaternion:\r\n");
            dmXMVECTOR Quaternion = new dmXMVECTOR(0.5f, 0.2f, 0.3f, 0.0f);
            s = String.Format("Quaternion:  {0}, {1}, {2}, {3}\r\n", Quaternion.dmXMVECTOR_f32.x, Quaternion.dmXMVECTOR_f32.y, Quaternion.dmXMVECTOR_f32.z, Quaternion.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixRotationQuaternion(Quaternion);
            Memo.AppendText("Resultin matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixRotationRollPitchYaw
            Memo.AppendText("\r\nXMMatrixRotationRollPitchYaw\r\n");
            float Pitch = 1.1f;
            float Yaw = 1.2f;
            float Roll = 0.3f;
            s = String.Format("Pitch={0:0.00}, Yaw={1:0.00}, Roll={2:0.00}\r\n", Pitch, Yaw, Roll);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixRotationRollPitchYaw(Pitch, Yaw, Roll);
            Memo.AppendText("Rotation matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixRotationY
            Memo.AppendText("\r\nXMMatrixRotationY\r\n");
            float Angle = 1.1f;
            s = String.Format("Angle={0:0.00}\r\n", Angle);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixRotationY(Angle);
            Memo.AppendText("Rotation matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixScalingFromVector
            Memo.AppendText("\r\nXMMatrixScalingFromVector:\r\n");
            dmXMVECTOR Scale = new dmXMVECTOR(1.5f, 3.0f, 4.3f, -1.1f);
            s = String.Format("Scale:  {0}, {1}, {2}, {3}\r\n", Scale.dmXMVECTOR_f32.x, Scale.dmXMVECTOR_f32.y, Scale.dmXMVECTOR_f32.z, Scale.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixScalingFromVector(Scale);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixShadow
            Memo.AppendText("\r\nXMMatrixShadow:\r\n");
            dmXMVECTOR ShadowPlane = new dmXMVECTOR(1.5f, 3.0f, 4.3f, 0.0f);
            s = String.Format("ShadowPlane:  {0}, {1}, {2}, {3}\r\n", ShadowPlane.dmXMVECTOR_f32.x, ShadowPlane.dmXMVECTOR_f32.y, ShadowPlane.dmXMVECTOR_f32.z, ShadowPlane.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR LightPosition = new dmXMVECTOR(0.5f, 0.0f, 0.3f, 0.0f);
            s = String.Format("LightPosition:  {0}, {1}, {2}, {3}\r\n", LightPosition.dmXMVECTOR_f32.x, LightPosition.dmXMVECTOR_f32.y, LightPosition.dmXMVECTOR_f32.z, LightPosition.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixShadow(ShadowPlane, LightPosition);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixTransformation
            Memo.AppendText("\r\nXMMatrixTransformation:\r\n");
            dmXMVECTOR ScalingOrigin = new dmXMVECTOR(0.5f, 0.2f, 0.3f, 0.0f);
            s = String.Format("ScalingOrigin:  {0}, {1}, {2}, {3}\r\n", ScalingOrigin.dmXMVECTOR_f32.x, ScalingOrigin.dmXMVECTOR_f32.y, ScalingOrigin.dmXMVECTOR_f32.z, ScalingOrigin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR ScalingOrientationQuaternion = new dmXMVECTOR(1.1f, -1.2f, 1.3f, 0.4f);
            s = String.Format("ScalingOrientationQuaternion:  {0}, {1}, {2}, {3}\r\n", ScalingOrientationQuaternion.dmXMVECTOR_f32.x, ScalingOrientationQuaternion.dmXMVECTOR_f32.y, ScalingOrientationQuaternion.dmXMVECTOR_f32.z, ScalingOrientationQuaternion.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR Scaling = new dmXMVECTOR(4.1f, -4.2f, 4.3f, 3.4f);
            s = String.Format("Scaling:  {0}, {1}, {2}, {3}\r\n", Scaling.dmXMVECTOR_f32.x, Scaling.dmXMVECTOR_f32.y, Scaling.dmXMVECTOR_f32.z, Scaling.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR RotationOrigin = new dmXMVECTOR(7.1f, 4.6f, 2.3f, 1.4f);
            s = String.Format("RotationOrigin:  {0}, {1}, {2}, {3}\r\n", RotationOrigin.dmXMVECTOR_f32.x, RotationOrigin.dmXMVECTOR_f32.y, RotationOrigin.dmXMVECTOR_f32.z, RotationOrigin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR RotationQuaternion = new dmXMVECTOR(-2.0f, 2.43f, 3.7f, 1.6f);
            s = String.Format("RotationQuaternion:  {0}, {1}, {2}, {3}\r\n", RotationQuaternion.dmXMVECTOR_f32.x, RotationQuaternion.dmXMVECTOR_f32.y, RotationQuaternion.dmXMVECTOR_f32.z, RotationQuaternion.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR Translation = new dmXMVECTOR(6.2f, 5.4f, 2.03f, 2.99f);
            s = String.Format("Translation:  {0}, {1}, {2}, {3}\r\n", Translation.dmXMVECTOR_f32.x, Translation.dmXMVECTOR_f32.y, Translation.dmXMVECTOR_f32.z, Translation.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            resMat = DMathClass.XMMatrixTransformation(ScalingOrigin, ScalingOrientationQuaternion, Scaling, RotationOrigin, RotationQuaternion, Translation);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixTransformation2D
            Memo.AppendText("\r\nXMMatrixTransformation2D:\r\n");
            s = String.Format("ScalingOrigin:  {0}, {1}, {2}, {3}\r\n", ScalingOrigin.dmXMVECTOR_f32.x, ScalingOrigin.dmXMVECTOR_f32.y, ScalingOrigin.dmXMVECTOR_f32.z, ScalingOrigin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float ScalingOrientation = 0.3f;
            s = String.Format("ScalingOrientation:  {0}\r\n", ScalingOrientation);
            Memo.AppendText(s);
            s = String.Format("Scaling:  {0}, {1}, {2}, {3}\r\n", Scaling.dmXMVECTOR_f32.x, Scaling.dmXMVECTOR_f32.y, Scaling.dmXMVECTOR_f32.z, Scaling.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("RotationOrigin:  {0}, {1}, {2}, {3}\r\n", RotationOrigin.dmXMVECTOR_f32.x, RotationOrigin.dmXMVECTOR_f32.y, RotationOrigin.dmXMVECTOR_f32.z, RotationOrigin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float Rotation = 0.4f;
            s = String.Format("Rotation:  {0}\r\n", Rotation);
            Memo.AppendText(s);
            s = String.Format("Translation:  {0}, {1}, {2}, {3}\r\n", Translation.dmXMVECTOR_f32.x, Translation.dmXMVECTOR_f32.y, Translation.dmXMVECTOR_f32.z, Translation.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixTransformation2D(ScalingOrigin, ScalingOrientation, Scaling, RotationOrigin, Rotation, Translation);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            resMat = DMathClass.XMMatrixTransformation(ScalingOrigin, ScalingOrientationQuaternion, Scaling, RotationOrigin, RotationQuaternion, Translation);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixTranslationFromVector
            Memo.AppendText("\r\nXMMatrixTranslationFromVector:\r\n");
            dmXMVECTOR Offset = new dmXMVECTOR(0.5f, 0.2f, 0.3f, 0.0f);
            s = String.Format("Offset:  {0}, {1}, {2}, {3}\r\n", Offset.dmXMVECTOR_f32.x, Offset.dmXMVECTOR_f32.y, Offset.dmXMVECTOR_f32.z, Offset.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixTranslationFromVector(Offset);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMMatrixTranspose
            Memo.AppendText("\r\nXMMatrixTranspose:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resMat = DMathClass.XMMatrixTranspose(M1);
            Memo.AppendText("Resulting matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m1.dmXMVECTOR_f32.x, resMat.m1.dmXMVECTOR_f32.y, resMat.m1.dmXMVECTOR_f32.z, resMat.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m2.dmXMVECTOR_f32.x, resMat.m2.dmXMVECTOR_f32.y, resMat.m2.dmXMVECTOR_f32.z, resMat.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m3.dmXMVECTOR_f32.x, resMat.m3.dmXMVECTOR_f32.y, resMat.m3.dmXMVECTOR_f32.z, resMat.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resMat.m4.dmXMVECTOR_f32.x, resMat.m4.dmXMVECTOR_f32.y, resMat.m4.dmXMVECTOR_f32.z, resMat.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
        }

        private void btPlane_Click(object sender, EventArgs e)
        {
            Memo.Clear();

            dmXMVECTOR V1 = new dmXMVECTOR(3.5f, 0.2f, 0.3f, 1.0f);
            dmXMVECTOR V2 = new dmXMVECTOR(2.3f, -0.1f, 3.4f, 2.0f);
            dmXMVECTOR V3 = new dmXMVECTOR(1.4f, 2.7f, 4.1f, -3.1f);
            dmXMVECTOR V4 = new dmXMVECTOR(1.8f, 1.6f, 2.2f, 0.2f);
            dmXMMATRIX M1 = new dmXMMATRIX(V1, V2, V3, V4);

            // XMPlaneDotCoord
            Memo.AppendText("\r\nXMPlaneDotCoord:\r\n");
            string s = String.Format("P:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMPlaneDotCoord(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMPlaneDotNormal
            Memo.AppendText("\r\nXMPlaneDotNormal:\r\n");
            s = String.Format("P:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMPlaneDotNormal(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMPlaneEqual
            Memo.AppendText("\r\nXMPlaneEqual:\r\n");
            s = String.Format("P:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMPlaneEqual(V1, V2);
            s = String.Format("Are equal? :  {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMPlaneFromPointNormal
            Memo.AppendText("\r\nXMPlaneFromPointNormal:\r\n");
            s = String.Format("Point:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMPlaneFromPointNormal(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMPlaneFromPoints
            Memo.AppendText("\r\nXMPlaneFromPoints:\r\n");
            s = String.Format("Point1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Point2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Point3:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMPlaneFromPoints(V1, V2, V3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMPlaneIntersectLine
            Memo.AppendText("\r\nXMPlaneIntersectLine:\r\n");
            s = String.Format("P:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("LinePoint1:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("LinePoint2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMPlaneIntersectLine(V1, V2, V3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMPlaneIntersectPlane
            dmXMVECTOR pLinePoint1;// = new dmXMVECTOR();
            dmXMVECTOR pLinePoint2;// = new dmXMVECTOR();
            Memo.AppendText("XMPlaneIntersectPlane:\r\n");
            s = String.Format("P1: {0},{1},{2},{3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("P2: {0},{1},{2},{3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMPlaneIntersectPlane(out pLinePoint1, out pLinePoint2, V1, V2);
            s = String.Format("LinePoint1:  {0},{1},{2},{3}\r\n", pLinePoint1.dmXMVECTOR_f32.x, pLinePoint1.dmXMVECTOR_f32.y, pLinePoint1.dmXMVECTOR_f32.z, pLinePoint1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("LinePoint2:  {0},{1},{2},{3}\r\n", pLinePoint2.dmXMVECTOR_f32.x, pLinePoint2.dmXMVECTOR_f32.y, pLinePoint2.dmXMVECTOR_f32.z, pLinePoint2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMPlaneNearEqual
            dmXMVECTOR C1 = new dmXMVECTOR(3.5f, 0.2f, 3.3f, 4.0f);
            dmXMVECTOR C2 = new dmXMVECTOR(3.4f, 0.1f, 3.1f, 3.85f);
            dmXMVECTOR Epsilon = new dmXMVECTOR(0.2f, 0.2f, 0.2f, 0.2f);
            Memo.AppendText("\r\nXMPlaneNearEqual:\r\n");
            s = String.Format("P1:  {0}, {1}, {2}, {3}\r\n", C1.dmXMVECTOR_f32.x, C1.dmXMVECTOR_f32.y, C1.dmXMVECTOR_f32.z, C1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("P2:  {0}, {1}, {2}, {3}\r\n", C2.dmXMVECTOR_f32.x, C2.dmXMVECTOR_f32.y, C2.dmXMVECTOR_f32.z, C2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Epsilon:  {0}, {1}, {2}, {3}\r\n", Epsilon.dmXMVECTOR_f32.x, Epsilon.dmXMVECTOR_f32.y, Epsilon.dmXMVECTOR_f32.z, Epsilon.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMPlaneNearEqual(C1, C2, Epsilon);
            s = String.Format("Near equal? :  {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMPlaneNormalize
            Memo.AppendText("\r\nXMPlaneNormalize:\r\n");
            s = String.Format("P:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMPlaneNormalize(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMPlaneNotEqual
            Memo.AppendText("\r\nXMPlaneNotEqual:\r\n");
            s = String.Format("P1:  {0}, {1}, {2}, {3}\r\n", C1.dmXMVECTOR_f32.x, C1.dmXMVECTOR_f32.y, C1.dmXMVECTOR_f32.z, C1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("P2:  {0}, {1}, {2}, {3}\r\n", C2.dmXMVECTOR_f32.x, C2.dmXMVECTOR_f32.y, C2.dmXMVECTOR_f32.z, C2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMPlaneNotEqual(C1, C2);
            s = String.Format("Not equal? :  {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMPlaneTransform
            Memo.AppendText("\r\nXMPlaneTransform:\r\n");
            s = String.Format("Plane coefficents:  {0}, {1}, {2}, {3}\r\n", C1.dmXMVECTOR_f32.x, C1.dmXMVECTOR_f32.y, C1.dmXMVECTOR_f32.z, C1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Transformation Matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMPlaneTransform(C1, M1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMPlaneTransformStream
            Memo.AppendText("\r\nXMPlaneTransformStream\r\n");
            dmXMFLOAT4[] outfloat4arr;// = new dmXMFLOAT4[4];
            /*
            outfloat4arr[0] = new dmXMFLOAT4();
            outfloat4arr[1] = new dmXMFLOAT4();
            outfloat4arr[2] = new dmXMFLOAT4();
            outfloat4arr[3] = new dmXMFLOAT4();
            */
            dmXMFLOAT4[] infloat4arr = new dmXMFLOAT4[4];
            infloat4arr[0] = new dmXMFLOAT4(1.2f, 1.3f, 1.4f, 1.5f);
            infloat4arr[1] = new dmXMFLOAT4(3.5f, 0.2f, 3.3f, 4.0f);
            infloat4arr[2] = new dmXMFLOAT4(0.2f, -4.2f, 1.7f, 4.5f);
            infloat4arr[3] = new dmXMFLOAT4(-1.5f, 2.8f, 4.2f, 5.9f);
            Memo.AppendText("Input dmXMFLOAT4s:\r\n");
            for (int i = 0; i < infloat4arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT4 {0}: {1}, {2}, {3}, {4}\r\n", i, infloat4arr[i].x, infloat4arr[i].y, infloat4arr[i].z, infloat4arr[i].w));
            }
            int float4size = Marshal.SizeOf(infloat4arr.GetValue(0));
            DMathClass.XMPlaneTransformStream(out outfloat4arr, float4size, infloat4arr, float4size, 4, M1);
            Memo.AppendText("Output dmXMFLOAT4s:\r\n");
            for (int i = 0; i < outfloat4arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT4 {0}: {1}, {2}, {3}, {4}\r\n", i, outfloat4arr[i].x, outfloat4arr[i].y, outfloat4arr[i].z, outfloat4arr[i].w));
            }

        }

        private void btQuaternion_Click(object sender, EventArgs e)
        {
            Memo.Clear();

            dmXMVECTOR V1 = new dmXMVECTOR(3.5f, 0.2f, 0.3f, 1.1f);
            dmXMVECTOR V2 = new dmXMVECTOR(2.3f, -0.1f, 3.4f, 2.0f);
            dmXMVECTOR V3 = new dmXMVECTOR(1.4f, 2.7f, 4.1f, -3.1f);
            dmXMVECTOR V4 = new dmXMVECTOR(1.8f, 1.6f, 2.2f, 0.2f);
            dmXMVECTOR V5 = new dmXMVECTOR(2.2f, 1.8f, 4.3f, 1.6f);
            dmXMMATRIX M1 = new dmXMMATRIX(V1, V2, V3, V4);
            dmXMVECTOR intQuat1 = DMathClass.XMQuaternionNormalize(V1);
            dmXMVECTOR intQuat2 = DMathClass.XMQuaternionNormalize(V2);
            dmXMVECTOR intQuat3 = DMathClass.XMQuaternionNormalize(V3);
            dmXMVECTOR intQuat4 = DMathClass.XMQuaternionNormalize(V4);


            // XMQuaternionBaryCentric
            float f = 0.4f;
            float g = 0.6f;
            Memo.AppendText("XMQuaternionBaryCentric:\r\n");
            string s = String.Format("Q0:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q1:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Weighting factors: f={0}, g={1}\r\n", f, g);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMQuaternionBaryCentric(V1, V2, V3, f, g);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionBaryCentricV
            Memo.AppendText("\r\nXMQuaternionBaryCentricV:\r\n");
            dmXMVECTOR QB1 = new dmXMVECTOR(1.8f, 1.8f, 1.8f, 1.8f); // Required the same values across
            dmXMVECTOR QB2 = new dmXMVECTOR(2.2f, 2.2f, 2.2f, 2.2f); // Required the same values across
            s = String.Format("Q0:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q1:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("F:  {0}, {1}, {2}, {3}\r\n", QB1.dmXMVECTOR_f32.x, QB1.dmXMVECTOR_f32.y, QB1.dmXMVECTOR_f32.z, QB1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("G:  {0}, {1}, {2}, {3}\r\n", QB2.dmXMVECTOR_f32.x, QB2.dmXMVECTOR_f32.y, QB2.dmXMVECTOR_f32.z, QB2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionBaryCentricV(V1, V2, V3, QB1, QB2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionConjugate
            Memo.AppendText("\r\nXMQuaternionConjugate:\r\n");
            s = String.Format("Q:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionConjugate(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionDot
            Memo.AppendText("\r\nXMQuaternionDot:\r\n");
            s = String.Format("Q1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionDot(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionEqual
            Memo.AppendText("\r\nXMQuaternionEqual:\r\n");
            s = String.Format("Q1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMQuaternionEqual(V1, V2);
            s = String.Format("Are equal? :  {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMQuaternionExp
            Memo.AppendText("\r\nXMQuaternionExp:\r\n");
            s = String.Format("Q:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionExp(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionIdentity
            Memo.AppendText("\r\nXMQuaternionIdentity:\r\n");
            resVect = DMathClass.XMQuaternionIdentity();
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionInverse
            Memo.AppendText("\r\nXMQuaternionInverse:\r\n");
            s = String.Format("Q:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionInverse(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMXMQuaternionLength
            Memo.AppendText("\r\nXMQuaternionLength:\r\n");
            s = String.Format("Q:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionLength(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionLengthSq
            Memo.AppendText("\r\nXMQuaternionLengthSq:\r\n");
            s = String.Format("Q:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionLengthSq(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionLn
            Memo.AppendText("\r\nXMQuaternionLn:\r\n");
            s = String.Format("Q:  {0}, {1}, {2}, {3}\r\n", intQuat1.dmXMVECTOR_f32.x, intQuat1.dmXMVECTOR_f32.y, intQuat1.dmXMVECTOR_f32.z, intQuat1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionLn(intQuat1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionMultiply
            Memo.AppendText("\r\nXMQuaternionMultiply:\r\n");
            s = String.Format("Q1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionMultiply(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionNormalize
            Memo.AppendText("\r\nXMQuaternionNormalize:\r\n");
            s = String.Format("Q:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionNormalize(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionReciprocalLength
            Memo.AppendText("\r\nXMQuaternionReciprocalLength:\r\n");
            s = String.Format("Q:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionReciprocalLength(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionRotationAxis
            float rotAngle = 0.7f;
            Memo.AppendText("\r\nXMQuaternionRotationAxis:\r\n");
            s = String.Format("Axis:  {0}, {1}, {2}, {3} Angle: {4}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w, rotAngle);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionRotationAxis(V1, rotAngle);
            s = String.Format("Rotation quaternion:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionRotationMatrix
            Memo.AppendText("\r\nXMQuaternionRotationMatrix\r\n");
            Memo.AppendText("Rotation matrix:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionRotationMatrix(M1);
            s = String.Format("Rotation quaternion:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionRotationNormal
            Memo.AppendText("\r\nXMQuaternionRotationNormal:\r\n");
            s = String.Format("Axis:  {0}, {1}, {2}, {3} Angle: {4}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w, rotAngle);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionRotationNormal(V1, rotAngle);
            s = String.Format("Rotation quaternion:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionRotationRollPitchYaw
            Memo.AppendText("\r\nXMQuaternionRotationRollPitchYaw\r\n");
            float Pitch = 1.1f;
            float Yaw = 1.2f;
            float Roll = 0.3f;
            s = String.Format("Pitch={0:0.00}, Yaw={1:0.00}, Roll={2:0.00}\r\n", Pitch, Yaw, Roll);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionRotationRollPitchYaw(Pitch, Yaw, Roll);
            s = String.Format("Rotation quaternion:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionRotationRollPitchYawFromVector
            Memo.AppendText("\r\nXMQuaternionRotationRollPitchYawFromVector:\r\n");
            s = String.Format("Euler Angles:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionRotationRollPitchYawFromVector(V1);
            s = String.Format("Rotation quaternion:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionSlerp
            float controlFactor = 0.3f;
            Memo.AppendText("\r\nXMQuaternionSlerp:\r\n");
            s = String.Format("Q0:  {0}, {1}, {2}, {3}\r\n", intQuat1.dmXMVECTOR_f32.x, intQuat1.dmXMVECTOR_f32.y, intQuat1.dmXMVECTOR_f32.z, intQuat1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q1:  {0}, {1}, {2}, {3} Control Factor: {4}\r\n", intQuat2.dmXMVECTOR_f32.x, intQuat2.dmXMVECTOR_f32.y, intQuat2.dmXMVECTOR_f32.z, intQuat2.dmXMVECTOR_f32.w, controlFactor);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionSlerp(intQuat1, intQuat2, controlFactor);
            s = String.Format("Interpolated quaternion:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionSlerpV
            dmXMVECTOR tV = new dmXMVECTOR(0.3f, 0.3f, 0.3f, 0.3f); // All component values must be the same.
            Memo.AppendText("\r\nXMQuaternionSlerp:\r\n");
            s = String.Format("Q0:  {0}, {1}, {2}, {3}\r\n", intQuat1.dmXMVECTOR_f32.x, intQuat1.dmXMVECTOR_f32.y, intQuat1.dmXMVECTOR_f32.z, intQuat1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q1:  {0}, {1}, {2}, {3}\r\n", intQuat2.dmXMVECTOR_f32.x, intQuat2.dmXMVECTOR_f32.y, intQuat2.dmXMVECTOR_f32.z, intQuat2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("t:  {0}, {1}, {2}, {3}\r\n", tV.dmXMVECTOR_f32.x, tV.dmXMVECTOR_f32.y, tV.dmXMVECTOR_f32.z, tV.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMQuaternionSlerpV(intQuat1, intQuat2, tV);
            s = String.Format("Interpolated quaternion:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionSquad
            Memo.AppendText("\r\nXMQuaternionSquad, control factor 0.3\r\n");
            s = String.Format("First quaternion:  {0}, {1}, {2}, {3}\r\n", intQuat1.dmXMVECTOR_f32.x, intQuat1.dmXMVECTOR_f32.y, intQuat1.dmXMVECTOR_f32.z, intQuat1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Second quaternion:  {0}, {1}, {2}, {3}\r\n", intQuat2.dmXMVECTOR_f32.x, intQuat2.dmXMVECTOR_f32.y, intQuat2.dmXMVECTOR_f32.z, intQuat2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Third quaternion:  {0}, {1}, {2}, {3}\r\n", intQuat3.dmXMVECTOR_f32.x, intQuat3.dmXMVECTOR_f32.y, intQuat3.dmXMVECTOR_f32.z, intQuat3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Fourth quaternion:  {0}, {1}, {2}, {3}\r\n", intQuat4.dmXMVECTOR_f32.x, intQuat4.dmXMVECTOR_f32.y, intQuat4.dmXMVECTOR_f32.z, intQuat4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR quartSquad = DMathClass.XMQuaternionSquad(intQuat1, intQuat2, intQuat3, intQuat4, 0.3f);
            s = String.Format("Interpolated quaternion:  {0}, {1}, {2}, {3}\r\n", quartSquad.dmXMVECTOR_f32.x, quartSquad.dmXMVECTOR_f32.y, quartSquad.dmXMVECTOR_f32.z, quartSquad.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionSquadSetup
            dmXMVECTOR pA; //= new dmXMVECTOR();
            dmXMVECTOR pB; //= new dmXMVECTOR();
            dmXMVECTOR pC; // = new dmXMVECTOR();
            Memo.AppendText("\r\nXMQuaternionSquadSetup\r\n");
            Memo.AppendText("Input:\r\n");
            s = String.Format("Q0: {0}, {1}, {2}, {3}\r\n", intQuat1.dmXMVECTOR_f32.x, intQuat1.dmXMVECTOR_f32.y, intQuat1.dmXMVECTOR_f32.z, intQuat1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q1:  {0}, {1}, {2}, {3}\r\n", intQuat2.dmXMVECTOR_f32.x, intQuat2.dmXMVECTOR_f32.y, intQuat2.dmXMVECTOR_f32.z, intQuat2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q2:  {0}, {1}, {2}, {3}\r\n", intQuat3.dmXMVECTOR_f32.x, intQuat3.dmXMVECTOR_f32.y, intQuat3.dmXMVECTOR_f32.z, intQuat3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Q3:  {0}, {1}, {2}, {3}\r\n", intQuat4.dmXMVECTOR_f32.x, intQuat4.dmXMVECTOR_f32.y, intQuat4.dmXMVECTOR_f32.z, intQuat4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMQuaternionSquadSetup(out pA, out pB, out pC, intQuat1, intQuat2, intQuat3, intQuat4);
            Memo.AppendText("Outputed Setup Quaternions:\r\n");
            s = String.Format("pA:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", pA.dmXMVECTOR_f32.x, pA.dmXMVECTOR_f32.y, pA.dmXMVECTOR_f32.z, pA.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("pB:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", pB.dmXMVECTOR_f32.x, pB.dmXMVECTOR_f32.y, pB.dmXMVECTOR_f32.z, pB.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("pC:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", pC.dmXMVECTOR_f32.x, pC.dmXMVECTOR_f32.y, pC.dmXMVECTOR_f32.z, pC.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionSquadV
            Memo.AppendText("\r\nXMQuaternionSquadV\r\n");
            s = String.Format("First quaternion:  {0}, {1}, {2}, {3}\r\n", intQuat1.dmXMVECTOR_f32.x, intQuat1.dmXMVECTOR_f32.y, intQuat1.dmXMVECTOR_f32.z, intQuat1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Second quaternion:  {0}, {1}, {2}, {3}\r\n", intQuat2.dmXMVECTOR_f32.x, intQuat2.dmXMVECTOR_f32.y, intQuat2.dmXMVECTOR_f32.z, intQuat2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Third quaternion:  {0}, {1}, {2}, {3}\r\n", intQuat3.dmXMVECTOR_f32.x, intQuat3.dmXMVECTOR_f32.y, intQuat3.dmXMVECTOR_f32.z, intQuat3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Fourth quaternion:  {0}, {1}, {2}, {3}\r\n", intQuat4.dmXMVECTOR_f32.x, intQuat4.dmXMVECTOR_f32.y, intQuat4.dmXMVECTOR_f32.z, intQuat4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR iV = new dmXMVECTOR(0.3f, 0.3f, 0.3f, 0.3f); // All component values must be the same.
            s = String.Format("Interpolation vector:  {0}, {1}, {2}, {3}\r\n", iV.dmXMVECTOR_f32.x, iV.dmXMVECTOR_f32.y, iV.dmXMVECTOR_f32.z, iV.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            quartSquad = DMathClass.XMQuaternionSquadV(intQuat1, intQuat2, intQuat3, intQuat4, iV);
            s = String.Format("Interpolated quaternion:  {0}, {1}, {2}, {3}\r\n", quartSquad.dmXMVECTOR_f32.x, quartSquad.dmXMVECTOR_f32.y, quartSquad.dmXMVECTOR_f32.z, quartSquad.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMQuaternionToAxisAngle
            dmXMVECTOR pAxis;// = new dmXMVECTOR();
            float pAngle;
            Memo.AppendText("\r\nXMQuaternionToAxisAngle\r\n");
            s = String.Format("Q0: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMQuaternionToAxisAngle(out pAxis, out pAngle, V1);
            Memo.AppendText("Output:\r\n");
            s = String.Format("pAxis:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", pAxis.dmXMVECTOR_f32.x, pAxis.dmXMVECTOR_f32.y, pAxis.dmXMVECTOR_f32.z, pAxis.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("pAngle:  {0:0.00}\r\n", pAngle);
            Memo.AppendText(s);
        }

        private void btScalar_Click(object sender, EventArgs e)
        {
            Memo.Clear();
            float Value1 = 0.3f; // For Arc function - Must be between -1.0f and 1.0f
            float Value2 = 2.1f;
            float Value3 = 9.5f;
            float Value4 = 9.48f;
            float Epsilon = 0.05f;

            // XMScalarACos
            Memo.AppendText("\r\nXMScalarACos\r\n");
            String s = String.Format("Input: {0}\r\n", Value1);
            Memo.AppendText(s);
            float result = DMathClass.XMScalarACos(Value1);
            s = String.Format("Output:  {0}\r\n", result);
            Memo.AppendText(s);

            // XMScalarASin
            Memo.AppendText("\r\nXMScalarASin\r\n");
            s = String.Format("Input: {0}\r\n", Value1);
            Memo.AppendText(s);
            result = DMathClass.XMScalarASin(Value1);
            s = String.Format("Output:  {0}\r\n", result);
            Memo.AppendText(s);

            // XMScalarCos
            Memo.AppendText("\r\nXMScalarCos\r\n");
            s = String.Format("Input: {0}\r\n", Value2);
            Memo.AppendText(s);
            result = DMathClass.XMScalarCos(Value2);
            s = String.Format("Output:  {0}\r\n", result);
            Memo.AppendText(s);

            // XMScalarModAngle
            Memo.AppendText("\r\nXMScalarModAngle\r\n");
            s = String.Format("Input: {0}\r\n", Value3);
            Memo.AppendText(s);
            result = DMathClass.XMScalarModAngle(Value3);
            s = String.Format("Output:  {0}\r\n", result);
            Memo.AppendText(s);

            // XMScalarNearEqual
            Memo.AppendText("\r\nXMScalarNearEqual\r\n");
            s = String.Format("Value1: {0}, Value2: {1}, Epsilon: {2}\r\n", Value3, Value4, Epsilon);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMScalarNearEqual(Value3, Value4, Epsilon);
            s = String.Format("Near equal?:  {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMScalarSin
            Memo.AppendText("\r\nXMScalarSin\r\n");
            s = String.Format("Input: {0}\r\n", Value2);
            Memo.AppendText(s);
            result = DMathClass.XMScalarSin(Value2);
            s = String.Format("Output:  {0}\r\n", result);
            Memo.AppendText(s);

            // XMScalarSinCos
            Memo.AppendText("\r\nXMScalarSinCos\r\n");
            s = String.Format("Input: {0}\r\n", Value2);
            Memo.AppendText(s);
            float pSin;
            float pCos;
            DMathClass.XMScalarSinCos(out pSin, out pCos, Value2);
            s = String.Format("pSin:  {0} pCos: {1}\r\n", pSin, pCos);
            Memo.AppendText(s);

        }

        private void btVectArith_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(3.1f, 0.2f, 0.3f, -1.1f);
            dmXMVECTOR V2 = new dmXMVECTOR(2.3f, -0.1f, 1.6f, 2.0f);
            dmXMVECTOR V3 = new dmXMVECTOR(1.4f, 2.7f, 4.1f, -3.1f);
            dmXMVECTOR vMin = new dmXMVECTOR(1.1f, 2.6f, 3.1f, -3.1f);
            dmXMVECTOR vMax = new dmXMVECTOR(2.1f, 3.6f, 4.1f, 3.1f);

            // XMVectorAbs
            Memo.AppendText("\r\nXMVectorAbs\r\n");
            String s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVectorAbs(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorAdd
            Memo.AppendText("\r\nXMVectorAdd\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorAdd(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorAddAngles
            Memo.AppendText("\r\nXMVectorAddAngles\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorAddAngles(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorCeiling
            Memo.AppendText("\r\nXMVectorCeiling\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorCeiling(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorClamp
            Memo.AppendText("\r\nXMVectorClamp\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Min:  {0}, {1}, {2}, {3}\r\n", vMin.dmXMVECTOR_f32.x, vMin.dmXMVECTOR_f32.y, vMin.dmXMVECTOR_f32.z, vMin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Max:  {0}, {1}, {2}, {3}\r\n", vMax.dmXMVECTOR_f32.x, vMax.dmXMVECTOR_f32.y, vMax.dmXMVECTOR_f32.z, vMax.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorClamp(V1, vMin, vMax);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorDivide
            Memo.AppendText("\r\nXMVectorDivide\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorDivide(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorFloor
            Memo.AppendText("\r\nXMVectorFloor\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorFloor(V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorIsInfinite
            Memo.AppendText("\r\nXMVectorIsInfinite\r\n");
            V3.dmXMVECTOR_u32.y = 0x7F800000;
            V3.dmXMVECTOR_u32.z = 0x7FF00000;
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorIsInfinite(V3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            // XMVectorIsNaN
            Memo.AppendText("\r\nXMVectorIsNaN\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorIsNaN(V3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            V3.dmXMVECTOR_f32.y = 4.1f;
            V3.dmXMVECTOR_f32.z = -3.1f;
            // XMVectorMax
            Memo.AppendText("\r\nXMVectorMax\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorMax(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorMin
            Memo.AppendText("\r\nXMVectorMin\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorMin(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorMod
            Memo.AppendText("\r\nXMVectorMod\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorMod(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorModAngles
            dmXMVECTOR vAngles = new dmXMVECTOR(8.4f, -6.7f, 4.1f, 3.1f);
            Memo.AppendText("\r\nXMVectorModAngles\r\n");
            s = String.Format("Angles:  {0}, {1}, {2}, {3}\r\n", vAngles.dmXMVECTOR_f32.x, vAngles.dmXMVECTOR_f32.y, vAngles.dmXMVECTOR_f32.z, vAngles.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorModAngles(vAngles);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorMultiply
            Memo.AppendText("\r\nXMVectorMultiply\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorMultiply(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorMultiplyAdd
            Memo.AppendText("\r\nXMVectorMultiplyAdd\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V3:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorMultiplyAdd(V1, V2, V3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorNegate
            Memo.AppendText("\r\nXMVectorNegate\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorNegate(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorNegativeMultiplySubtract
            Memo.AppendText("\r\nXMVectorNegativeMultiplySubtract\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V3:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorNegativeMultiplySubtract(V1, V2, V3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorPow
            Memo.AppendText("\r\nXMVectorPow\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorPow(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorReciprocal
            Memo.AppendText("\r\nXMVectorReciprocal\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorReciprocal(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorReciprocalSqrt
            Memo.AppendText("\r\nXMVectorReciprocalSqrt\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorReciprocalSqrt(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorRound
            Memo.AppendText("\r\nXMVectorRound\r\n");
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorRound(V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSaturate
            Memo.AppendText("\r\nXMVectorSaturate\r\n");
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSaturate(V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorScale
            Memo.AppendText("\r\nXMVectorScale\r\n");
            float scaleFactor = 0.3f;
            s = String.Format("V2:  {0}, {1}, {2}, {3} Scale factor: {4}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w, scaleFactor);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorScale(V2, scaleFactor);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSqrt
            Memo.AppendText("\r\nXMVectorSqrt\r\n");
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSqrt(V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSubtract
            Memo.AppendText("\r\nXMVectorSubtract\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSubtract(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSubtractAngles
            Memo.AppendText("\r\nXMVectorSubtractAngles\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSubtractAngles(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorTruncate
            Memo.AppendText("\r\nXMVectorTruncate\r\n");
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorTruncate(V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

        }

        private void btBitWiseVector_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.4f, 1.1f, 0.9f);
            dmXMVECTOR V2 = new dmXMVECTOR(4.2f, -0.4f, -3.1f, 1.1f);
            dmXMVECTOR V3 = new dmXMVECTOR(1.4f, 2.7f, 4.1f, -3.1f);

            // XMVectorAndCInt
            Memo.AppendText("\r\nXMVectorAndCInt\r\n");
            String s = String.Format("V1:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVectorAndCInt(V1, V2);
            s = String.Format("Resulting vector:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorAndInt
            Memo.AppendText("\r\nXMVectorAndInt\r\n");
            s = String.Format("V1:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorAndInt(V1, V2);
            s = String.Format("Resulting vector:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorNorInt
            Memo.AppendText("\r\nXMVectorNorInt\r\n");
            s = String.Format("V1:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorNorInt(V1, V2);
            s = String.Format("Resulting vector:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorNotEqual
            Memo.AppendText("\r\nXMVectorNotEqual\r\n");
            s = String.Format("V1:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorNotEqual(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            // XMVectorNotEqualInt
            Memo.AppendText("\r\nXMVectorNotEqualInt\r\n");
            s = String.Format("V1:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorNotEqualInt(V1, V2);
            s = String.Format("Resulting vector:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorOrInt
            Memo.AppendText("\r\nXMVectorOrInt\r\n");
            s = String.Format("V1:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorOrInt(V1, V2);
            s = String.Format("Resulting vector:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorXorInt
            Memo.AppendText("\r\nXMVectorXorInt\r\n");
            s = String.Format("V1:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorXorInt(V1, V2);
            s = String.Format("Resulting vector:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

        }

        private void btVectComp_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.4f, 1.1f, 1.9f);
            dmXMVECTOR V2 = new dmXMVECTOR(4.2f, -0.4f, -3.1f, 1.7f);
            dmXMVECTOR V3 = new dmXMVECTOR(1.4f, 2.7f, 4.1f, -3.1f);
            dmXMVECTOR Epsilon = new dmXMVECTOR(0.2f, 0.2f, 0.2f, 0.2f);

            Memo.Clear();

            // XMVectorEqual
            Memo.AppendText("\r\nXMVectorEqual\r\n");
            String s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVectorEqual(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            // XMVectorEqualInt
            Memo.AppendText("\r\nXMVectorEqualInt\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorEqualInt(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorEqualIntR
            uint pCR;
            Memo.AppendText("\r\nXMVectorEqualIntR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorEqualIntR(out pCR, V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Comparation value: 0x{0:X}\r\n", pCR));

            // XMVectorEqualR
            Memo.AppendText("\r\nXMVectorEqualIntR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorEqualR(out pCR, V1, V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Comparation value: 0x{0:X}\r\n", pCR));

            // XMVectorGreater
            Memo.AppendText("\r\nXMVectorGreater\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorGreater(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            // XMVectorGreaterOrEqual
            Memo.AppendText("\r\nXMVectorGreaterOrEqual\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorGreaterOrEqual(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            // XMVectorGreaterOrEqualR
            Memo.AppendText("\r\nXMVectorGreaterOrEqualR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorGreaterOrEqualR(out pCR, V1, V3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Comparation value: 0x{0:X}\r\n", pCR));

            // XMVectorGreaterR
            Memo.AppendText("\r\nXMVectorGreaterR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorGreaterR(out pCR, V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Comparation value: 0x{0:X}\r\n", pCR));

            // XMVectorLess
            Memo.AppendText("\r\nXMVectorLess\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorLess(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            // XMVectorLessOrEqual
            Memo.AppendText("\r\nXMVectorLessOrEqual\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorLessOrEqual(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            // XMVectorNearEqual
            Memo.AppendText("\r\nXMVectorNearEqual\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Epsilon:  {0}, {1}, {2}, {3}\r\n", Epsilon.dmXMVECTOR_f32.x, Epsilon.dmXMVECTOR_f32.y, Epsilon.dmXMVECTOR_f32.z, Epsilon.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorNearEqual(V1, V2, Epsilon);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

        }

        private void btCompWise_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.4f, 1.1f, 1.9f);
            dmXMVECTOR V2 = new dmXMVECTOR(4.2f, -0.5f, -3.1f, 1.7f);
            dmXMVECTOR V3 = new dmXMVECTOR(1.4f, 2.7f, 4.1f, -3.1f);
            Memo.Clear();

            // XMVectorInsert
            Memo.AppendText("\r\nXMVectorInsert\r\n");
            String s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            uint rotPos = 3;
            uint sel0 = 0;
            uint sel1 = 1;
            uint sel2 = 2;
            uint sel3 = 3;
            s = String.Format("Positions to rotate left: {0}, Select0: {1}, Select1: {2}, Select2: {3}, Select3: {4}\r\n", rotPos, sel0 > 0, sel1 > 0, sel2 > 0, sel3 > 0);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVectorInsert(V1, V2, rotPos, sel0, sel1, sel2, sel3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorMergeXY
            Memo.AppendText("\r\nXMVectorMergeXY\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorMergeXY(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorMergeZW
            Memo.AppendText("\r\nXMVectorMergeZW\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorMergeZW(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorPermute
            Memo.AppendText("\r\nXMVectorPermute\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            uint permX = 4;
            uint permY = 1;
            uint permZ = 2;
            uint permW = 7;
            s = String.Format("Index of X: {0}, Index of Y: {1}, Index of Z: {2}, Index of W: {3}\r\n", permX, permY, permZ, permW);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorPermute(V1, V2, permX, permY, permZ, permW);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorRotateLeft
            Memo.AppendText("\r\nXMVectorRotateLeft\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Rotate left by: {0}\r\n", rotPos);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorRotateLeft(V1, rotPos);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorRotateRight
            Memo.AppendText("\r\nXMVectorRotateRight\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Rotate right by: {0}\r\n", rotPos);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorRotateRight(V1, rotPos);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSelect
            dmXMVECTOR vControl = new dmXMVECTOR(0, -1, 0, -1);
            Memo.AppendText("\r\nXMVectorSelect\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Control:  {0}, {1}, {2}, {3}\r\n", vControl.dmXMVECTOR_i32.x == -1, vControl.dmXMVECTOR_i32.y == -1, vControl.dmXMVECTOR_i32.z == -1, vControl.dmXMVECTOR_i32.w == -1);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSelect(V1, V2, vControl);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSelectControl
            uint Index0 = 0;
            uint Index1 = 1;
            uint Index2 = 0;
            uint Index3 = 1;
            Memo.AppendText("\r\nXMVectorSelectControl\r\n");
            s = String.Format("Index0: {0}, Index1: {1}, Index2: {2}, Index3: {3}\r\n", Index0, Index1, Index2, Index3);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSelectControl(Index0, Index1, Index2, Index3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_i32.x, resVect.dmXMVECTOR_i32.y, resVect.dmXMVECTOR_i32.z, resVect.dmXMVECTOR_i32.w);
            Memo.AppendText(s);

            // XMVectorShiftLeft
            Memo.AppendText("\r\nXMVectorShiftLeft\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Shift left by: {0}\r\n", rotPos);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorShiftLeft(V1, V2, rotPos);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatW
            Memo.AppendText("\r\nXMVectorSplatW\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSplatW(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatX
            Memo.AppendText("\r\nXMVectorSplatX\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSplatX(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatY
            Memo.AppendText("\r\nXMVectorSplatY\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSplatY(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatZ
            Memo.AppendText("\r\nXMVectorSplatZ\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSplatZ(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSwizzle
            Memo.AppendText("\r\nXMVectorSwizzle\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            uint E0 = 1;
            uint E1 = 3;
            uint E2 = 1;
            uint E3 = 2;
            s = String.Format("Index0: {0}, Index1: {1}, Index2: {2}, Index3: {3}\r\n", E0, E1, E2, E3);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSwizzle(V1, E0, E1, E2, E3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

        }

        private void btGeometric_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.4f, 1.1f, 1.9f);
            dmXMVECTOR V2 = new dmXMVECTOR(4.2f, -0.5f, -3.1f, 1.7f);
            dmXMVECTOR V3 = new dmXMVECTOR(1.4f, 2.7f, 4.1f, -3.1f);
            dmXMVECTOR V4 = new dmXMVECTOR(5.4f, 4.7f, 3.1f, 1.1f);
            Memo.Clear();

            // XMVectorBaryCentric
            Memo.AppendText("\r\nXMVectorBaryCentric\r\n");
            String s = String.Format("Position0:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position1:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float f = 0.3f;
            float g = 0.4f;
            s = String.Format("Weighting factor f: {0}, Weighing factor g: {1}\r\n", f, g);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVectorBaryCentric(V1, V2, V3, f, g);
            s = String.Format("Barycentric coordinates:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorBaryCentricV
            dmXMVECTOR vF = new dmXMVECTOR(0.4f, 0.3f, 0.2f, 0.25f);
            dmXMVECTOR vG = new dmXMVECTOR(0.3f, 0.5f, 0.4f, 0.15f);
            Memo.AppendText("\r\nXMVectorBaryCentricV\r\n");
            s = String.Format("Position0:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position1:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("F:  {0}, {1}, {2}, {3}\r\n", vF.dmXMVECTOR_f32.x, vF.dmXMVECTOR_f32.y, vF.dmXMVECTOR_f32.z, vF.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("G:  {0}, {1}, {2}, {3}\r\n", vG.dmXMVECTOR_f32.x, vG.dmXMVECTOR_f32.y, vG.dmXMVECTOR_f32.z, vG.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorBaryCentricV(V1, V2, V3, vF, vG);
            s = String.Format("Barycentric coordinates:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorCatmullRom
            Memo.AppendText("\r\nXMVectorCatmullRom\r\n");
            s = String.Format("Position0:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position1:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position3:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float intFactor = 0.1f;
            s = String.Format("Interpolating control factor: {0}\r\n", intFactor);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorCatmullRom(V1, V2, V3, V4, intFactor);
            s = String.Format("Catmull-Rom interpolation:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorCatmullRomV
            dmXMVECTOR vT = new dmXMVECTOR(0.4f, 0.3f, 0.2f, 0.25f);
            Memo.AppendText("\r\nXMVectorCatmullRomV\r\n");
            s = String.Format("Position0:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position1:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position3:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("T:  {0}, {1}, {2}, {3}\r\n", vT.dmXMVECTOR_f32.x, vT.dmXMVECTOR_f32.y, vT.dmXMVECTOR_f32.z, vT.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorCatmullRomV(V1, V2, V3, V4, vT);
            s = String.Format("Catmull-Rom interpolation:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorHermite
            Memo.AppendText("\r\nXMVectorHermite\r\n");
            s = String.Format("Position0:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Tangent0:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position1:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Tangent0:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Interpolating control factor: {0}\r\n", intFactor);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorHermite(V1, V2, V3, V4, intFactor);
            s = String.Format("Interpolation:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorHermiteV
            Memo.AppendText("\r\nXMVectorHermiteV\r\n");
            s = String.Format("Position0:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Tangent0:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Position1:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Tangent1:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("T:  {0}, {1}, {2}, {3}\r\n", vT.dmXMVECTOR_f32.x, vT.dmXMVECTOR_f32.y, vT.dmXMVECTOR_f32.z, vT.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorHermiteV(V1, V2, V3, V4, vT);
            s = String.Format("Interpolation:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorInBounds
            Memo.AppendText("\r\nXMVectorInBounds\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Bounds:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorInBounds(V1, V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);

            // XMVectorInBoundsR
            uint pCR;
            Memo.AppendText("\r\nXMVectorInBoundsR\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Bounds:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorInBoundsR(out pCR, V1, V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x > 0, resVect.dmXMVECTOR_u32.y > 0, resVect.dmXMVECTOR_u32.z > 0, resVect.dmXMVECTOR_u32.w > 0);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Comparation value: 0x{0:X}\r\n", pCR));

            // XMVectorLerp
            Memo.AppendText("\r\nXMVectorLerp\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Interpolating control factor: {0}\r\n", intFactor);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorLerp(V1, V2, intFactor);
            s = String.Format("Interpolation:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorLerpV
            Memo.AppendText("\r\nXMVectorLerpV\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("T:  {0}, {1}, {2}, {3}\r\n", vT.dmXMVECTOR_f32.x, vT.dmXMVECTOR_f32.y, vT.dmXMVECTOR_f32.z, vT.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorLerpV(V1, V2, vT);
            s = String.Format("Interpolation:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

        }

        private void btVectorInit_Click(object sender, EventArgs e)
        {
            Memo.Clear();

            // XMVectorFalseInt
            Memo.AppendText("XMVectorFalseInt\r\n");
            dmXMVECTOR resVect = DMathClass.XMVectorFalseInt();
            String s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorReplicate
            float fRep = 0.3f;
            Memo.AppendText("\r\nXMVectorReplicate\r\n");
            s = String.Format("Float to replicate: {0}\r\n", fRep);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorReplicate(fRep);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorReplicateInt
            uint iRep = 3;
            Memo.AppendText("\r\nXMVectorReplicateInt\r\n");
            s = String.Format("Integer to replicate: {0}\r\n", iRep);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorReplicateInt(iRep);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorReplicateIntPtr
            Memo.AppendText("\r\nXMVectorReplicatePtr\r\n");
            s = String.Format("Integer to replicate: {0}\r\n", iRep);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorReplicateIntPtr(ref iRep);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorReplicatePtr
            Memo.AppendText("\r\nXMVectorReplicatePtr\r\n");
            s = String.Format("Float to replicate: {0}\r\n", fRep);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorReplicatePtr(ref fRep);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSet
            Memo.AppendText("\r\nXMVectorSet\r\n");
            float f1 = 0.1f;
            float f2 = 0.2f;
            float f3 = 0.3f;
            float f4 = 0.4f;
            s = String.Format("Floats: x={0}, y={1}, z={2}, w={3}\r\n", f1, f2, f3, f4);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSet(f1, f2, f3, f4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetBinaryConstant
            Memo.AppendText("\r\nXMVectorSetBinaryConstant\r\n");
            uint c1 = 1;
            uint c2 = 0;
            uint c3 = 1;
            uint c4 = 0;
            s = String.Format("Constants: C0={0}, C1={1}, C2={2}, C3={3}\r\n", c1, c2, c3, c4);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSetBinaryConstant(c1, c2, c3, c4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetInt
            Memo.AppendText("\r\nXMVectorSetInt\r\n");
            uint i1 = 10;
            uint i2 = 11;
            uint i3 = 12;
            uint i4 = 13;
            s = String.Format("Constants: x={0}, y={1}, z={2}, w={3}\r\n", i1, i2, i3, i4);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSetInt(i1, i2, i3, i4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSplatConstant
            Memo.AppendText("\r\nXMVectorSplatConstant\r\n");
            int intConst = 3;
            uint divExp = 2;
            s = String.Format("IntConstant: {0}, DivExponent: {1}\r\n", intConst, divExp);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSplatConstant(intConst, divExp);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatConstantInt
            Memo.AppendText("\r\nXMVectorSplatConstantInt\r\n");
            intConst = -3;
            s = String.Format("IntConstant: {0}\r\n", intConst);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSplatConstantInt(intConst);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_i32.x, resVect.dmXMVECTOR_i32.y, resVect.dmXMVECTOR_i32.z, resVect.dmXMVECTOR_i32.w);
            Memo.AppendText(s);

            // XMVectorSplatEpsilon
            Memo.AppendText("\r\nXMVectorSplatEpsilon\r\n");
            resVect = DMathClass.XMVectorSplatEpsilon();
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatInfinity
            Memo.AppendText("\r\nXMVectorSplatInfinity\r\n");
            resVect = DMathClass.XMVectorSplatInfinity();
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatOne
            Memo.AppendText("\r\nXMVectorSplatOne\r\n");
            resVect = DMathClass.XMVectorSplatOne();
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatQNaN
            Memo.AppendText("\r\nXMVectorSplatQNaN\r\n");
            resVect = DMathClass.XMVectorSplatQNaN();
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSplatSignMask
            Memo.AppendText("\r\nXMVectorSplatSignMask\r\n");
            resVect = DMathClass.XMVectorSplatSignMask();
            s = String.Format("Resulting vector:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorTrueInt
            Memo.AppendText("\r\nXMVectorTrueInt\r\n");
            resVect = DMathClass.XMVectorTrueInt();
            s = String.Format("Resulting vector:  0x{0:X}, 0x{1:X}, 0x{2:X}, 0x{3:X}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorZero
            Memo.AppendText("\r\nXMVectorZero\r\n");
            resVect = DMathClass.XMVectorZero();
            s = String.Format("Resulting vector:  {0:0.0}, {1:0.0}, {2:0.0}, {3:0.0}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
        }

        private void btTransVect_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.4f, 0.1f, 0.9f);
            dmXMVECTOR V2 = new dmXMVECTOR(1.2f, 0.5f, -1.3f, 1.4f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.4f, 0.7f, -0.3f, -0.5f);
            dmXMVECTOR V4 = new dmXMVECTOR(1.4f, 1.7f, -2.0f, 0.1f);
            Memo.Clear();

            // XMVectorACos
            Memo.AppendText("\r\nXMVectorACos\r\n");
            String s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVectorACos(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorASin
            Memo.AppendText("\r\nXMVectorASin\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorASin(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorATan
            Memo.AppendText("\r\nXMVectorATan\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorATan(V1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorATan2
            Memo.AppendText("\r\nXMVectorATan2\r\n");
            s = String.Format("Y:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("X:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorATan2(V1, V2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorCos
            Memo.AppendText("\r\nXMVectorCos\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorCos(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorCosH
            Memo.AppendText("\r\nXMVectorCosH\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorCosH(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorExp
            Memo.AppendText("\r\nXMVectorExp (same as XMVectorExp2)\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorExp(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorExpE
            Memo.AppendText("\r\nXMVectorExpE\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorExpE(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorLog2
            Memo.AppendText("\r\nXMVectorLog2 (same as XMVectorLog)\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorLog2(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorLogE
            Memo.AppendText("\r\nXMVectorLogE\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorLogE(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSin
            Memo.AppendText("\r\nXMVectorSin\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSin(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSinCos
            dmXMVECTOR sin;// = new dmXMVECTOR();
            dmXMVECTOR cos;// = new dmXMVECTOR();
            Memo.AppendText("\r\nXMVectorSinCos\r\n");
            s = String.Format("Vector from which to compute Sin and Cos: {0},{1},{2},{3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            DMathClass.XMVectorSinCos(out sin, out cos, V4);
            Memo.AppendText(s);
            s = String.Format("Sin:  {0},{1},{2},{3}\r\n", sin.dmXMVECTOR_f32.x, sin.dmXMVECTOR_f32.y, sin.dmXMVECTOR_f32.z, sin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Cos:  {0},{1},{2},{3}\r\n", cos.dmXMVECTOR_f32.x, cos.dmXMVECTOR_f32.y, cos.dmXMVECTOR_f32.z, cos.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSinH
            Memo.AppendText("\r\nXMVectorSinH\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorSinH(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorTan
            Memo.AppendText("\r\nXMVectorTan\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorTan(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorTanH
            Memo.AppendText("\r\nXMVectorTanH\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVectorTanH(V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
        }

        private void bt2DVectComp_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.10f, 11.20f, 0.20f, 0.5f);
            dmXMVECTOR V2 = new dmXMVECTOR(0.10f, 11.20f, 9.0f, 4.0f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.11f, 11.19f, 5.0f, -0.1f);
            dmXMVECTOR Epsilon = new dmXMVECTOR(0.02f, 0.02f, 5.0f, -0.1f);

            // XMVector2Equal
            Memo.AppendText("\r\nXMVector2Equal\r\n");
            string s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMVector2Equal(V1, V2);
            s = String.Format("Are equal? : {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2EqualInt
            Memo.AppendText("\r\nXMVector2EqualInt\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2EqualInt(V1, V2);
            s = String.Format("Are equal? : {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2EqualIntR
            Memo.AppendText("\r\nXMVector2EqualIntR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_u32.x, V3.dmXMVECTOR_u32.y, V3.dmXMVECTOR_u32.z, V3.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            uint resUInt = DMathClass.XMVector2EqualIntR(V1, V3);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector2EqualR
            Memo.AppendText("\r\nXMVector2EqualR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector2EqualR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector2Greater
            Memo.AppendText("\r\nXMVector2Greater\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2Greater(V3, V2);
            s = String.Format("Greater?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2GreaterOrEqual
            Memo.AppendText("\r\nXMVector2GreaterOrEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2GreaterOrEqual(V1, V2);
            s = String.Format("Greater or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2GreaterOrEqualR
            Memo.AppendText("\r\nXMVector2GreaterOrEqualR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector2GreaterOrEqualR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector2GreaterR
            Memo.AppendText("\r\nXMVector2GreaterR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector2GreaterR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector2IsInfinite
            Memo.AppendText("\r\nXMVector2IsInfinite\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2IsInfinite(V1);
            s = String.Format("Is infinite? {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2IsNaN
            Memo.AppendText("\r\nXMVector2IsNaN\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2IsNaN(V1);
            s = String.Format("Is NaN? {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2Less
            Memo.AppendText("\r\nXMVector2Less\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2Less(V1, V2);
            s = String.Format("Less?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2LessOrEqual
            Memo.AppendText("\r\nXMVector2LessOrEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2LessOrEqual(V1, V2);
            s = String.Format("Less or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2NearEqual
            Memo.AppendText("\r\nXMVector2NearEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Epsilon:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", Epsilon.dmXMVECTOR_f32.x, Epsilon.dmXMVECTOR_f32.y, Epsilon.dmXMVECTOR_f32.z, Epsilon.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2NearEqual(V2, V3, Epsilon);
            s = String.Format("Less or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2NotEqual
            Memo.AppendText("\r\nXMVector2NotEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2NotEqual(V1, V2);
            s = String.Format("Not equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2NotEqualInt
            Memo.AppendText("\r\nXMVector2NotEqualInt\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector2NotEqualInt(V1, V2);
            s = String.Format("Not equal?: {0}\r\n", resBool);
            Memo.AppendText(s);
        }

        private void bt2DGeometric_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.3f, 0.0f, 0.0f);
            dmXMVECTOR V2 = new dmXMVECTOR(1.2f, 0.5f, 0.0f, 0.0f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.4f, 0.7f, 0.0f, 0.0f);
            dmXMVECTOR V4 = new dmXMVECTOR(1.4f, 1.7f, 0.0f, 0.0f);
            Memo.Clear();

            // XMVector2AngleBetweenNormals
            Memo.AppendText("XMVector2AngleBetweenNormals\r\n");
            dmXMVECTOR normalized1 = DMathClass.XMVector2Normalize(V1);
            dmXMVECTOR normalized2 = DMathClass.XMVector2Normalize(V2);
            String s = String.Format("N1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized1.dmXMVECTOR_f32.x, normalized1.dmXMVECTOR_f32.y, normalized1.dmXMVECTOR_f32.z, normalized1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("N2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized2.dmXMVECTOR_f32.x, normalized2.dmXMVECTOR_f32.y, normalized2.dmXMVECTOR_f32.z, normalized2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVector2AngleBetweenNormals(normalized1, normalized2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2AngleBetweenNormalsEst
            Memo.AppendText("XMVector2AngleBetweenNormalsEst\r\n");
            s = String.Format("N1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized1.dmXMVECTOR_f32.x, normalized1.dmXMVECTOR_f32.y, normalized1.dmXMVECTOR_f32.z, normalized1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("N2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized2.dmXMVECTOR_f32.x, normalized2.dmXMVECTOR_f32.y, normalized2.dmXMVECTOR_f32.z, normalized2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2AngleBetweenNormalsEst(normalized1, normalized2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2AngleBetweenVectors
            Memo.AppendText("\r\nXMVector2AngleBetweenVectors\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2AngleBetweenVectors(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2ClampLength
            Memo.AppendText("\r\nXMVector2ClampLength\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float clampMin = 1.0f;
            float clampMax = 3.0f;
            s = String.Format("LengthMin: {0:0.00}, LengthMax: {1:0.00}\r\n", clampMin, clampMax);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2ClampLength(V1, clampMin, clampMax);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2ClampLengthV
            Memo.AppendText("\r\nXMVector2ClampLengthV\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR ClampMin = new dmXMVECTOR(1.0f, 1.0f, 0.0f, 0.0f); // x,y components must have the same value
            dmXMVECTOR ClampMax = new dmXMVECTOR(3.0f, 3.0f, 0.0f, 0.0f); // x,y components must have the same value
            s = String.Format("LengthMin:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", ClampMin.dmXMVECTOR_f32.x, ClampMin.dmXMVECTOR_f32.y, ClampMin.dmXMVECTOR_f32.z, ClampMin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("LengthMax:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", ClampMax.dmXMVECTOR_f32.x, ClampMax.dmXMVECTOR_f32.y, ClampMax.dmXMVECTOR_f32.z, ClampMax.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2ClampLengthV(V1, ClampMin, ClampMax);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2Cross
            Memo.AppendText("\r\nXMVector2Cross\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2Cross(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2Dot
            Memo.AppendText("\r\nXMVector2Dot\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2Dot(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2InBounds
            Memo.AppendText("\r\nXMVector2InBounds\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Bounds:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMVector2InBounds(V1, V3);
            s = String.Format("In bounds?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector2IntersectLine
            Memo.AppendText("\r\nXMVector2IntersectLine\r\n");
            s = String.Format("Line1Point1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Line1Point2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Line2Point1:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Line2Point2:  {0}, {1}, {2}, {3}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2IntersectLine(V1, V2, V3, V4);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2Length
            Memo.AppendText("\r\nXMVector2Length\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2Length(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2LengthSq
            Memo.AppendText("\r\nXMVector2LengthSq\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2LengthSq(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2LinePointDistance
            Memo.AppendText("\r\nXMVector2LinePointDistance\r\n");
            s = String.Format("LinePoint1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("LinePoint2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Point:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2LinePointDistance(V1, V2, V3);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2Normalize
            Memo.AppendText("\r\nXMVector2Normalize\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2Normalize(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2NormalizeEst
            Memo.AppendText("\r\nXMVector2NormalizeEst\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2NormalizeEst(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2Orthogonal
            Memo.AppendText("\r\nXMVector2Orthogonal\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2Orthogonal(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2ReciprocalLength
            Memo.AppendText("\r\nXMVector2ReciprocalLength\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2ReciprocalLength(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2ReciprocalLengthEst
            Memo.AppendText("\r\nXMVector2ReciprocalLengthEst\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2ReciprocalLengthEst(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2Reflect
            Memo.AppendText("\r\nXMVector2Reflect\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2Reflect(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2Refract
            Memo.AppendText("\r\nXMVector2Refract\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float refIndex = 0.2f;
            s = String.Format("RefractionIndex:  {0:0.00}\r\n", refIndex);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2Refract(V1, V2, refIndex);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2RefractV
            Memo.AppendText("\r\nXMVector2RefractV\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR RefIndex = new dmXMVECTOR(0.1f, 0.1f, 0.0f, 0.0f);
            s = String.Format("RefractionIndex:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", RefIndex.dmXMVECTOR_f32.x, RefIndex.dmXMVECTOR_f32.y, RefIndex.dmXMVECTOR_f32.z, RefIndex.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2RefractV(V1, V2, RefIndex);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

        }

        private void bt2DTransf_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = DMathClass.XMVectorSet(3.5f, -3.0f, 0.4f, 1.5f);
            dmXMVECTOR V2 = DMathClass.XMVectorSet(4.5f, 4.0f, 1.4f, -1.5f);
            dmXMVECTOR V3 = DMathClass.XMVectorSet(2.5f, 1.0f, -1.4f, 3.1f);
            dmXMVECTOR V4 = DMathClass.XMVectorSet(1.1f, 1.7f, 3.6f, 2.7f);
            dmXMVECTOR V5 = DMathClass.XMVectorSet(2.6f, 4.2f, 0.0f, 0.0f);
            dmXMMATRIX M1 = new dmXMMATRIX(V1, V2, V3, V4);

            // XMVector2Transform
            Memo.AppendText("XMVector2Transform\r\n");
            String s = String.Format("V:  {0},{1},{2},{3}\r\n", V5.dmXMVECTOR_f32.x, V5.dmXMVECTOR_f32.y, V5.dmXMVECTOR_f32.z, V5.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVector2Transform(V5, M1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2TransformCoord
            Memo.AppendText("\r\nXMVector2TransformCoord\r\n");
            s = String.Format("V:  {0},{1},{2},{3}\r\n", V5.dmXMVECTOR_f32.x, V5.dmXMVECTOR_f32.y, V5.dmXMVECTOR_f32.z, V5.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector2TransformCoord(V5, M1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2TransformCoordStream
            Memo.AppendText("\r\nXMVector2TransformCoordStream\r\n");
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMFLOAT2[] outfloat2arr;// = new dmXMFLOAT2[4];
            /*
            outfloat2arr[0] = new dmXMFLOAT2();
            outfloat2arr[1] = new dmXMFLOAT2();
            outfloat2arr[2] = new dmXMFLOAT2();
            outfloat2arr[3] = new dmXMFLOAT2();
            */
            dmXMFLOAT2[] infloat2arr = new dmXMFLOAT2[4];
            infloat2arr[0] = new dmXMFLOAT2(1.2f, 1.3f);
            infloat2arr[1] = new dmXMFLOAT2(3.5f, 0.2f);
            infloat2arr[2] = new dmXMFLOAT2(2.6f, 4.2f);
            infloat2arr[3] = new dmXMFLOAT2(-1.5f, 2.8f);
            Memo.AppendText("Input dmXMFLOAT2s:\r\n");
            for (int i = 0; i < infloat2arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT2:{0}: {1}, {2}\r\n", i, infloat2arr[i].x, infloat2arr[i].y));
            }
            int float2size = Marshal.SizeOf(infloat2arr.GetValue(0));
            DMathClass.XMVector2TransformCoordStream(out outfloat2arr, float2size, infloat2arr, float2size, 4, M1);
            Memo.AppendText("Output dmXMFLOAT4s:\r\n");
            for (int i = 0; i < outfloat2arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT2 {0}: {1}, {2}\r\n", i, outfloat2arr[i].x, outfloat2arr[i].y));
            }

            // XMVector2TransformNormal
            Memo.AppendText("\r\nXMVector2TransformNormal\r\n");
            s = String.Format("V:  {0},{1},{2},{3}\r\n", V5.dmXMVECTOR_f32.x, V5.dmXMVECTOR_f32.y, V5.dmXMVECTOR_f32.z, V5.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("m3:  ignored\r\n");
            Memo.AppendText("m4:  ignored\r\n");
            resVect = DMathClass.XMVector2TransformNormal(V5, M1);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector2TransformNormalStream
            Memo.AppendText("\r\nXMVector2TransformNormalStream\r\n");
            s = String.Format("V:  {0},{1},{2},{3}\r\n", V5.dmXMVECTOR_f32.x, V5.dmXMVECTOR_f32.y, V5.dmXMVECTOR_f32.z, V5.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("m3:  ignored\r\n");
            Memo.AppendText("m4:  ignored\r\n");
            Memo.AppendText("Input dmXMFLOAT2s:\r\n");
            for (int i = 0; i < infloat2arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT2:{0}: {1}, {2}\r\n", i, infloat2arr[i].x, infloat2arr[i].y));
            }
            DMathClass.XMVector2TransformNormalStream(out outfloat2arr, float2size, infloat2arr, float2size, 4, M1);
            Memo.AppendText("Output dmXMFLOAT4s:\r\n");
            for (int i = 0; i < outfloat2arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT2 {0}: {1}, {2}\r\n", i, outfloat2arr[i].x, outfloat2arr[i].y));
            }

            // XMVector2TransformStream
            Memo.AppendText("\r\nXMVector2TransformStream\r\n");
            s = String.Format("V:  {0},{1},{2},{3}\r\n", V5.dmXMVECTOR_f32.x, V5.dmXMVECTOR_f32.y, V5.dmXMVECTOR_f32.z, V5.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMFLOAT4[] outfloat4arr = new dmXMFLOAT4[4];

            outfloat4arr[0] = new dmXMFLOAT4();
            outfloat4arr[1] = new dmXMFLOAT4();
            outfloat4arr[2] = new dmXMFLOAT4();
            outfloat4arr[3] = new dmXMFLOAT4();

            Memo.AppendText("Input dmXMFLOAT2s:\r\n");
            for (int i = 0; i < infloat2arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT2:{0}: {1}, {2}\r\n", i, infloat2arr[i].x, infloat2arr[i].y));
            }
            int float4size = Marshal.SizeOf(outfloat4arr.GetValue(0));
            DMathClass.XMVector2TransformStream(out outfloat4arr, float4size, infloat2arr, float2size, 4, M1);
            Memo.AppendText("Output dmXMFLOAT4s:\r\n");
            for (int i = 0; i < outfloat4arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT4 {0}: {1}, {2}, {3}, {4}\r\n", i, outfloat4arr[i].x, outfloat4arr[i].y, outfloat4arr[i].z, outfloat4arr[i].w));
            }

        }

        private void bt3DVectComp_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.10f, 11.20f, 0.20f, 0.0f);
            dmXMVECTOR V2 = new dmXMVECTOR(0.10f, 11.20f, 9.0f, 0.0f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.11f, 11.19f, 5.0f, 0.0f);
            dmXMVECTOR Epsilon = new dmXMVECTOR(0.02f, 0.02f, 0.02f, 0.0f);

            // XMVector3Equal
            Memo.AppendText("\r\nXMVector3Equal\r\n");
            string s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMVector3Equal(V1, V2);
            s = String.Format("Are equal? : {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3EqualInt
            Memo.AppendText("\r\nXMVector3EqualInt\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3EqualInt(V1, V2);
            s = String.Format("Are equal? : {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3EqualIntR
            Memo.AppendText("\r\nXMVector3EqualIntR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_u32.x, V3.dmXMVECTOR_u32.y, V3.dmXMVECTOR_u32.z, V3.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            uint resUInt = DMathClass.XMVector3EqualIntR(V1, V3);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector3EqualR
            Memo.AppendText("\r\nXMVector3EqualR\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector3EqualR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector3Greater
            Memo.AppendText("\r\nXMVector3Greater\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3Greater(V3, V2);
            s = String.Format("Greater?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3GreaterOrEqual
            Memo.AppendText("\r\nXMVector3GreaterOrEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3GreaterOrEqual(V1, V2);
            s = String.Format("Greater or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3GreaterOrEqualR
            Memo.AppendText("\r\nXMVector3GreaterOrEqualR\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector3GreaterOrEqualR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector3GreaterR
            Memo.AppendText("\r\nXMVector2GreaterR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector3GreaterR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector3IsInfinite
            Memo.AppendText("\r\nXMVector3IsInfinite\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3IsInfinite(V1);
            s = String.Format("Is infinite? {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3IsNaN
            Memo.AppendText("\r\nXMVector3IsNaN\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3IsNaN(V1);
            s = String.Format("Is NaN? {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3Less
            Memo.AppendText("\r\nXMVector3Less\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3Less(V1, V2);
            s = String.Format("Less?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3LessOrEqual
            Memo.AppendText("\r\nXMVector3LessOrEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3LessOrEqual(V1, V2);
            s = String.Format("Less or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3NearEqual
            Memo.AppendText("\r\nXMVector3NearEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Epsilon:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", Epsilon.dmXMVECTOR_f32.x, Epsilon.dmXMVECTOR_f32.y, Epsilon.dmXMVECTOR_f32.z, Epsilon.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3NearEqual(V2, V3, Epsilon);
            s = String.Format("Less or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3NotEqual
            Memo.AppendText("\r\nXMVector3NotEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3NotEqual(V1, V2);
            s = String.Format("Not equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3NotEqualInt
            Memo.AppendText("\r\nXMVector3NotEqualInt\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector3NotEqualInt(V1, V2);
            s = String.Format("Not equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

        }

        private void bt3DGeometric_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.3f, 1.2f, 0.0f);
            dmXMVECTOR V2 = new dmXMVECTOR(1.2f, 0.5f, -1.3f, 0.0f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.4f, 0.7f, 0.5f, 0.0f);
            dmXMVECTOR V4 = new dmXMVECTOR(1.4f, 1.7f, 1.9f, 0.0f);
            Memo.Clear();

            // XMVector3AngleBetweenNormals
            Memo.AppendText("XMVector3AngleBetweenNormals\r\n");
            dmXMVECTOR normalized1 = DMathClass.XMVector3Normalize(V1);
            dmXMVECTOR normalized2 = DMathClass.XMVector3Normalize(V2);
            String s = String.Format("N1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized1.dmXMVECTOR_f32.x, normalized1.dmXMVECTOR_f32.y, normalized1.dmXMVECTOR_f32.z, normalized1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("N2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized2.dmXMVECTOR_f32.x, normalized2.dmXMVECTOR_f32.y, normalized2.dmXMVECTOR_f32.z, normalized2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVector3AngleBetweenNormals(normalized1, normalized2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3AngleBetweenNormalsEst
            Memo.AppendText("XMVector3AngleBetweenNormalsEst\r\n");
            s = String.Format("N1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized1.dmXMVECTOR_f32.x, normalized1.dmXMVECTOR_f32.y, normalized1.dmXMVECTOR_f32.z, normalized1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("N2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized2.dmXMVECTOR_f32.x, normalized2.dmXMVECTOR_f32.y, normalized2.dmXMVECTOR_f32.z, normalized2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3AngleBetweenNormalsEst(normalized1, normalized2);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3AngleBetweenVectors
            Memo.AppendText("\r\nXMVector3AngleBetweenVectors\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3AngleBetweenVectors(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3ClampLength
            Memo.AppendText("\r\nXMVector3ClampLength\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float clampMin = 1.0f;
            float clampMax = 3.0f;
            s = String.Format("LengthMin: {0:0.00}, LengthMax: {1:0.00}\r\n", clampMin, clampMax);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3ClampLength(V1, clampMin, clampMax);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3ClampLengthV
            Memo.AppendText("\r\nXMVector3ClampLengthV\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR ClampMin = new dmXMVECTOR(1.0f, 1.0f, 1.0f, 0.0f); // x,y,z components must have the same value
            dmXMVECTOR ClampMax = new dmXMVECTOR(3.0f, 3.0f, 3.0f, 0.0f); // x,y,z components must have the same value
            s = String.Format("LengthMin:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", ClampMin.dmXMVECTOR_f32.x, ClampMin.dmXMVECTOR_f32.y, ClampMin.dmXMVECTOR_f32.z, ClampMin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("LengthMax:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", ClampMax.dmXMVECTOR_f32.x, ClampMax.dmXMVECTOR_f32.y, ClampMax.dmXMVECTOR_f32.z, ClampMax.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3ClampLengthV(V1, ClampMin, ClampMax);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3ComponentsFromNormal
            dmXMVECTOR pParalel;//= new dmXMVECTOR();
            dmXMVECTOR pPerpendicular;// = new dmXMVECTOR();
            Memo.AppendText("\r\nXMVector3ComponentsFromNormal\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMVector3ComponentsFromNormal(out pParalel, out pPerpendicular, V1, V2);
            s = String.Format("Parallel: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", pParalel.dmXMVECTOR_f32.x, pParalel.dmXMVECTOR_f32.y, pParalel.dmXMVECTOR_f32.z, pParalel.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Perpendicular: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", pPerpendicular.dmXMVECTOR_f32.x, pPerpendicular.dmXMVECTOR_f32.y, pPerpendicular.dmXMVECTOR_f32.z, pPerpendicular.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3Cross
            Memo.AppendText("\r\nXMVector3Cross\r\n");
            s = String.Format("V1: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Cross(V1, V2);
            s = String.Format("Resulting vector: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3Dot
            Memo.AppendText("\r\nXMVector3Dot\r\n");
            s = String.Format("V1: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Dot(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3InBounds
            Memo.AppendText("\r\nXMVector3InBounds\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Bounds: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMVector3InBounds(V1, V4);
            s = String.Format("In bounds?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector3Length
            Memo.AppendText("\r\nXMVector3Length\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Length(V1);
            s = String.Format("Resulting vector: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3LengthSq
            Memo.AppendText("\r\nXMVector3LengthSq\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3LengthSq(V1);
            s = String.Format("Resulting vector: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3LinePointDistance
            Memo.AppendText("\r\nXMVector3LinePointDistance\r\n");
            s = String.Format("LinePoint1: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("LinePoint2: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Point: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3LinePointDistance(V1, V2, V3);
            s = String.Format("Resulting vector: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3Normalize
            Memo.AppendText("\r\nXMVector3Normalize\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Normalize(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3NormalizeEst
            Memo.AppendText("\r\nXMVector3NormalizeEst\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3NormalizeEst(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3Orthogonal
            Memo.AppendText("\r\nXMVector3Orthogonal\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Orthogonal(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3ReciprocalLength
            Memo.AppendText("\r\nXMVector3ReciprocalLength\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3ReciprocalLength(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3ReciprocalLengthEst
            Memo.AppendText("\r\nXMVector3ReciprocalLengthEst\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3ReciprocalLengthEst(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3Reflect
            Memo.AppendText("\r\nXMVector3Reflect\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Reflect(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3Refract
            Memo.AppendText("\r\nXMVector3Refract\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float refIndex = 0.2f;
            s = String.Format("RefractionIndex:  {0:0.00}\r\n", refIndex);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Refract(V1, V2, refIndex);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3RefractV
            Memo.AppendText("\r\nXMVector3RefractV\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR RefIndex = new dmXMVECTOR(0.1f, 0.1f, 0.1f, 0.0f);
            s = String.Format("RefractionIndex:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", RefIndex.dmXMVECTOR_f32.x, RefIndex.dmXMVECTOR_f32.y, RefIndex.dmXMVECTOR_f32.z, RefIndex.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3RefractV(V1, V2, RefIndex);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
        }

        private void bt3DTransf_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.5f, 0.1f, 0.4f, 0.5f);
            dmXMVECTOR V2 = new dmXMVECTOR(0.5f, 0.0f, 0.4f, 0.4f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.0f, 0.0f, 0.4f, 0.1f);
            dmXMVECTOR V4 = new dmXMVECTOR(0.1f, 0.7f, 0.6f, 0.7f);
            dmXMVECTOR V5 = new dmXMVECTOR(0.6f, 0.2f, 0.8f, 0.0f);
            dmXMVECTOR V6 = new dmXMVECTOR(0.4f, 0.1f, 0.2f, 0.3f);
            dmXMVECTOR V7 = new dmXMVECTOR(0.7f, 0.2f, 0.1f, 0.8f);
            dmXMVECTOR V8 = new dmXMVECTOR(0.2f, 0.7f, 0.8f, 0.2f);
            dmXMVECTOR V9 = new dmXMVECTOR(0.4f, 0.4f, 0.2f, 0.3f);
            dmXMVECTOR V10 = new dmXMVECTOR(0.1f, 0.25f, 0.3f, 0.9f);
            dmXMVECTOR V11 = new dmXMVECTOR(0.9f, 0.9f, 0.8f, 0.2f);
            dmXMVECTOR V12 = new dmXMVECTOR(0.6f, 0.3f, 0.15f, 0.4f);
            dmXMVECTOR V13 = new dmXMVECTOR(0.11f, 0.3f, 0.75f, 0.0f);
            dmXMVECTOR V14 = new dmXMVECTOR(450.0f, 300.0f, 0.1f, 0.0f);
            dmXMMATRIX M1 = new dmXMMATRIX(V1, V2, V3, V4);
            dmXMMATRIX M2 = new dmXMMATRIX(V5, V6, V7, V8);
            dmXMMATRIX M3 = new dmXMMATRIX(V9, V10, V11, V12);
            Memo.Clear();

            // XMVector3InverseRotate
            Memo.AppendText("XMVector3InverseRotate\r\n");
            String s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVector3InverseRotate(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3Project
            Memo.AppendText("\r\nXMVector3Project\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V13.dmXMVECTOR_f32.x, V13.dmXMVECTOR_f32.y, V13.dmXMVECTOR_f32.z, V13.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float ViewportX = 0.0f;
            float ViewportY = 0.0f;
            float ViewportWidth = 800.0f;
            float ViewportHeight = 600.0f;
            float ViewportMinZ = 0.0f;
            float ViewportMaxZ = 1.0f;
            s = String.Format("ViewportX: {0:0.00}, ViewportY: {1:0.00}, ViewportWidth: {2:0.00}, ViewportHeight: {3:0.00} ViewportMinZ: {4:0.00} ViewportMaxZ: {5:0.00}\r\n", ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ);
            Memo.AppendText(s);
            Memo.AppendText("Project Matrix:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("View Matrix:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M2.m1.dmXMVECTOR_f32.x, M2.m1.dmXMVECTOR_f32.y, M2.m1.dmXMVECTOR_f32.z, M2.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M2.m2.dmXMVECTOR_f32.x, M2.m2.dmXMVECTOR_f32.y, M2.m2.dmXMVECTOR_f32.z, M2.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M2.m3.dmXMVECTOR_f32.x, M2.m3.dmXMVECTOR_f32.y, M2.m3.dmXMVECTOR_f32.z, M2.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M2.m4.dmXMVECTOR_f32.x, M2.m4.dmXMVECTOR_f32.y, M2.m4.dmXMVECTOR_f32.z, M2.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("World Matrix:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M3.m1.dmXMVECTOR_f32.x, M3.m1.dmXMVECTOR_f32.y, M3.m1.dmXMVECTOR_f32.z, M3.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M3.m2.dmXMVECTOR_f32.x, M3.m2.dmXMVECTOR_f32.y, M3.m2.dmXMVECTOR_f32.z, M3.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M3.m3.dmXMVECTOR_f32.x, M3.m3.dmXMVECTOR_f32.y, M3.m3.dmXMVECTOR_f32.z, M3.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M3.m4.dmXMVECTOR_f32.x, M3.m4.dmXMVECTOR_f32.y, M3.m4.dmXMVECTOR_f32.z, M3.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Project(V13, ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ, M1, M2, M3);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3ProjectStream
            Memo.AppendText("\r\nXMVector3ProjectStream\r\n");
            dmXMFLOAT3[] outfloat3arr;// = new dmXMFLOAT3[4];
            /*
            outfloat3arr[0] = new dmXMFLOAT3();
            outfloat3arr[1] = new dmXMFLOAT3();
            outfloat3arr[2] = new dmXMFLOAT3();
            outfloat3arr[3] = new dmXMFLOAT3();
            */
            dmXMFLOAT3[] infloat3arr = new dmXMFLOAT3[4];
            infloat3arr[0] = new dmXMFLOAT3(0.2f, 0.9f, 1.0f);
            infloat3arr[1] = new dmXMFLOAT3(0.5f, 0.2f, 0.6f);
            infloat3arr[2] = new dmXMFLOAT3(0.11f, 0.3f, 0.75f);
            infloat3arr[3] = new dmXMFLOAT3(0.7f, 0.8f, 0.2f);
            Memo.AppendText("Input dmXMFLOAT3s:\r\n");
            for (int i = 0; i < infloat3arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1}, {2}, {3}\r\n", i, infloat3arr[i].x, infloat3arr[i].y, infloat3arr[i].z));
            }
            s = String.Format("ViewportX: {0:0.00}, ViewportY: {1:0.00}, ViewportWidth: {2:0.00}, ViewportHeight: {3:0.00} ViewportMinZ: {4:0.00} ViewportMaxZ: {5:0.00}\r\n", ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ);
            Memo.AppendText(s);
            Memo.AppendText("Project Matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("View Matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M2.m1.dmXMVECTOR_f32.x, M2.m1.dmXMVECTOR_f32.y, M2.m1.dmXMVECTOR_f32.z, M2.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M2.m2.dmXMVECTOR_f32.x, M2.m2.dmXMVECTOR_f32.y, M2.m2.dmXMVECTOR_f32.z, M2.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M2.m3.dmXMVECTOR_f32.x, M2.m3.dmXMVECTOR_f32.y, M2.m3.dmXMVECTOR_f32.z, M2.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M2.m4.dmXMVECTOR_f32.x, M2.m4.dmXMVECTOR_f32.y, M2.m4.dmXMVECTOR_f32.z, M2.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("World Matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M3.m1.dmXMVECTOR_f32.x, M3.m1.dmXMVECTOR_f32.y, M3.m1.dmXMVECTOR_f32.z, M3.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M3.m2.dmXMVECTOR_f32.x, M3.m2.dmXMVECTOR_f32.y, M3.m2.dmXMVECTOR_f32.z, M3.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M3.m3.dmXMVECTOR_f32.x, M3.m3.dmXMVECTOR_f32.y, M3.m3.dmXMVECTOR_f32.z, M3.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M3.m4.dmXMVECTOR_f32.x, M3.m4.dmXMVECTOR_f32.y, M3.m4.dmXMVECTOR_f32.z, M3.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            int float3size = Marshal.SizeOf(infloat3arr.GetValue(0));
            DMathClass.XMVector3ProjectStream(out outfloat3arr, float3size, infloat3arr, float3size, 4,
                ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ, M1, M2, M3);
            Memo.AppendText("Output dmXMFLOAT3s:\r\n");
            for (int i = 0; i < outfloat3arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1:0.00}, {2:0.00}, {3:0.00}\r\n", i, outfloat3arr[i].x, outfloat3arr[i].y, outfloat3arr[i].z));
            }

            // XMVector3Rotate
            Memo.AppendText("\r\nXMVector3Rotate\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Rotate(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3Transform
            Memo.AppendText("\r\nXMVector3Transform\r\n");
            s = String.Format("V:  {0},{1},{2},{3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00 }, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Transform(V1, M1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3TransformCoord
            Memo.AppendText("\r\nXMVector3TransformCoord\r\n");
            s = String.Format("V:  {0},{1},{2},{3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3TransformCoord(V1, M1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3TransformCoordStream
            Memo.AppendText("\r\nXMVector3TransformCoordStream\r\n");
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMFLOAT3[] outfloat3arrA;// = new dmXMFLOAT3[4];
            /*
            outfloat3arrA[0] = new dmXMFLOAT3();
            outfloat3arrA[1] = new dmXMFLOAT3();
            outfloat3arrA[2] = new dmXMFLOAT3();
            outfloat3arrA[3] = new dmXMFLOAT3();
            */
            dmXMFLOAT3[] infloat3arrA = new dmXMFLOAT3[4];
            infloat3arrA[0] = new dmXMFLOAT3(0.2f, 0.3f, 0.5f);
            infloat3arrA[1] = new dmXMFLOAT3(0.7f, 0.9f, 0.75f);
            infloat3arrA[2] = new dmXMFLOAT3(0.5f, 0.1f, 0.4f);
            infloat3arrA[3] = new dmXMFLOAT3(0.8f, 0.8f, 0.05f);
            Memo.AppendText("Input dmXMFLOAT3s:\r\n");
            for (int i = 0; i < infloat3arrA.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1:0.00}, {2:0.00}, {3:0.00}\r\n", i, infloat3arrA[i].x, infloat3arrA[i].y, infloat3arrA[i].z));
            }
            float3size = Marshal.SizeOf(infloat3arrA.GetValue(0));
            DMathClass.XMVector3TransformCoordStream(out outfloat3arrA, float3size, infloat3arrA, float3size, 4, M1);
            Memo.AppendText("Output dmXMFLOAT4s:\r\n");
            for (int i = 0; i < outfloat3arrA.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1:0.00}, {2:0.00}, {3:0.00}\r\n", i, outfloat3arrA[i].x, outfloat3arrA[i].y, outfloat3arrA[i].z));
            }

            // XMVector3TransformNormal
            Memo.AppendText("\r\nXMVector3TransformNormal\r\n");
            s = String.Format("V:  {0},{1},{2},{3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3TransformNormal(V1, M1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3TransformNormalStream
            Memo.AppendText("\r\nXMVector3TransformNormalStream\r\n");
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Input dmXMFLOAT3s:\r\n");
            for (int i = 0; i < infloat3arrA.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1:0.00}, {2:0.00}, {3:0.00}\r\n", i, infloat3arrA[i].x, infloat3arrA[i].y, infloat3arrA[i].z));
            }
            float3size = Marshal.SizeOf(infloat3arrA.GetValue(0));
            DMathClass.XMVector3TransformNormalStream(out outfloat3arrA, float3size, infloat3arrA, float3size, 4, M1);
            Memo.AppendText("Output dmXMFLOAT4s:\r\n");
            for (int i = 0; i < outfloat3arrA.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1:0.00}, {2:0.00}, {3:0.00}\r\n", i, outfloat3arrA[i].x, outfloat3arrA[i].y, outfloat3arrA[i].z));
            }

            // XMVector3TransformStream
            Memo.AppendText("\r\nXMVector3TransformStream\r\n");
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMFLOAT4[] outfloat4arr = new dmXMFLOAT4[4];

            outfloat4arr[0] = new dmXMFLOAT4();
            outfloat4arr[1] = new dmXMFLOAT4();
            outfloat4arr[2] = new dmXMFLOAT4();
            outfloat4arr[3] = new dmXMFLOAT4();

            Memo.AppendText("Input dmXMFLOAT3s:\r\n");
            for (int i = 0; i < infloat3arrA.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1:0.00}, {2:0.00}, {3:0.00}\r\n", i, infloat3arrA[i].x, infloat3arrA[i].y, infloat3arrA[i].z));
            }
            int float4size = Marshal.SizeOf(outfloat4arr.GetValue(0));
            DMathClass.XMVector3TransformStream(out outfloat4arr, float4size, infloat3arrA, float3size, 4, M1);
            Memo.AppendText("Output dmXMFLOAT4s:\r\n");
            for (int i = 0; i < outfloat4arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT4 {0}: {1:0.00}, {2:0.00}, {3:0.00}, {4:0.00}\r\n", i, outfloat4arr[i].x, outfloat4arr[i].y, outfloat4arr[i].z, outfloat4arr[i].w));
            }

            // XMVector3Unproject
            Memo.AppendText("\r\nXMVector3Unproject\r\n");
            s = String.Format("V:  {0},{1},{2},{3}\r\n", V14.dmXMVECTOR_f32.x, V14.dmXMVECTOR_f32.y, V14.dmXMVECTOR_f32.z, V14.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            s = String.Format("ViewportX: {0:0.00}, ViewportY: {1:0.00}, ViewportWidth: {2:0.00}, ViewportHeight: {3:0.00} ViewportMinZ: {4:0.00} ViewportMaxZ: {5:0.00}\r\n", ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ);
            Memo.AppendText(s);
            Memo.AppendText("Project Matrix:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("View Matrix:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M2.m1.dmXMVECTOR_f32.x, M2.m1.dmXMVECTOR_f32.y, M2.m1.dmXMVECTOR_f32.z, M2.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M2.m2.dmXMVECTOR_f32.x, M2.m2.dmXMVECTOR_f32.y, M2.m2.dmXMVECTOR_f32.z, M2.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M2.m3.dmXMVECTOR_f32.x, M2.m3.dmXMVECTOR_f32.y, M2.m3.dmXMVECTOR_f32.z, M2.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M2.m4.dmXMVECTOR_f32.x, M2.m4.dmXMVECTOR_f32.y, M2.m4.dmXMVECTOR_f32.z, M2.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("World Matrix:\r\n");
            s = String.Format("m1:  {0},{1},{2},{3}\r\n", M3.m1.dmXMVECTOR_f32.x, M3.m1.dmXMVECTOR_f32.y, M3.m1.dmXMVECTOR_f32.z, M3.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0},{1},{2},{3}\r\n", M3.m2.dmXMVECTOR_f32.x, M3.m2.dmXMVECTOR_f32.y, M3.m2.dmXMVECTOR_f32.z, M3.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0},{1},{2},{3}\r\n", M3.m3.dmXMVECTOR_f32.x, M3.m3.dmXMVECTOR_f32.y, M3.m3.dmXMVECTOR_f32.z, M3.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0},{1},{2},{3}\r\n", M3.m4.dmXMVECTOR_f32.x, M3.m4.dmXMVECTOR_f32.y, M3.m4.dmXMVECTOR_f32.z, M3.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector3Unproject(V14, ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ, M1, M2, M3);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector3UnprojectStream
            Memo.AppendText("\r\nXMVector3UnprojectStream\r\n");
            Memo.AppendText("Input dmXMFLOAT3s:\r\n");
            dmXMFLOAT3[] infloat3arrB = new dmXMFLOAT3[4];
            infloat3arrB[0] = new dmXMFLOAT3(100.2f, 90.3f, 10.5f);
            infloat3arrB[1] = new dmXMFLOAT3(130.7f, 40.9f, 50.75f);
            infloat3arrB[2] = new dmXMFLOAT3(450.0f, 300.0f, 0.1f);
            infloat3arrB[3] = new dmXMFLOAT3(60.8f, 60.4f, 20.05f);

            for (int i = 0; i < infloat3arrB.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1}, {2}, {3}\r\n", i, infloat3arrB[i].x, infloat3arrB[i].y, infloat3arrB[i].z));
            }
            s = String.Format("ViewportX: {0:0.00}, ViewportY: {1:0.00}, ViewportWidth: {2:0.00}, ViewportHeight: {3:0.00} ViewportMinZ: {4:0.00} ViewportMaxZ: {5:0.00}\r\n", ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ);
            Memo.AppendText(s);
            Memo.AppendText("Project Matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("View Matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M2.m1.dmXMVECTOR_f32.x, M2.m1.dmXMVECTOR_f32.y, M2.m1.dmXMVECTOR_f32.z, M2.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M2.m2.dmXMVECTOR_f32.x, M2.m2.dmXMVECTOR_f32.y, M2.m2.dmXMVECTOR_f32.z, M2.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M2.m3.dmXMVECTOR_f32.x, M2.m3.dmXMVECTOR_f32.y, M2.m3.dmXMVECTOR_f32.z, M2.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M2.m4.dmXMVECTOR_f32.x, M2.m4.dmXMVECTOR_f32.y, M2.m4.dmXMVECTOR_f32.z, M2.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("World Matrix:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M3.m1.dmXMVECTOR_f32.x, M3.m1.dmXMVECTOR_f32.y, M3.m1.dmXMVECTOR_f32.z, M3.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M3.m2.dmXMVECTOR_f32.x, M3.m2.dmXMVECTOR_f32.y, M3.m2.dmXMVECTOR_f32.z, M3.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M3.m3.dmXMVECTOR_f32.x, M3.m3.dmXMVECTOR_f32.y, M3.m3.dmXMVECTOR_f32.z, M3.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M3.m4.dmXMVECTOR_f32.x, M3.m4.dmXMVECTOR_f32.y, M3.m4.dmXMVECTOR_f32.z, M3.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMVector3UnprojectStream(out outfloat3arr, float3size, infloat3arrB, float3size, 4,
                ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ, M1, M2, M3);
            Memo.AppendText("Output dmXMFLOAT3s:\r\n");
            for (int i = 0; i < outfloat3arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT3 {0}: {1:0.00}, {2:0.00}, {3:0.00}\r\n", i, outfloat3arr[i].x, outfloat3arr[i].y, outfloat3arr[i].z));
            }

        }

        private void bt4DVectComp_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.10f, 11.20f, -0.10f, 3.4f);
            dmXMVECTOR V2 = new dmXMVECTOR(0.10f, 11.20f, -3.05f, 9.5f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.11f, 11.19f, -3.04f, 9.45f);
            dmXMVECTOR Epsilon = new dmXMVECTOR(0.02f, 0.02f, 0.02f, 0.2f);

            // XMVector4Equal
            Memo.AppendText("\r\nXMVector4Equal\r\n");
            string s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMVector4Equal(V1, V2);
            s = String.Format("Are equal? : {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4EqualInt
            Memo.AppendText("\r\nXMVector4EqualInt\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4EqualInt(V1, V2);
            s = String.Format("Are equal? : {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4EqualIntR
            Memo.AppendText("\r\nXMVector4EqualIntR\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V3.dmXMVECTOR_u32.x, V3.dmXMVECTOR_u32.y, V3.dmXMVECTOR_u32.z, V3.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            uint resUInt = DMathClass.XMVector4EqualIntR(V1, V3);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector4EqualR
            Memo.AppendText("\r\nXMVector4EqualR\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector4EqualR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector4Greater
            Memo.AppendText("\r\nXMVector4Greater\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4Greater(V3, V2);
            s = String.Format("Greater?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4GreaterOrEqual
            Memo.AppendText("\r\nXMVector4GreaterOrEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4GreaterOrEqual(V1, V2);
            s = String.Format("Greater or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4GreaterOrEqualR
            Memo.AppendText("\r\nXMVector4GreaterOrEqualR\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector4GreaterOrEqualR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector4GreaterR
            Memo.AppendText("\r\nXMVector4GreaterR\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resUInt = DMathClass.XMVector4GreaterR(V1, V2);
            s = String.Format("Returned value: 0x{0:X}\r\n", resUInt);
            Memo.AppendText(s);

            // XMVector4IsInfinite
            Memo.AppendText("\r\nXMVector4IsInfinite\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4IsInfinite(V1);
            s = String.Format("Is infinite? {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4IsNaN
            Memo.AppendText("\r\nXMVector4IsNaN\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4IsNaN(V1);
            s = String.Format("Is NaN? {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4Less
            Memo.AppendText("\r\nXMVector4Less\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4Less(V1, V2);
            s = String.Format("Less?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4LessOrEqual
            Memo.AppendText("\r\nXMVector4LessOrEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4LessOrEqual(V1, V2);
            s = String.Format("Less or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4NearEqual
            Memo.AppendText("\r\nXMVector4NearEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Epsilon:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", Epsilon.dmXMVECTOR_f32.x, Epsilon.dmXMVECTOR_f32.y, Epsilon.dmXMVECTOR_f32.z, Epsilon.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4NearEqual(V2, V3, Epsilon);
            s = String.Format("Less or equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4NotEqual
            Memo.AppendText("\r\nXMVector4NotEqual\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4NotEqual(V1, V2);
            s = String.Format("Not equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4NotEqualInt
            Memo.AppendText("\r\nXMVector4NotEqualInt\r\n");
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_u32.x, V1.dmXMVECTOR_u32.y, V1.dmXMVECTOR_u32.z, V1.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resBool = DMathClass.XMVector4NotEqualInt(V1, V2);
            s = String.Format("Not equal?: {0}\r\n", resBool);
            Memo.AppendText(s);

        }

        private void bt4DGeometric_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.3f, 1.2f, 3.1f);
            dmXMVECTOR V2 = new dmXMVECTOR(1.2f, 0.5f, -1.3f, 2.2f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.4f, 0.7f, 0.5f, 1.8f);
            dmXMVECTOR V4 = new dmXMVECTOR(1.4f, 1.7f, 1.9f, 3.0f);
            Memo.Clear();

            // XMVector4AngleBetweenNormals
            Memo.AppendText("XMVector4AngleBetweenNormals\r\n");
            dmXMVECTOR normalized1 = DMathClass.XMVector4Normalize(V1);
            dmXMVECTOR normalized2 = DMathClass.XMVector4Normalize(V2);
            String s = String.Format("N1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized1.dmXMVECTOR_f32.x, normalized1.dmXMVECTOR_f32.y, normalized1.dmXMVECTOR_f32.z, normalized1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("N2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized2.dmXMVECTOR_f32.x, normalized2.dmXMVECTOR_f32.y, normalized2.dmXMVECTOR_f32.z, normalized2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVector4AngleBetweenNormals(normalized1, normalized2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4AngleBetweenNormalsEst
            Memo.AppendText("\r\nXMVector4AngleBetweenNormals\r\n");
            s = String.Format("N1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized1.dmXMVECTOR_f32.x, normalized1.dmXMVECTOR_f32.y, normalized1.dmXMVECTOR_f32.z, normalized1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("N2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", normalized2.dmXMVECTOR_f32.x, normalized2.dmXMVECTOR_f32.y, normalized2.dmXMVECTOR_f32.z, normalized2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4AngleBetweenNormalsEst(normalized1, normalized2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4AngleBetweenVectors
            Memo.AppendText("\r\nXMVector4AngleBetweenVectors\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4AngleBetweenVectors(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4ClampLength
            Memo.AppendText("\r\nXMVector4ClampLength\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float clampMin = 1.0f;
            float clampMax = 3.0f;
            s = String.Format("LengthMin: {0:0.00}, LengthMax: {1:0.00}\r\n", clampMin, clampMax);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4ClampLength(V1, clampMin, clampMax);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4ClampLengthV
            Memo.AppendText("\r\nXMVector4ClampLengthV\r\n");
            s = String.Format("V:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR ClampMin = new dmXMVECTOR(1.0f, 1.0f, 1.0f, 1.0f); // x,y,z components must have the same value
            dmXMVECTOR ClampMax = new dmXMVECTOR(3.0f, 3.0f, 3.0f, 3.0f); // x,y,z components must have the same value
            s = String.Format("LengthMin:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", ClampMin.dmXMVECTOR_f32.x, ClampMin.dmXMVECTOR_f32.y, ClampMin.dmXMVECTOR_f32.z, ClampMin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("LengthMax:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", ClampMax.dmXMVECTOR_f32.x, ClampMax.dmXMVECTOR_f32.y, ClampMax.dmXMVECTOR_f32.z, ClampMax.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4ClampLengthV(V1, ClampMin, ClampMax);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4Cross
            Memo.AppendText("\r\nXMVector4Cross\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V3.dmXMVECTOR_f32.x, V3.dmXMVECTOR_f32.y, V3.dmXMVECTOR_f32.z, V3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4Cross(V1, V2, V3);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4ot
            Memo.AppendText("\r\nXMVector4Dot\r\n");
            s = String.Format("V1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4Dot(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4InBounds
            Memo.AppendText("\r\nXMVector4InBounds\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Bounds:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V4.dmXMVECTOR_f32.x, V4.dmXMVECTOR_f32.y, V4.dmXMVECTOR_f32.z, V4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool resBool = DMathClass.XMVector4InBounds(V1, V4);
            s = String.Format("In bounds?: {0}\r\n", resBool);
            Memo.AppendText(s);

            // XMVector4Length
            Memo.AppendText("\r\nXMVector4Length\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4Length(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4LengthEst
            Memo.AppendText("\r\nXMVector4LengthEst\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4LengthEst(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4LengthSq
            Memo.AppendText("\r\nXMVector4LengthSq\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4LengthSq(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4Normalize
            Memo.AppendText("\r\nXMVector4Normalize\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4Normalize(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4NormalizeEst
            Memo.AppendText("\r\nXMVector4NormalizeEst\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4NormalizeEst(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4Orthogonal
            Memo.AppendText("\r\nXMVector4Orthogonal\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4Orthogonal(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4ReciprocalLength
            Memo.AppendText("\r\nXMVector4ReciprocalLength\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4ReciprocalLength(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4ReciprocalLengthEst
            Memo.AppendText("\r\nXMVector4ReciprocalLengthEst\r\n");
            s = String.Format("V:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4ReciprocalLengthEst(V1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4Reflect
            Memo.AppendText("\r\nXMVector4Reflect\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4Reflect(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4Refract
            Memo.AppendText("\r\nXMVector4Refract\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            float refIndex = 0.1f;
            s = String.Format("RefractionIndex:  {0:0.00}\r\n", refIndex);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4Refract(V1, V2, refIndex);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4RefractV
            Memo.AppendText("\r\nXMVector4RefractV\r\n");
            s = String.Format("Incident:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Normal:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR RefIndex = new dmXMVECTOR(0.1f, 0.1f, 0.1f, 0.1f);
            s = String.Format("RefractionIndex:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", RefIndex.dmXMVECTOR_f32.x, RefIndex.dmXMVECTOR_f32.y, RefIndex.dmXMVECTOR_f32.z, RefIndex.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resVect = DMathClass.XMVector4RefractV(V1, V2, RefIndex);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
        }

        private void bt4DTrans_Click(object sender, EventArgs e)
        {
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.3f, 1.2f, 3.1f);
            dmXMVECTOR V2 = new dmXMVECTOR(1.2f, 0.5f, -1.3f, 2.2f);
            dmXMVECTOR V3 = new dmXMVECTOR(0.4f, 0.7f, 0.5f, 1.8f);
            dmXMVECTOR V4 = new dmXMVECTOR(1.4f, 1.7f, 1.9f, 3.0f);
            dmXMMATRIX M1 = new dmXMMATRIX(V1, V2, V3, V4);

            // XMVector4Transform
            Memo.AppendText("nXMVector4Transform\r\n");
            String s = String.Format("V:  {0},{1},{2},{3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00 }, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMVector4Transform(V1, M1);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVector4TransformStream
            Memo.AppendText("\r\nXMVector4TransformStream\r\n");
            Memo.AppendText("Matrix M:\r\n");
            s = String.Format("m1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m1.dmXMVECTOR_f32.x, M1.m1.dmXMVECTOR_f32.y, M1.m1.dmXMVECTOR_f32.z, M1.m1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m2.dmXMVECTOR_f32.x, M1.m2.dmXMVECTOR_f32.y, M1.m2.dmXMVECTOR_f32.z, M1.m2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m3:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m3.dmXMVECTOR_f32.x, M1.m3.dmXMVECTOR_f32.y, M1.m3.dmXMVECTOR_f32.z, M1.m3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("m4:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", M1.m4.dmXMVECTOR_f32.x, M1.m4.dmXMVECTOR_f32.y, M1.m4.dmXMVECTOR_f32.z, M1.m4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMFLOAT4[] outfloat4arr = new dmXMFLOAT4[4];
            outfloat4arr[0] = new dmXMFLOAT4();
            outfloat4arr[1] = new dmXMFLOAT4();
            outfloat4arr[2] = new dmXMFLOAT4();
            outfloat4arr[3] = new dmXMFLOAT4();
            Memo.AppendText("Input dmXMFLOAT2s:\r\n");
            dmXMFLOAT4[] infloat4arr = new dmXMFLOAT4[4];
            infloat4arr[0] = new dmXMFLOAT4(0.6f, 0.4f, 1.5f, 1.1f);
            infloat4arr[1] = new dmXMFLOAT4(0.7f, 0.9f, 0.75f, 1.1f);
            infloat4arr[2] = new dmXMFLOAT4(0.2f, -0.3f, 1.2f, 3.1f);
            infloat4arr[3] = new dmXMFLOAT4(0.8f, 0.8f, 0.05f, 2.4f);
            Memo.AppendText("Input dmXMFLOAT4s:\r\n");

            for (int i = 0; i < infloat4arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT4 {0}: {1:0.00}, {2:0.00}, {3:0.00}, {4:0.00}\r\n", i, infloat4arr[i].x, infloat4arr[i].y, infloat4arr[i].z, infloat4arr[i].w));
            }
            int float4size = Marshal.SizeOf(outfloat4arr.GetValue(0));
            DMathClass.XMVector4TransformStream(out outfloat4arr, float4size, infloat4arr, float4size, 4, M1);
            Memo.AppendText("Output dmXMFLOAT4s:\r\n");
            for (int i = 0; i < outfloat4arr.Length; i++)
            {
                Memo.AppendText(String.Format("dmXMFLOAT4 {0}: {1:0.00}, {2:0.00}, {3:0.00}, {4:0.00}\r\n", i, outfloat4arr[i].x, outfloat4arr[i].y, outfloat4arr[i].z, outfloat4arr[i].w));
            }

        }

        private void btTemplates_Click(object sender, EventArgs e)
        {
            // XMax/XMMin
            Memo.AppendText("\r\nXMMax/XMMin (Generics)\r\n");

            int aInt = 10;
            int bInt = -12;
            Memo.AppendText(String.Format("Ints: int1={0} Int2={1}\r\n", aInt, bInt));
            int resMinInt = DMathClass.XMMin(aInt, bInt);
            Memo.AppendText(String.Format("Minimum: {0}\r\n", resMinInt));
            int resMaxInt = DMathClass.XMMax(aInt, bInt);
            Memo.AppendText(String.Format("Maximum: {0}\r\n", resMaxInt));

            uint aUInt = 10;
            uint bUInt = 15;
            Memo.AppendText(String.Format("UInts: uInt1={0} uInt2={1}\r\n", aUInt, bUInt));
            uint resMinUInt = DMathClass.XMMin(aUInt, bUInt);
            Memo.AppendText(String.Format("Minimum: {0}\r\n", resMinUInt));
            uint resMaxUInt = DMathClass.XMMax(aUInt, bUInt);
            Memo.AppendText(String.Format("Maximum: {0}\r\n", resMaxUInt));

            float aFloat = 10.3f;
            float bFloat = -12.3f;
            Memo.AppendText(String.Format("Floats: int1={0} Int2={1}\r\n", aFloat, bFloat));
            float resFloat = DMathClass.XMMin(aFloat, bFloat);
            Memo.AppendText(String.Format("Minimum: {0}\r\n", resFloat));
            resFloat = DMathClass.XMMax(aFloat, bFloat);
            Memo.AppendText(String.Format("Maximum: {0}\r\n", resFloat));

            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.3f, 1.2f, 3.1f);
            dmXMVECTOR V2 = new dmXMVECTOR(1.2f, 0.5f, -1.3f, 2.2f);
            Memo.AppendText("Vectors\r\n");
            String s = String.Format("Vector1:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Vector2:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR vResMax = DMathClass.XMMax(V1, V2);
            dmXMVECTOR vResMin = DMathClass.XMMin(V1, V2);
            s = String.Format("Minimum:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", vResMin.dmXMVECTOR_f32.x, vResMin.dmXMVECTOR_f32.y, vResMin.dmXMVECTOR_f32.z, vResMin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Maximum:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", vResMax.dmXMVECTOR_f32.x, vResMax.dmXMVECTOR_f32.y, vResMax.dmXMVECTOR_f32.z, vResMax.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("\r\nNote: C# does not support Templates, use the function forms instead (XMVectorPermute, XMVectorSwizzle, etc). XMMax and XMMin can be implemented with Generics though.");
        }

        private void btUtility_Click(object sender, EventArgs e)
        {
            uint CR1 = 0x0;
            uint CR2 = 0x80;
            uint CR3 = 0x20;

            // XMComparisonAllFalse
            bool resCR1 = DMathClass.XMComparisonAllFalse(CR1);
            bool resCR2 = DMathClass.XMComparisonAllFalse(CR2);
            bool resCR3 = DMathClass.XMComparisonAllFalse(CR3);
            String s = String.Format("nXMComparisonAllFalse. For CR=0x{0:X} result={1}, for CR=0x{2:X} result={3}, for CR=0x{4:X} result={5}\r\n", CR1, resCR1, CR2, resCR2, CR3, resCR3);
            Memo.AppendText(s);

            // XMComparisonAllInBounds
            resCR1 = DMathClass.XMComparisonAllInBounds(CR1);
            resCR2 = DMathClass.XMComparisonAllInBounds(CR2);
            resCR3 = DMathClass.XMComparisonAllInBounds(CR3);
            s = String.Format("\r\nXMComparisonAllInBounds. For CR=0x{0:X} result={1}, for CR=0x{2:X} result={3}, for CR=0x{4:X} result={5}\r\n", CR1, resCR1, CR2, resCR2, CR3, resCR3);
            Memo.AppendText(s);

            // XMComparisonAllTrue
            resCR1 = DMathClass.XMComparisonAllTrue(CR1);
            resCR2 = DMathClass.XMComparisonAllTrue(CR2);
            resCR3 = DMathClass.XMComparisonAllTrue(CR3);
            s = String.Format("\r\nXMComparisonAllTrue. For CR=0x{0:X} result={1}, for CR=0x{2:X} result={3}, for CR=0x{4:X} result={5}\r\n", CR1, resCR1, CR2, resCR2, CR3, resCR3);
            Memo.AppendText(s);

            // XMComparisonAnyFalse
            resCR1 = DMathClass.XMComparisonAnyFalse(CR1);
            resCR2 = DMathClass.XMComparisonAnyFalse(CR2);
            resCR3 = DMathClass.XMComparisonAnyFalse(CR3);
            s = String.Format("\r\nXMComparisonAnyFalse. For CR=0x{0:X} result={1}, for CR=0x{2:X} result={3}, for CR=0x{4:X} result={5}\r\n", CR1, resCR1, CR2, resCR2, CR3, resCR3);
            Memo.AppendText(s);

            // XMComparisonAnyOutOfBounds
            resCR1 = DMathClass.XMComparisonAnyOutOfBounds(CR1);
            resCR2 = DMathClass.XMComparisonAnyOutOfBounds(CR2);
            resCR3 = DMathClass.XMComparisonAnyOutOfBounds(CR3);
            s = String.Format("\r\nXMComparisonAnyOutOfBounds. For CR=0x{0:X} result={1}, for CR=0x{2:X} result={3}, for CR=0x{4:X} result={5}\r\n", CR1, resCR1, CR2, resCR2, CR3, resCR3);
            Memo.AppendText(s);

            // XMComparisonAnyTrue
            resCR1 = DMathClass.XMComparisonAnyTrue(CR1);
            resCR2 = DMathClass.XMComparisonAnyTrue(CR2);
            resCR3 = DMathClass.XMComparisonAnyTrue(CR3);
            s = String.Format("\r\nXMComparisonAnyTrue. For CR=0x{0:X} result={1}, for CR=0x{2:X} result={3}, for CR=0x{4:X} result={5}\r\n", CR1, resCR1, CR2, resCR2, CR3, resCR3);
            Memo.AppendText(s);

            // XMComparisonMixed
            resCR1 = DMathClass.XMComparisonMixed(CR1);
            resCR2 = DMathClass.XMComparisonMixed(CR2);
            resCR3 = DMathClass.XMComparisonMixed(CR3);
            s = String.Format("\r\nXMComparisonMixed. For CR=0x{0:X} result={1}, for CR=0x{2:X} result={3}, for CR=0x{4:X} result={5}\r\n", CR1, resCR1, CR2, resCR2, CR3, resCR3);
            Memo.AppendText(s);

            // XMFresnelTerm
            Memo.AppendText("\r\nXMFresnelTerm\r\n");
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.3f, 1.2f, 3.1f);
            dmXMVECTOR V2 = new dmXMVECTOR(1.2f, 0.5f, -1.3f, 2.2f);
            s = String.Format("CosIncidentAngle: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("RefractionIndex: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            dmXMVECTOR resVect = DMathClass.XMFresnelTerm(V1, V2);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVerifyCPUSupport
            Memo.AppendText("\r\nXMVerifyCPUSupport\r\n");
            bool resSupSSE2 = DMathClass.XMVerifyCPUSupport();
            s = String.Format("CPU supports SSE2? {0}", resSupSSE2);
            Memo.AppendText(s);
        }

        private void btClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btVectAcc_Click(object sender, EventArgs e)
        {
            // XMVectorGetByIndex
            Memo.AppendText("XMVectorGetByIndex\r\n");
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.3f, 1.2f, 3.1f);
            int pos = 2;
            String s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Position: {0}\r\n", pos));
            float resFloat = DMathClass.XMVectorGetByIndex(V1, pos);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetByIndexPtr
            Memo.AppendText("\r\nXMVectorGetByIndexPtr\r\n");
            pos = 3;
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Position: {0}\r\n", pos));
            DMathClass.XMVectorGetByIndexPtr(out resFloat, V1, pos);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetIntByIndex
            Memo.AppendText("\r\nXMVectorGetIntByIndex\r\n");
            dmXMVECTOR V2 = new dmXMVECTOR(2, 3, 4, 5);
            pos = 2;
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Position: {0}\r\n", pos));
            uint resUint = DMathClass.XMVectorGetIntByIndex(V2, pos);
            s = String.Format("Result:  {0}\r\n", resUint);
            Memo.AppendText(s);

            // XMVectorGetIntByIndexPtr
            Memo.AppendText("\r\nXMVectorGetIntByIndexPtr\r\n");
            pos = 1;
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("Position: {0}\r\n", pos));
            DMathClass.XMVectorGetIntByIndexPtr(out resUint, V2, pos);
            s = String.Format("Result:  {0}\r\n", resUint);
            Memo.AppendText(s);

            // XMVectorGetIntW
            Memo.AppendText("\r\nXMVectorGetIntW\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resUint = DMathClass.XMVectorGetIntW(V2);
            s = String.Format("Result:  {0}\r\n", resUint);
            Memo.AppendText(s);

            // XMVectorGetIntWPtr
            Memo.AppendText("\r\nXMVectorGetIntWPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            DMathClass.XMVectorGetIntWPtr(out resUint, V2);
            s = String.Format("Result:  {0}\r\n", resUint);
            Memo.AppendText(s);

            // XMVectorGetIntX
            Memo.AppendText("\r\nXMVectorGetIntX\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resUint = DMathClass.XMVectorGetIntX(V2);
            s = String.Format("Result:  {0}\r\n", resUint);
            Memo.AppendText(s);

            // XMVectorGetIntXPtr
            Memo.AppendText("\r\nXMVectorGetIntXPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            DMathClass.XMVectorGetIntXPtr(out resUint, V2);
            s = String.Format("Result:  {0}\r\n", resUint);
            Memo.AppendText(s);

            // XMVectorGetIntY
            Memo.AppendText("\r\nXMVectorGetIntY\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            resUint = DMathClass.XMVectorGetIntY(V2);
            s = String.Format("Result:  {0}\r\n", resUint);
            Memo.AppendText(s);

            // XMVectorGetIntYPtr
            Memo.AppendText("\r\nXMVectorGetIntYPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            DMathClass.XMVectorGetIntYPtr(out resUint, V2);
            s = String.Format("Result:  {0}\r\n", resUint);
            Memo.AppendText(s);

            // XMVectorGetW
            Memo.AppendText("\r\nXMVectorGetW\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resFloat = DMathClass.XMVectorGetW(V1);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetWPtr
            Memo.AppendText("\r\nXMVectorGetWPtr\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMVectorGetWPtr(out resFloat, V1);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetX
            Memo.AppendText("\r\nXMVectorGetX\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resFloat = DMathClass.XMVectorGetX(V1);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetXPtr
            Memo.AppendText("\r\nXMVectorGetXPtr\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMVectorGetXPtr(out resFloat, V1);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetY
            Memo.AppendText("\r\nXMVectorGetY\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resFloat = DMathClass.XMVectorGetY(V1);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetYPtr
            Memo.AppendText("\r\nXMVectorGetYPtr\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMVectorGetYPtr(out resFloat, V1);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetZ
            Memo.AppendText("\r\nXMVectorGetZ\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            resFloat = DMathClass.XMVectorGetZ(V1);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorGetZPtr
            Memo.AppendText("\r\nXMVectorGetZPtr\r\n");
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            DMathClass.XMVectorGetZPtr(out resFloat, V1);
            s = String.Format("Result:  {0:0.00}\r\n", resFloat);
            Memo.AppendText(s);

            // XMVectorSetByIndex
            Memo.AppendText("\r\nXMVectorSetByIndex\r\n");
            pos = 2;
            float newFloatValue = 13.3f;
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}, Position: {1}\r\n", newFloatValue, pos));
            dmXMVECTOR resVect = DMathClass.XMVectorSetByIndex(V1, newFloatValue, pos);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetByIndexPtr
            Memo.AppendText("\r\nXMVectorSetByIndexPtr\r\n");
            pos = 2;
            s = String.Format("V: {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}, Position: {1}\r\n", newFloatValue, pos));
            resVect = DMathClass.XMVectorSetByIndexPtr(V1, ref newFloatValue, pos);
            s = String.Format("Resulting vector:  {0:0.00}, {1:0.00}, {2:0.00}, {3:0.00}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetIntByIndex
            Memo.AppendText("\r\nXMVectorSetIntByIndex\r\n");
            pos = 2;
            uint newUInt = 13;
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}, Position: {1}\r\n", newUInt, pos));
            resVect = DMathClass.XMVectorSetIntByIndex(V2, newUInt, pos);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntByIndexPtr
            Memo.AppendText("\r\nXMVectorSetIntByIndexPtr\r\n");
            pos = 2;
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}, Position: {1}\r\n", newUInt, pos));
            resVect = DMathClass.XMVectorSetIntByIndexPtr(V2, ref newUInt, pos);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntW
            Memo.AppendText("\r\nXMVectorSetIntByIndex\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newUInt));
            resVect = DMathClass.XMVectorSetIntW(V2, newUInt);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntWPtr
            Memo.AppendText("\r\nXMVectorSetIntWPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newUInt));
            resVect = DMathClass.XMVectorSetIntWPtr(V2, ref newUInt);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntX
            Memo.AppendText("\r\nXMVectorSetIntX\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newUInt));
            resVect = DMathClass.XMVectorSetIntX(V2, newUInt);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntXPtr
            Memo.AppendText("\r\nXMVectorSetIntXPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newUInt));
            resVect = DMathClass.XMVectorSetIntXPtr(V2, ref newUInt);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntY
            Memo.AppendText("\r\nXMVectorSetIntY\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newUInt));
            resVect = DMathClass.XMVectorSetIntY(V2, newUInt);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntYPtr
            Memo.AppendText("\r\nXMVectorSetIntYPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newUInt));
            resVect = DMathClass.XMVectorSetIntYPtr(V2, ref newUInt);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntZ
            Memo.AppendText("\r\nXMVectorSetIntZ\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newUInt));
            resVect = DMathClass.XMVectorSetIntZ(V2, newUInt);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetIntZPtr
            Memo.AppendText("\r\nXMVectorSetIntZPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_u32.x, V2.dmXMVECTOR_u32.y, V2.dmXMVECTOR_u32.z, V2.dmXMVECTOR_u32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newUInt));
            resVect = DMathClass.XMVectorSetIntZPtr(V2, ref newUInt);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_u32.x, resVect.dmXMVECTOR_u32.y, resVect.dmXMVECTOR_u32.z, resVect.dmXMVECTOR_u32.w);
            Memo.AppendText(s);

            // XMVectorSetW
            Memo.AppendText("\r\nXMVectorSetW\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newFloatValue));
            resVect = DMathClass.XMVectorSetW(V1, newFloatValue);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetWPtr
            Memo.AppendText("\r\nXMVectorSetWPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newFloatValue));
            resVect = DMathClass.XMVectorSetWPtr(V1, ref newFloatValue);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetX
            Memo.AppendText("\r\nXMVectorSetX\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newFloatValue));
            resVect = DMathClass.XMVectorSetX(V1, newFloatValue);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetXPtr
            Memo.AppendText("\r\nXMVectorSetXPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newFloatValue));
            resVect = DMathClass.XMVectorSetXPtr(V1, ref newFloatValue);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetY
            Memo.AppendText("\r\nXMVectorSetY\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newFloatValue));
            resVect = DMathClass.XMVectorSetY(V1, newFloatValue);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetYPtr
            Memo.AppendText("\r\nXMVectorSetYPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newFloatValue));
            resVect = DMathClass.XMVectorSetYPtr(V1, ref newFloatValue);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetZ
            Memo.AppendText("\r\nXMVectorSetZ\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newFloatValue));
            resVect = DMathClass.XMVectorSetZ(V1, newFloatValue);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

            // XMVectorSetZPtr
            Memo.AppendText("\r\nXMVectorSetZPtr\r\n");
            s = String.Format("V: {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText(String.Format("New Value: {0}\r\n", newFloatValue));
            resVect = DMathClass.XMVectorSetZPtr(V1, ref newFloatValue);
            s = String.Format("Resulting vector:  {0}, {1}, {2}, {3}\r\n", resVect.dmXMVECTOR_f32.x, resVect.dmXMVECTOR_f32.y, resVect.dmXMVECTOR_f32.z, resVect.dmXMVECTOR_f32.w);
            Memo.AppendText(s);

        }

        private void btTriangleTests_Click(object sender, EventArgs e)
        {

            Memo.Clear();
            // ContainmentType ContainedBy(dmXMVECTOR^ V0, dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ Plane0, dmXMVECTOR^ Plane1, dmXMVECTOR^ Plane2, dmXMVECTOR^ Plane3, dmXMVECTOR^ Plane4, dmXMVECTOR^ Plane5)
            dmXMVECTOR V0 = new dmXMVECTOR(0.1f, -0.1f, -0.5f, 0.0f);
            dmXMVECTOR V1 = new dmXMVECTOR(0.2f, -0.5f, -0.6f, 0.0f);
            dmXMVECTOR V2 = new dmXMVECTOR(0.3f, -0.4f, -0.4f, 0.0f);

            dmXMVECTOR Plane0 = new dmXMVECTOR(0.0f, 0.0f, -1.0f, 0.0f);
            dmXMVECTOR Plane1 = new dmXMVECTOR(0.0f, 0.0f, -1.0f, 1.0f);
            dmXMVECTOR Plane2 = new dmXMVECTOR(1.0f, 0.0f, 0.0f, 0.0f);
            dmXMVECTOR Plane3 = new dmXMVECTOR(1.0f, 0.0f, 0.0f, -1.0f);
            dmXMVECTOR Plane4 = new dmXMVECTOR(0.0f, -1.0f, 0.0f, 0.0f);
            dmXMVECTOR Plane5 = new dmXMVECTOR(0.0f, -1.0f, 0.0f, 1.0f);
            Memo.AppendText("TriangleTests/ContainedBy:\r\n");
            String s = String.Format("V0:  {0}, {1}, {2}, {3}\r\n", V0.dmXMVECTOR_f32.x, V0.dmXMVECTOR_f32.y, V0.dmXMVECTOR_f32.z, V0.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1.dmXMVECTOR_f32.x, V1.dmXMVECTOR_f32.y, V1.dmXMVECTOR_f32.z, V1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2.dmXMVECTOR_f32.x, V2.dmXMVECTOR_f32.y, V2.dmXMVECTOR_f32.z, V2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Plane0:  {0}, {1}, {2}, {3}\r\n", Plane0.dmXMVECTOR_f32.x, Plane0.dmXMVECTOR_f32.y, Plane0.dmXMVECTOR_f32.z, Plane0.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Plane1:  {0}, {1}, {2}, {3}\r\n", Plane1.dmXMVECTOR_f32.x, Plane1.dmXMVECTOR_f32.y, Plane1.dmXMVECTOR_f32.z, Plane1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Plane2:  {0}, {1}, {2}, {3}\r\n", Plane2.dmXMVECTOR_f32.x, Plane2.dmXMVECTOR_f32.y, Plane2.dmXMVECTOR_f32.z, Plane2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Plane3:  {0}, {1}, {2}, {3}\r\n", Plane3.dmXMVECTOR_f32.x, Plane3.dmXMVECTOR_f32.y, Plane3.dmXMVECTOR_f32.z, Plane3.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Plane4:  {0}, {1}, {2}, {3}\r\n", Plane4.dmXMVECTOR_f32.x, Plane4.dmXMVECTOR_f32.y, Plane4.dmXMVECTOR_f32.z, Plane4.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Plane5:  {0}, {1}, {2}, {3}\r\n", Plane5.dmXMVECTOR_f32.x, Plane5.dmXMVECTOR_f32.y, Plane5.dmXMVECTOR_f32.z, Plane5.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            Memo.AppendText("Result:");
            ContainmentType cont = TriangleTests.ContainedBy(V0, V1, V2, Plane0, Plane1, Plane2, Plane3, Plane4, Plane5);
            switch (cont)
            {
                case ContainmentType.DISJOINT:
                    Memo.AppendText("Disjoint\r\n");
                    break;
                case ContainmentType.INTERSECTS:
                    Memo.AppendText("Intersects\r\n");
                    break;
                case ContainmentType.CONTAINS:
                    Memo.AppendText("Contains\r\n");
                    break;

            }


            // Intersects(dmXMVECTOR^ Origin, dmXMVECTOR^ Direction, dmXMVECTOR^ V0, dmXMVECTOR^ V1, dmXMVECTOR^ V2, [Out] float% Dist)
            dmXMVECTOR Origin = new dmXMVECTOR(0.0f, 0.0f, 50.0f, 0.0f);
            dmXMVECTOR Direction = new dmXMVECTOR(0.6f, 0.0f, -0.8f, 0.0f);
            dmXMVECTOR V0i1 = new dmXMVECTOR(1.7f, 0.05f, 48.0f, 1.0f);
            dmXMVECTOR V1i1 = new dmXMVECTOR(-0.4f, -0.2f, 45.0f, 1.0f);
            dmXMVECTOR V2i1 = new dmXMVECTOR(-1.3f, -1.2f, 48.2f, 1.0f);
            float Dist;
            Memo.AppendText("\r\nTriangleTests/Intersects (Triangle-Ray):\r\n");
            s = String.Format("Ray Origin:  {0}, {1}, {2}, {3}\r\n", Origin.dmXMVECTOR_f32.x, Origin.dmXMVECTOR_f32.y, Origin.dmXMVECTOR_f32.z, Origin.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Ray Direction:  {0}, {1}, {2}, {3}\r\n", Direction.dmXMVECTOR_f32.x, Direction.dmXMVECTOR_f32.y, Direction.dmXMVECTOR_f32.z, Direction.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V0:  {0}, {1}, {2}, {3}\r\n", V0i1.dmXMVECTOR_f32.x, V0i1.dmXMVECTOR_f32.y, V0i1.dmXMVECTOR_f32.z, V0i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1i1.dmXMVECTOR_f32.x, V1i1.dmXMVECTOR_f32.y, V1i1.dmXMVECTOR_f32.z, V1i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2i1.dmXMVECTOR_f32.x, V2i1.dmXMVECTOR_f32.y, V2i1.dmXMVECTOR_f32.z, V2i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            bool intercepts = TriangleTests.Intersects(Origin, Direction, V0i1, V1i1, V2i1, out Dist);
            s = String.Format("Intersects? {0}\r\n", intercepts);
            Memo.AppendText(s);

            // Intersects(dmXMVECTOR^ A0, dmXMVECTOR^ A1, dmXMVECTOR^ A2, dmXMVECTOR^ B0, dmXMVECTOR^ B1, dmXMVECTOR^ B2)
            dmXMVECTOR V0i2 = new dmXMVECTOR(1.8f, 0.06f, 46.0f, 1.0f);
            dmXMVECTOR V1i2 = new dmXMVECTOR(0.4f, -0.2f, 45.0f, 1.0f);
            dmXMVECTOR V2i2 = new dmXMVECTOR(-1.4f, -1.2f, 50.0f, 1.0f);
            Memo.AppendText("\r\nTriangleTests/Intersects (Triangle-Triangle):\r\n");
            s = String.Format("Triangle1 A0:  {0}, {1}, {2}, {3}\r\n", V0i1.dmXMVECTOR_f32.x, V0i1.dmXMVECTOR_f32.y, V0i1.dmXMVECTOR_f32.z, V0i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Triangle1 A1:  {0}, {1}, {2}, {3}\r\n", V1i1.dmXMVECTOR_f32.x, V1i1.dmXMVECTOR_f32.y, V1i1.dmXMVECTOR_f32.z, V1i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Triangle1 A2:  {0}, {1}, {2}, {3}\r\n", V2i1.dmXMVECTOR_f32.x, V2i1.dmXMVECTOR_f32.y, V2i1.dmXMVECTOR_f32.z, V2i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Triangle2 B0:  {0}, {1}, {2}, {3}\r\n", V0i2.dmXMVECTOR_f32.x, V0i2.dmXMVECTOR_f32.y, V0i2.dmXMVECTOR_f32.z, V0i2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Triangle2 B1:  {0}, {1}, {2}, {3}\r\n", V1i2.dmXMVECTOR_f32.x, V1i2.dmXMVECTOR_f32.y, V1i2.dmXMVECTOR_f32.z, V1i2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Triangle2 B2:  {0}, {1}, {2}, {3}\r\n", V2i2.dmXMVECTOR_f32.x, V2i2.dmXMVECTOR_f32.y, V2i2.dmXMVECTOR_f32.z, V2i2.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            intercepts = TriangleTests.Intersects(V0i1, V1i1, V2i1, V0i2, V1i2, V2i2);
            s = String.Format("Intersects? {0}\r\n", intercepts);
            Memo.AppendText(s);


            // PlaneIntersectionType Intersects(dmXMVECTOR^ V0, dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ Plane)
            dmXMVECTOR Plane = new dmXMVECTOR(46.0f, 0.0f, 0.0f, 0.0f);
            Memo.AppendText("\r\nTriangleTests/Intersects (Triangle-Plane):\r\n");
            s = String.Format("V0:  {0}, {1}, {2}, {3}\r\n", V0i1.dmXMVECTOR_f32.x, V0i1.dmXMVECTOR_f32.y, V0i1.dmXMVECTOR_f32.z, V0i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V1:  {0}, {1}, {2}, {3}\r\n", V1i1.dmXMVECTOR_f32.x, V1i1.dmXMVECTOR_f32.y, V1i1.dmXMVECTOR_f32.z, V1i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("V2:  {0}, {1}, {2}, {3}\r\n", V2i1.dmXMVECTOR_f32.x, V2i1.dmXMVECTOR_f32.y, V2i1.dmXMVECTOR_f32.z, V2i1.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            s = String.Format("Plane:  {0}, {1}, {2}, {3}\r\n", Plane.dmXMVECTOR_f32.x, Plane.dmXMVECTOR_f32.y, Plane.dmXMVECTOR_f32.z, Plane.dmXMVECTOR_f32.w);
            Memo.AppendText(s);
            PlaneIntersectionType intType = TriangleTests.Intersects(V0i1, V1i1, V2i1, Plane);
            Memo.AppendText("Result:");
            switch (intType)
            {
                case PlaneIntersectionType.FRONT:
                    Memo.AppendText("Front\r\n");
                    break;
                case PlaneIntersectionType.INTERSECTING:
                    Memo.AppendText("Intersecting\r\n");
                    break;
                case PlaneIntersectionType.BACK:
                    Memo.AppendText("Back\r\n");
                    break;
            }
        }
    }
}
