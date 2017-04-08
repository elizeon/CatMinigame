namespace testApp
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
            this.Memo = new System.Windows.Forms.TextBox();
            this.btColor = new System.Windows.Forms.Button();
            this.btVectorLoad = new System.Windows.Forms.Button();
            this.btVectorStore = new System.Windows.Forms.Button();
            this.btConversion = new System.Windows.Forms.Button();
            this.btMatrix = new System.Windows.Forms.Button();
            this.btPlane = new System.Windows.Forms.Button();
            this.btQuaternion = new System.Windows.Forms.Button();
            this.btScalar = new System.Windows.Forms.Button();
            this.btVectArith = new System.Windows.Forms.Button();
            this.btBitWiseVector = new System.Windows.Forms.Button();
            this.btVectComp = new System.Windows.Forms.Button();
            this.btCompWise = new System.Windows.Forms.Button();
            this.btGeometric = new System.Windows.Forms.Button();
            this.btVectorInit = new System.Windows.Forms.Button();
            this.btTransVect = new System.Windows.Forms.Button();
            this.bt2DVectComp = new System.Windows.Forms.Button();
            this.bt2DGeometric = new System.Windows.Forms.Button();
            this.bt2DTransf = new System.Windows.Forms.Button();
            this.bt3DVectComp = new System.Windows.Forms.Button();
            this.bt3DGeometric = new System.Windows.Forms.Button();
            this.bt3DTransf = new System.Windows.Forms.Button();
            this.bt4DVectComp = new System.Windows.Forms.Button();
            this.bt4DGeom = new System.Windows.Forms.Button();
            this.bt4DTransf = new System.Windows.Forms.Button();
            this.btTemplates = new System.Windows.Forms.Button();
            this.btUtility = new System.Windows.Forms.Button();
            this.btVectAcc = new System.Windows.Forms.Button();
            this.btClose = new System.Windows.Forms.Button();
            this.btTriangleTests = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Memo
            // 
            this.Memo.AcceptsReturn = true;
            this.Memo.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.Memo.BackColor = System.Drawing.Color.Black;
            this.Memo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Memo.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.Memo.Location = new System.Drawing.Point(12, 24);
            this.Memo.Multiline = true;
            this.Memo.Name = "Memo";
            this.Memo.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.Memo.Size = new System.Drawing.Size(965, 269);
            this.Memo.TabIndex = 2;
            // 
            // btColor
            // 
            this.btColor.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btColor.Location = new System.Drawing.Point(28, 309);
            this.btColor.Name = "btColor";
            this.btColor.Size = new System.Drawing.Size(199, 23);
            this.btColor.TabIndex = 3;
            this.btColor.Text = "Color Functions";
            this.btColor.UseVisualStyleBackColor = true;
            this.btColor.Click += new System.EventHandler(this.btColor_Click);
            // 
            // btVectorLoad
            // 
            this.btVectorLoad.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btVectorLoad.Location = new System.Drawing.Point(260, 537);
            this.btVectorLoad.Name = "btVectorLoad";
            this.btVectorLoad.Size = new System.Drawing.Size(199, 23);
            this.btVectorLoad.TabIndex = 4;
            this.btVectorLoad.Text = "Vector Load Functions";
            this.btVectorLoad.UseVisualStyleBackColor = true;
            this.btVectorLoad.Click += new System.EventHandler(this.btVectorLoad_Click);
            // 
            // btVectorStore
            // 
            this.btVectorStore.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btVectorStore.Location = new System.Drawing.Point(492, 537);
            this.btVectorStore.Name = "btVectorStore";
            this.btVectorStore.Size = new System.Drawing.Size(199, 23);
            this.btVectorStore.TabIndex = 5;
            this.btVectorStore.Text = "Vector Store Functions";
            this.btVectorStore.UseVisualStyleBackColor = true;
            this.btVectorStore.Click += new System.EventHandler(this.btVectorStore_Click);
            // 
            // btConversion
            // 
            this.btConversion.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btConversion.Location = new System.Drawing.Point(260, 309);
            this.btConversion.Name = "btConversion";
            this.btConversion.Size = new System.Drawing.Size(199, 23);
            this.btConversion.TabIndex = 6;
            this.btConversion.Text = "Conversion Functions";
            this.btConversion.UseVisualStyleBackColor = true;
            this.btConversion.Click += new System.EventHandler(this.btConversion_Click);
            // 
            // btMatrix
            // 
            this.btMatrix.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btMatrix.Location = new System.Drawing.Point(492, 309);
            this.btMatrix.Name = "btMatrix";
            this.btMatrix.Size = new System.Drawing.Size(199, 23);
            this.btMatrix.TabIndex = 7;
            this.btMatrix.Text = "Matrix Functions";
            this.btMatrix.UseVisualStyleBackColor = true;
            this.btMatrix.Click += new System.EventHandler(this.btMatrix_Click);
            // 
            // btPlane
            // 
            this.btPlane.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btPlane.Location = new System.Drawing.Point(724, 309);
            this.btPlane.Name = "btPlane";
            this.btPlane.Size = new System.Drawing.Size(199, 23);
            this.btPlane.TabIndex = 8;
            this.btPlane.Text = "Plane Functions";
            this.btPlane.UseVisualStyleBackColor = true;
            this.btPlane.Click += new System.EventHandler(this.btPlane_Click);
            // 
            // btQuaternion
            // 
            this.btQuaternion.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btQuaternion.Location = new System.Drawing.Point(28, 347);
            this.btQuaternion.Name = "btQuaternion";
            this.btQuaternion.Size = new System.Drawing.Size(199, 23);
            this.btQuaternion.TabIndex = 9;
            this.btQuaternion.Text = "Quaternion Functions";
            this.btQuaternion.UseVisualStyleBackColor = true;
            this.btQuaternion.Click += new System.EventHandler(this.btQuaternion_Click);
            // 
            // btScalar
            // 
            this.btScalar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btScalar.Location = new System.Drawing.Point(260, 347);
            this.btScalar.Name = "btScalar";
            this.btScalar.Size = new System.Drawing.Size(199, 23);
            this.btScalar.TabIndex = 10;
            this.btScalar.Text = "Scalar Functions";
            this.btScalar.UseVisualStyleBackColor = true;
            this.btScalar.Click += new System.EventHandler(this.btScalar_Click);
            // 
            // btVectArith
            // 
            this.btVectArith.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btVectArith.Location = new System.Drawing.Point(492, 347);
            this.btVectArith.Name = "btVectArith";
            this.btVectArith.Size = new System.Drawing.Size(199, 23);
            this.btVectArith.TabIndex = 11;
            this.btVectArith.Text = "Vector Arithmetic Functions";
            this.btVectArith.UseVisualStyleBackColor = true;
            this.btVectArith.Click += new System.EventHandler(this.btVectArith_Click);
            // 
            // btBitWiseVector
            // 
            this.btBitWiseVector.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btBitWiseVector.Location = new System.Drawing.Point(724, 347);
            this.btBitWiseVector.Name = "btBitWiseVector";
            this.btBitWiseVector.Size = new System.Drawing.Size(199, 23);
            this.btBitWiseVector.TabIndex = 12;
            this.btBitWiseVector.Text = "Bit-Wise Vector Functions";
            this.btBitWiseVector.UseVisualStyleBackColor = true;
            this.btBitWiseVector.Click += new System.EventHandler(this.btBitWiseVector_Click);
            // 
            // btVectComp
            // 
            this.btVectComp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btVectComp.Location = new System.Drawing.Point(28, 385);
            this.btVectComp.Name = "btVectComp";
            this.btVectComp.Size = new System.Drawing.Size(199, 23);
            this.btVectComp.TabIndex = 13;
            this.btVectComp.Text = "Vector Comparation Functions";
            this.btVectComp.UseVisualStyleBackColor = true;
            this.btVectComp.Click += new System.EventHandler(this.btVectComp_Click);
            // 
            // btCompWise
            // 
            this.btCompWise.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btCompWise.Location = new System.Drawing.Point(260, 385);
            this.btCompWise.Name = "btCompWise";
            this.btCompWise.Size = new System.Drawing.Size(199, 23);
            this.btCompWise.TabIndex = 14;
            this.btCompWise.Text = "Component.Wise Vector Functions";
            this.btCompWise.UseVisualStyleBackColor = true;
            this.btCompWise.Click += new System.EventHandler(this.btCompWise_Click);
            // 
            // btGeometric
            // 
            this.btGeometric.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btGeometric.Location = new System.Drawing.Point(492, 385);
            this.btGeometric.Name = "btGeometric";
            this.btGeometric.Size = new System.Drawing.Size(199, 23);
            this.btGeometric.TabIndex = 15;
            this.btGeometric.Text = "Geometric Vector Functions";
            this.btGeometric.UseVisualStyleBackColor = true;
            this.btGeometric.Click += new System.EventHandler(this.btGeometric_Click);
            // 
            // btVectorInit
            // 
            this.btVectorInit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btVectorInit.Location = new System.Drawing.Point(724, 385);
            this.btVectorInit.Name = "btVectorInit";
            this.btVectorInit.Size = new System.Drawing.Size(199, 23);
            this.btVectorInit.TabIndex = 16;
            this.btVectorInit.Text = "Vector Initialization Functions";
            this.btVectorInit.UseVisualStyleBackColor = true;
            this.btVectorInit.Click += new System.EventHandler(this.btVectorInit_Click);
            // 
            // btTransVect
            // 
            this.btTransVect.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btTransVect.Location = new System.Drawing.Point(28, 423);
            this.btTransVect.Name = "btTransVect";
            this.btTransVect.Size = new System.Drawing.Size(199, 23);
            this.btTransVect.TabIndex = 17;
            this.btTransVect.Text = "Transcendental Vector Functions";
            this.btTransVect.UseVisualStyleBackColor = true;
            this.btTransVect.Click += new System.EventHandler(this.btTransVect_Click);
            // 
            // bt2DVectComp
            // 
            this.bt2DVectComp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt2DVectComp.Location = new System.Drawing.Point(260, 423);
            this.bt2DVectComp.Name = "bt2DVectComp";
            this.bt2DVectComp.Size = new System.Drawing.Size(199, 23);
            this.bt2DVectComp.TabIndex = 18;
            this.bt2DVectComp.Text = "2D Vector Comparison Functions";
            this.bt2DVectComp.UseVisualStyleBackColor = true;
            this.bt2DVectComp.Click += new System.EventHandler(this.bt2DVectComp_Click);
            // 
            // bt2DGeometric
            // 
            this.bt2DGeometric.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt2DGeometric.Location = new System.Drawing.Point(492, 423);
            this.bt2DGeometric.Name = "bt2DGeometric";
            this.bt2DGeometric.Size = new System.Drawing.Size(199, 23);
            this.bt2DGeometric.TabIndex = 19;
            this.bt2DGeometric.Text = "2D Vector Geometric Functions";
            this.bt2DGeometric.UseVisualStyleBackColor = true;
            this.bt2DGeometric.Click += new System.EventHandler(this.bt2DGeometric_Click);
            // 
            // bt2DTransf
            // 
            this.bt2DTransf.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt2DTransf.Location = new System.Drawing.Point(724, 423);
            this.bt2DTransf.Name = "bt2DTransf";
            this.bt2DTransf.Size = new System.Drawing.Size(199, 23);
            this.bt2DTransf.TabIndex = 20;
            this.bt2DTransf.Text = "2D Vector Transformation Functions";
            this.bt2DTransf.UseVisualStyleBackColor = true;
            this.bt2DTransf.Click += new System.EventHandler(this.bt2DTransf_Click);
            // 
            // bt3DVectComp
            // 
            this.bt3DVectComp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt3DVectComp.Location = new System.Drawing.Point(28, 461);
            this.bt3DVectComp.Name = "bt3DVectComp";
            this.bt3DVectComp.Size = new System.Drawing.Size(199, 23);
            this.bt3DVectComp.TabIndex = 21;
            this.bt3DVectComp.Text = "3D Vector Comparison Functions";
            this.bt3DVectComp.UseVisualStyleBackColor = true;
            this.bt3DVectComp.Click += new System.EventHandler(this.bt3DVectComp_Click);
            // 
            // bt3DGeometric
            // 
            this.bt3DGeometric.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt3DGeometric.Location = new System.Drawing.Point(260, 461);
            this.bt3DGeometric.Name = "bt3DGeometric";
            this.bt3DGeometric.Size = new System.Drawing.Size(199, 23);
            this.bt3DGeometric.TabIndex = 22;
            this.bt3DGeometric.Text = "3D Vector Geometric Functions";
            this.bt3DGeometric.UseVisualStyleBackColor = true;
            this.bt3DGeometric.Click += new System.EventHandler(this.bt3DGeometric_Click);
            // 
            // bt3DTransf
            // 
            this.bt3DTransf.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt3DTransf.Location = new System.Drawing.Point(492, 461);
            this.bt3DTransf.Name = "bt3DTransf";
            this.bt3DTransf.Size = new System.Drawing.Size(199, 23);
            this.bt3DTransf.TabIndex = 23;
            this.bt3DTransf.Text = "3D Vector Transformation Functions";
            this.bt3DTransf.UseVisualStyleBackColor = true;
            this.bt3DTransf.Click += new System.EventHandler(this.bt3DTransf_Click);
            // 
            // bt4DVectComp
            // 
            this.bt4DVectComp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt4DVectComp.Location = new System.Drawing.Point(724, 461);
            this.bt4DVectComp.Name = "bt4DVectComp";
            this.bt4DVectComp.Size = new System.Drawing.Size(199, 23);
            this.bt4DVectComp.TabIndex = 24;
            this.bt4DVectComp.Text = "4D Vector Comparison Functions";
            this.bt4DVectComp.UseVisualStyleBackColor = true;
            this.bt4DVectComp.Click += new System.EventHandler(this.bt4DVectComp_Click);
            // 
            // bt4DGeom
            // 
            this.bt4DGeom.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt4DGeom.Location = new System.Drawing.Point(28, 499);
            this.bt4DGeom.Name = "bt4DGeom";
            this.bt4DGeom.Size = new System.Drawing.Size(199, 23);
            this.bt4DGeom.TabIndex = 25;
            this.bt4DGeom.Text = "4D Vector Geometric Functions";
            this.bt4DGeom.UseVisualStyleBackColor = true;
            this.bt4DGeom.Click += new System.EventHandler(this.bt4DGeometric_Click);
            // 
            // bt4DTransf
            // 
            this.bt4DTransf.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.bt4DTransf.Location = new System.Drawing.Point(260, 499);
            this.bt4DTransf.Name = "bt4DTransf";
            this.bt4DTransf.Size = new System.Drawing.Size(199, 23);
            this.bt4DTransf.TabIndex = 26;
            this.bt4DTransf.Text = " 4D Vector Transformation Functions";
            this.bt4DTransf.UseVisualStyleBackColor = true;
            this.bt4DTransf.Click += new System.EventHandler(this.bt4DTrans_Click);
            // 
            // btTemplates
            // 
            this.btTemplates.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btTemplates.Location = new System.Drawing.Point(492, 499);
            this.btTemplates.Name = "btTemplates";
            this.btTemplates.Size = new System.Drawing.Size(199, 23);
            this.btTemplates.TabIndex = 27;
            this.btTemplates.Text = "Template Functions ";
            this.btTemplates.UseVisualStyleBackColor = true;
            this.btTemplates.Click += new System.EventHandler(this.btTemplates_Click);
            // 
            // btUtility
            // 
            this.btUtility.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btUtility.Location = new System.Drawing.Point(724, 499);
            this.btUtility.Name = "btUtility";
            this.btUtility.Size = new System.Drawing.Size(199, 23);
            this.btUtility.TabIndex = 28;
            this.btUtility.Text = "Utility Functions";
            this.btUtility.UseVisualStyleBackColor = true;
            this.btUtility.Click += new System.EventHandler(this.btUtility_Click);
            // 
            // btVectAcc
            // 
            this.btVectAcc.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btVectAcc.Location = new System.Drawing.Point(28, 537);
            this.btVectAcc.Name = "btVectAcc";
            this.btVectAcc.Size = new System.Drawing.Size(199, 23);
            this.btVectAcc.TabIndex = 29;
            this.btVectAcc.Text = "Vector Accessor Functions";
            this.btVectAcc.UseVisualStyleBackColor = true;
            this.btVectAcc.Click += new System.EventHandler(this.btVectAcc_Click);
            // 
            // btClose
            // 
            this.btClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btClose.Location = new System.Drawing.Point(724, 550);
            this.btClose.Name = "btClose";
            this.btClose.Size = new System.Drawing.Size(199, 45);
            this.btClose.TabIndex = 30;
            this.btClose.Text = "&Close";
            this.btClose.UseVisualStyleBackColor = true;
            this.btClose.Click += new System.EventHandler(this.btClose_Click);
            // 
            // btTriangleTests
            // 
            this.btTriangleTests.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btTriangleTests.Location = new System.Drawing.Point(28, 572);
            this.btTriangleTests.Name = "btTriangleTests";
            this.btTriangleTests.Size = new System.Drawing.Size(199, 23);
            this.btTriangleTests.TabIndex = 31;
            this.btTriangleTests.Text = "Collision - Triangle Tests";
            this.btTriangleTests.UseVisualStyleBackColor = true;
            this.btTriangleTests.Click += new System.EventHandler(this.btTriangleTests_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(989, 607);
            this.Controls.Add(this.btTriangleTests);
            this.Controls.Add(this.btClose);
            this.Controls.Add(this.btVectAcc);
            this.Controls.Add(this.btUtility);
            this.Controls.Add(this.btTemplates);
            this.Controls.Add(this.bt4DTransf);
            this.Controls.Add(this.bt4DGeom);
            this.Controls.Add(this.bt4DVectComp);
            this.Controls.Add(this.bt3DTransf);
            this.Controls.Add(this.bt3DGeometric);
            this.Controls.Add(this.bt3DVectComp);
            this.Controls.Add(this.bt2DTransf);
            this.Controls.Add(this.bt2DGeometric);
            this.Controls.Add(this.bt2DVectComp);
            this.Controls.Add(this.btTransVect);
            this.Controls.Add(this.btVectorInit);
            this.Controls.Add(this.btGeometric);
            this.Controls.Add(this.btCompWise);
            this.Controls.Add(this.btVectComp);
            this.Controls.Add(this.btBitWiseVector);
            this.Controls.Add(this.btVectArith);
            this.Controls.Add(this.btScalar);
            this.Controls.Add(this.btQuaternion);
            this.Controls.Add(this.btPlane);
            this.Controls.Add(this.btMatrix);
            this.Controls.Add(this.btConversion);
            this.Controls.Add(this.btVectorStore);
            this.Controls.Add(this.btVectorLoad);
            this.Controls.Add(this.btColor);
            this.Controls.Add(this.Memo);
            this.Name = "Form1";
            this.Text = "DMath Library Testing";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox Memo;
        private System.Windows.Forms.Button btColor;
        private System.Windows.Forms.Button btVectorLoad;
        private System.Windows.Forms.Button btVectorStore;
        private System.Windows.Forms.Button btConversion;
        private System.Windows.Forms.Button btMatrix;
        private System.Windows.Forms.Button btPlane;
        private System.Windows.Forms.Button btQuaternion;
        private System.Windows.Forms.Button btScalar;
        private System.Windows.Forms.Button btVectArith;
        private System.Windows.Forms.Button btBitWiseVector;
        private System.Windows.Forms.Button btVectComp;
        private System.Windows.Forms.Button btCompWise;
        private System.Windows.Forms.Button btGeometric;
        private System.Windows.Forms.Button btVectorInit;
        private System.Windows.Forms.Button btTransVect;
        private System.Windows.Forms.Button bt2DVectComp;
        private System.Windows.Forms.Button bt2DGeometric;
        private System.Windows.Forms.Button bt2DTransf;
        private System.Windows.Forms.Button bt3DVectComp;
        private System.Windows.Forms.Button bt3DGeometric;
        private System.Windows.Forms.Button bt3DTransf;
        private System.Windows.Forms.Button bt4DVectComp;
        private System.Windows.Forms.Button bt4DGeom;
        private System.Windows.Forms.Button bt4DTransf;
        private System.Windows.Forms.Button btTemplates;
        private System.Windows.Forms.Button btUtility;
        private System.Windows.Forms.Button btVectAcc;
        private System.Windows.Forms.Button btClose;
        private System.Windows.Forms.Button btTriangleTests;
    }
}

