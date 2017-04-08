// DMathLib.h

#pragma once
#include "DDXMath.h"
#include <memory.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace DDMath;

namespace DMathLib
{


	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmFLOATXMVECTOR
	{
		float x, y, z, w;

		dmFLOATXMVECTOR() {}
		dmFLOATXMVECTOR(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmUINTXMVECTOR
	{
		uint32_t x, y, z, w;

		dmUINTXMVECTOR() {}
		dmUINTXMVECTOR(uint32_t _x, uint32_t _y, uint32_t _z, uint32_t _w) { x = _x; y = _y; z = _z; w = _w; }
	};
	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmINTXMVECTOR
	{
		int32_t x, y, z, w;

		dmINTXMVECTOR() {}
		dmINTXMVECTOR(int32_t _x, int32_t _y, int32_t _z, int32_t _w) { x = _x; y = _y; z = _z; w = _w; }
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMVECTOR
	{
		[FieldOffset(0)]
		dmFLOATXMVECTOR^ dmXMVECTOR_f32;
		[FieldOffset(0)]
		dmUINTXMVECTOR^ dmXMVECTOR_u32;
		[FieldOffset(0)]
		dmINTXMVECTOR^ dmXMVECTOR_i32;

		dmXMVECTOR() { dmXMVECTOR_f32 = gcnew dmFLOATXMVECTOR(); };
		dmXMVECTOR(float _x, float _y, float _z, float _w) {
			dmXMVECTOR_f32 = gcnew dmFLOATXMVECTOR(_x, _y, _z, _w);
		};
		dmXMVECTOR(uint32_t _x, uint32_t _y, uint32_t _z, uint32_t _w) {
			dmXMVECTOR_u32 = gcnew dmUINTXMVECTOR(_x, _y, _z, _w);
		};
		dmXMVECTOR(int32_t _x, int32_t _y, int32_t _z, int32_t _w) {
			dmXMVECTOR_i32 = gcnew dmINTXMVECTOR(_x, _y, _z, _w);
		};
		dmXMVECTOR(_In_  dmXMVECTOR^ xmv)
		{
			dmXMVECTOR_f32 = gcnew dmFLOATXMVECTOR(xmv->dmXMVECTOR_f32->x, xmv->dmXMVECTOR_f32->y, xmv->dmXMVECTOR_f32->z, xmv->dmXMVECTOR_f32->w);
		}
		void Clone(_In_ dmXMVECTOR^ xmv) {
			this->dmXMVECTOR_f32->x = xmv->dmXMVECTOR_f32->x;
			this->dmXMVECTOR_f32->y = xmv->dmXMVECTOR_f32->y;
			this->dmXMVECTOR_f32->z = xmv->dmXMVECTOR_f32->z;
			this->dmXMVECTOR_f32->w = xmv->dmXMVECTOR_f32->w;
		}

	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct _dmXMMATRIXA
	{
		float m11, m12, m13, m14;
		float m21, m22, m23, m24;
		float m31, m32, m33, m34;
		float m41, m42, m43, m44;
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMMATRIX
	{
		[FieldOffset(0)]
		_dmXMMATRIXA^ mat;
		[FieldOffset(0)]
		dmXMVECTOR^ m1;
		[FieldOffset(16)]
		dmXMVECTOR^ m2;
		[FieldOffset(32)]
		dmXMVECTOR^ m3;
		[FieldOffset(48)]
		dmXMVECTOR^ m4;

		dmXMMATRIX() { m1 = gcnew dmXMVECTOR();m2 = gcnew dmXMVECTOR();		m3 = gcnew dmXMVECTOR();m4 = gcnew dmXMVECTOR(); };
		dmXMMATRIX(dmXMVECTOR^ _m1, dmXMVECTOR^ _m2, dmXMVECTOR^ _m3, dmXMVECTOR^ _m4)
		{
			m1 = _m1; m2 = _m2;m3 = _m3; m4 = _m4;
		};
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMBYTE2
	{
		[FieldOffset(0)]
		int8_t x;
		[FieldOffset(1)]
		int8_t y;
		[FieldOffset(0)]
		uint16_t v;

		dmXMBYTE2() {}
		dmXMBYTE2(int8_t _x, int8_t _y) { x = _x; y = _y; }
		dmXMBYTE2(float _x, float _y)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreByte2((XMBYTE2*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, 0.0f, 0.0f));
			v = (uint16_t)Marshal::PtrToStructure(m_handle, uint16_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT3PK
	{
		uint32_t v;

		dmXMFLOAT3PK() {}
		dmXMFLOAT3PK(int xm, int xe, int ym, int ye, int zm, int ze)
		{
			xm &= 0x3F; xe &= 0x1F; ym &= 0x3F; ye &= 0x1F; zm &= 0x1F; ze &= 0x1F;
			v = (ze << 27) | (zm << 22) | (ye << 17) | (ym << 11) | (xe << 6) | xm;
		}
		dmXMFLOAT3PK(float _x, float _y, float _z)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreFloat3PK((XMFLOAT3PK*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, 0.0f));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMFLOAT3PK([Out] uint32_t% xm, [Out] uint32_t% xe, [Out] uint32_t% ym, [Out] uint32_t% ye, [Out] uint32_t% zm, [Out] uint32_t% ze)
		{
			xm = v & 0x3F;
			xe = (v >> 6) & 0x1F;
			ym = (v >> 11) & 0x3F;
			ye = (v >> 17) & 0x1F;
			zm = (v >> 22) & 0x1F;
			ze = (v >> 27) & 0x1F;
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT3SE
	{
		uint32_t v;

		dmXMFLOAT3SE() {}
		dmXMFLOAT3SE(int xm, int ym, int zm, int e)
		{
			xm &= 0x1FF;  ym &= 0x1FF; zm &= 0x1FF; e &= 0x1F;
			v = (e << 27) | (zm << 18) | (ym << 9) | xm;
		}
		dmXMFLOAT3SE(float _x, float _y, float _z)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreFloat3SE((XMFLOAT3SE*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, 0.0f));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMFLOAT3SE([Out] uint32_t% xm, [Out] uint32_t% ym, [Out] uint32_t% zm, [Out] uint32_t% e)
		{
			xm = v & 0x1FF;
			ym = (v >> 9) & 0x1FF;
			zm = (v >> 18) & 0x1FF;
			e = (v >> 27) & 0x1F;
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMBYTEN2
	{
		[FieldOffset(0)]
		int8_t x;
		[FieldOffset(1)]
		int8_t y;
		[FieldOffset(0)]
		uint16_t v;

		dmXMBYTEN2() {}
		dmXMBYTEN2(int8_t _x, int8_t _y) { x = _x; y = _y; }
		dmXMBYTEN2(float _x, float _y)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreByteN2((XMBYTEN2*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, 0.0f, 0.0f));
			v = (uint16_t)Marshal::PtrToStructure(m_handle, uint16_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMBYTE4
	{
		[FieldOffset(0)]
		int8_t x;
		[FieldOffset(1)]
		int8_t y;
		[FieldOffset(2)]
		int8_t z;
		[FieldOffset(3)]
		int8_t w;
		[FieldOffset(0)]
		uint32_t v;

		dmXMBYTE4() {}
		dmXMBYTE4(int8_t _x, int8_t _y, int8_t _z, int8_t _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMBYTE4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreByte4((XMBYTE4*)m_handle.ToPointer(), XMVectorSet(_x, _y, _z, _w));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMBYTEN4
	{
		[FieldOffset(0)]
		int8_t x;
		[FieldOffset(1)]
		int8_t y;
		[FieldOffset(2)]
		int8_t z;
		[FieldOffset(3)]
		int8_t w;
		[FieldOffset(0)]
		uint32_t v;

		dmXMBYTEN4() {}
		dmXMBYTEN4(int8_t _x, int8_t _y, int8_t _z, int8_t _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMBYTEN4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreByteN4((XMBYTEN4*)m_handle.ToPointer(), XMVectorSet(_x, _y, _z, _w));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMCOLOR
	{
		[FieldOffset(0)]
		uint8_t b;
		[FieldOffset(1)]
		uint8_t g;
		[FieldOffset(2)]
		uint8_t r;
		[FieldOffset(3)]
		uint8_t a;
		[FieldOffset(0)]
		uint32_t c;

		dmXMCOLOR() {}
		dmXMCOLOR(uint32_t Color) { c = Color; }
		dmXMCOLOR(float _r, float _g, float _b, float _a)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreColor((XMCOLOR*)m_handle.ToPointer(), DDMath::XMVectorSet(_r, _g, _b, _a));
			c = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMDEC4
	{
		uint32_t v;

		dmXMDEC4() {};
		dmXMDEC4(int32_t x, int32_t y, int32_t z, int32_t w)
		{
			w &= 0x3;  x &= 0x3FF; y &= 0x3FF; z &= 0x3FF;
			v = (w << 30) | (z << 20) | (y << 10) | x;
		}
		dmXMDEC4(float _x, float _y, float _z)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreDec4((XMDEC4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, 0.0f));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMDEC4([Out] int32_t% x, [Out] int32_t% y, [Out] int32_t% z, [Out] int32_t% w)
		{
			x = v & 0x3FF;
			y = (v >> 10) & 0x3FF;
			z = (v >> 20) & 0x3FF;
			w = (v >> 30) & 3;
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMDECN4
	{
		uint32_t v;

		dmXMDECN4() {};
		dmXMDECN4(int32_t x, int32_t y, int32_t z, int32_t w)
		{
			w &= 0x3;  x &= 0x3FF; y &= 0x3FF; z &= 0x3FF;
			v = (w << 30) | (z << 20) | (y << 10) | x;
		}
		dmXMDECN4(float _x, float _y, float _z)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreDecN4((XMDECN4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, 0.0f));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMDECN4([Out] int32_t% x, [Out] int32_t% y, [Out] int32_t% z, [Out] int32_t% w)
		{
			x = v & 0x3FF;
			y = (v >> 10) & 0x3FF;
			z = (v >> 20) & 0x3FF;
			w = (v >> 30) & 3;
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT3X3
	{
		float _11, _12, _13;
		float _21, _22, _23;
		float _31, _32, _33;

		dmXMFLOAT3X3() {};
		dmXMFLOAT3X3(float __11, float __12, float __13, float __21, float __22, float __23, float __31, float __32, float __33)
		{
			_11 = __11; _12 = __12; _13 = __13;
			_21 = __21; _22 = __22; _23 = __23;
			_31 = __31; _32 = __32; _33 = __33;
		};
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT4X3
	{
		float _11, _12, _13;
		float _21, _22, _23;
		float _31, _32, _33;
		float _41, _42, _43;

		dmXMFLOAT4X3() {};
		dmXMFLOAT4X3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22, float m30, float m31, float m32)
		{
			_11 = m00; _12 = m01; _13 = m02;
			_21 = m10; _22 = m11; _23 = m12;
			_31 = m20; _32 = m21; _33 = m22;
			_41 = m30; _42 = m31; _43 = m32;
		};
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT4X3A :dmXMFLOAT4X3 {};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT4X4
	{
		float _11, _12, _13, _14;
		float _21, _22, _23, _24;
		float _31, _32, _33, _34;
		float _41, _42, _43, _44;

		dmXMFLOAT4X4() {};
		dmXMFLOAT4X4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
		{
			_11 = m00; _12 = m01; _13 = m02; _14 = m03;
			_21 = m10; _22 = m11; _23 = m12; _24 = m13;
			_31 = m20; _32 = m21; _33 = m22; _34 = m23;
			_41 = m30; _42 = m31; _43 = m32; _44 = m33;
		};
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT4X4A :dmXMFLOAT4X4 {};


	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT3
	{
		float x, y, z;

		dmXMFLOAT3() {};
		dmXMFLOAT3(float _x, float _y, float _z) { x = _x;y = _y;z = _z; };

		void Clone(_In_ dmXMFLOAT3^ xmv) {
			this->x = xmv->x;
			this->y = xmv->y;
			this->z = xmv->z;
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT3A :dmXMFLOAT3 {};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT2
	{
		float x, y;

		dmXMFLOAT2() {};
		dmXMFLOAT2(float _x, float _y) { x = _x;y = _y; };
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT2A :dmXMFLOAT2 {};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT4
	{

		float x, y, z, w;

		dmXMFLOAT4() {};
		dmXMFLOAT4(float _x, float _y, float _z, float _w) { x = _x;y = _y; z = _z; w = _w; };

		void Clone(_In_ dmXMFLOAT4^ xmv) {
			this->x = xmv->x;
			this->y = xmv->y;
			this->z = xmv->z;
			this->w = xmv->w;
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMFLOAT4A :dmXMFLOAT4 {};

	using HALF = uint16_t;

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMHALF2
	{
		[FieldOffset(0)]
		HALF x;
		[FieldOffset(2)]
		HALF y;
		[FieldOffset(0)]
		uint32_t v;

		dmXMHALF2() {}
		dmXMHALF2(HALF _x, HALF _y) { x = _x; y = _y; }
		dmXMHALF2(float _x, float _y)
		{
			x = XMConvertFloatToHalf(_x);
			y = XMConvertFloatToHalf(_y);
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMHALF4
	{
		[FieldOffset(0)]
		HALF x;
		[FieldOffset(2)]
		HALF y;
		[FieldOffset(4)]
		HALF z;
		[FieldOffset(6)]
		HALF w;
		[FieldOffset(0)]
		uint64_t v;

		dmXMHALF4() {}
		dmXMHALF4(HALF _x, HALF _y, HALF _z, HALF _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMHALF4(float _x, float _y, float _z, float _w)
		{
			x = XMConvertFloatToHalf(_x);
			y = XMConvertFloatToHalf(_y);
			z = XMConvertFloatToHalf(_z);
			w = XMConvertFloatToHalf(_w);
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMSHORT2
	{
		[FieldOffset(0)]
		int16_t x;
		[FieldOffset(2)]
		int16_t y;
		[FieldOffset(0)]
		uint32_t v;

		dmXMSHORT2() {};
		dmXMSHORT2(int16_t _x, int16_t _y) { x = _x; y = _y; };
		dmXMSHORT2(float _x, float _y)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreShort2((XMSHORT2*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, 0.0f, 0.0f));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMSHORTN2
	{
		[FieldOffset(0)]
		int16_t x;
		[FieldOffset(2)]
		int16_t y;
		[FieldOffset(0)]
		uint32_t v;

		dmXMSHORTN2() {};
		dmXMSHORTN2(int16_t _x, int16_t _y) { x = _x; y = _y; };
		dmXMSHORTN2(float _x, float _y)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreShortN2((XMSHORTN2*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, 0.0f, 0.0f));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMSHORT4
	{
		[FieldOffset(0)]
		int16_t x;
		[FieldOffset(2)]
		int16_t y;
		[FieldOffset(4)]
		int16_t z;
		[FieldOffset(6)]
		int16_t w;
		[FieldOffset(0)]
		uint64_t v;

		dmXMSHORT4() {}
		dmXMSHORT4(int16_t _x, int16_t _y, int16_t _z, int16_t _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMSHORT4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreShort4((XMSHORT4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint64_t)Marshal::PtrToStructure(m_handle, uint64_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMSHORTN4
	{
		[FieldOffset(0)]
		int16_t x;
		[FieldOffset(2)]
		int16_t y;
		[FieldOffset(4)]
		int16_t z;
		[FieldOffset(6)]
		int16_t w;
		[FieldOffset(0)]
		uint64_t v;

		dmXMSHORTN4() {}
		dmXMSHORTN4(int16_t _x, int16_t _y, int16_t _z, int16_t _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMSHORTN4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreShortN4((XMSHORTN4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint64_t)Marshal::PtrToStructure(m_handle, uint64_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMINT2
	{
		int32_t x, y;

		dmXMINT2() {};
		dmXMINT2(int32_t _x, int32_t _y) { x = _x;y = _y; };
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMINT3
	{
		int32_t x, y, z;

		dmXMINT3() {};
		dmXMINT3(int32_t _x, int32_t _y, int32_t _z) { x = _x;y = _y; z = _z; };
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMINT4
	{
		int32_t x, y, z, w;

		dmXMINT4() {};
		dmXMINT4(int32_t _x, int32_t _y, int32_t _z, int32_t _w) { x = _x;y = _y; z = _z; w = _w; };
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMU555
	{
		uint16_t v;

		dmXMU555() {};
		dmXMU555(uint16_t x, uint16_t y, uint16_t z, uint16_t w)
		{
			w &= 1;  x &= 0x1F; y &= 0x1F; z &= 0x1F;
			v = (w << 15) | (z << 10) | (y << 5) | x;
		}
		dmXMU555(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreU555((XMU555*)m_handle.ToPointer(), XMVectorSet(_x, _y, _z, ((_w) ? 1.0f : 0.0f)));
			v = (uint16_t)Marshal::PtrToStructure(m_handle, uint16_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMU555([Out] uint16_t% x, [Out] uint16_t% y, [Out] uint16_t% z, [Out] uint16_t% w)
		{
			x = v & 0x1F;
			y = (v >> 5) & 0x1F;
			z = (v >> 10) & 0x1F;
			w = (v >> 15) & 1;
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMU565
	{
		uint16_t v;

		dmXMU565() {};
		dmXMU565(uint16_t x, uint16_t y, uint16_t z)
		{
			x &= 0x1F; y &= 0x3F; z &= 0x1F;
			v = (z << 11) | (y << 5) | x;
		}
		dmXMU565(float _x, float _y, float _z)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreU565((XMU565*)m_handle.ToPointer(), XMVectorSet(_x, _y, _z, 0.0f));
			v = (uint16_t)Marshal::PtrToStructure(m_handle, uint16_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMU565([Out] uint16_t% x, [Out] uint16_t% y, [Out] uint16_t% z)
		{
			x = v & 0x1F;
			y = (v >> 5) & 0x3F;
			z = (v >> 11) & 0x1F;
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMUBYTE2
	{
		[FieldOffset(0)]
		uint8_t x;
		[FieldOffset(1)]
		uint8_t y;
		[FieldOffset(0)]
		uint16_t v;

		dmXMUBYTE2() {}
		dmXMUBYTE2(uint8_t _x, uint8_t _y) { x = _x; y = _y; }
		dmXMUBYTE2(float _x, float _y)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUByte2((XMUBYTE2*)m_handle.ToPointer(), XMVectorSet(_x, _y, 0.0f, 0.0f));
			v = (uint16_t)Marshal::PtrToStructure(m_handle, uint16_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMUBYTEN2
	{
		[FieldOffset(0)]
		uint8_t x;
		[FieldOffset(1)]
		uint8_t y;
		[FieldOffset(0)]
		uint16_t v;

		dmXMUBYTEN2() {}
		dmXMUBYTEN2(uint8_t _x, uint8_t _y) { x = _x; y = _y; }
		dmXMUBYTEN2(float _x, float _y)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUByteN2((XMUBYTEN2*)m_handle.ToPointer(), XMVectorSet(_x, _y, 0.0f, 0.0f));
			v = (uint16_t)Marshal::PtrToStructure(m_handle, uint16_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMUBYTE4
	{
		[FieldOffset(0)]
		uint8_t x;
		[FieldOffset(1)]
		uint8_t y;
		[FieldOffset(2)]
		uint8_t z;
		[FieldOffset(3)]
		uint8_t w;
		[FieldOffset(0)]
		uint32_t v;

		dmXMUBYTE4() {}
		dmXMUBYTE4(uint8_t _x, uint8_t _y, uint8_t _z, uint8_t _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMUBYTE4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUByte4((XMUBYTE4*)m_handle.ToPointer(), XMVectorSet(_x, _y, _z, _w));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMUBYTEN4
	{
		[FieldOffset(0)]
		uint8_t x;
		[FieldOffset(1)]
		uint8_t y;
		[FieldOffset(2)]
		uint8_t z;
		[FieldOffset(3)]
		uint8_t w;
		[FieldOffset(0)]
		uint32_t v;

		dmXMUBYTEN4() {}
		dmXMUBYTEN4(uint8_t _x, uint8_t _y, uint8_t _z, uint8_t _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMUBYTEN4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUByteN4((XMUBYTEN4*)m_handle.ToPointer(), XMVectorSet(_x, _y, _z, _w));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMUDEC4
	{
		uint32_t v;

		dmXMUDEC4() {};
		dmXMUDEC4(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
		{
			w &= 3;  x &= 0x3FF; y &= 0x3FF; z &= 0x3FF;
			v = (w << 30) | (z << 20) | (y << 10) | x;
		}
		dmXMUDEC4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUDec4((XMUDEC4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMUDEC4([Out] uint32_t% x, [Out] uint32_t% y, [Out] uint32_t% z, [Out] uint32_t% w)
		{
			x = v & 0x3FF;
			y = (v >> 10) & 0x3FF;
			z = (v >> 20) & 0x3FF;
			w = (v >> 30) & 3;
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMUDECN4
	{
		uint32_t v;

		dmXMUDECN4() {};
		dmXMUDECN4(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
		{
			w &= 3;  x &= 0x3FF; y &= 0x3FF; z &= 0x3FF;
			v = (w << 30) | (z << 20) | (y << 10) | x;
		}
		dmXMUDECN4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUDecN4((XMUDECN4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMUDECN4([Out] uint32_t% x, [Out] uint32_t% y, [Out] uint32_t% z, [Out] uint32_t% w)
		{
			x = v & 0x3FF;
			y = (v >> 10) & 0x3FF;
			z = (v >> 20) & 0x3FF;
			w = (v >> 30) & 3;
		}
	};


	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMUINT2
	{
		uint32_t x, y;

		dmXMUINT2() {};
		dmXMUINT2(uint32_t _x, uint32_t _y) { x = _x;y = _y; };
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMUINT3
	{
		uint32_t x, y, z;

		dmXMUINT3() {};
		dmXMUINT3(uint32_t _x, uint32_t _y, uint32_t _z) { x = _x;y = _y; z = _z; };
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMUINT4
	{
		uint32_t x, y, z, w;

		dmXMUINT4() {};
		dmXMUINT4(uint32_t _x, uint32_t _y, uint32_t _z, uint32_t _w) { x = _x;y = _y; z = _z; w = _w; };
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMUNIBBLE4
	{
		uint16_t v;

		dmXMUNIBBLE4() {};
		dmXMUNIBBLE4(uint16_t x, uint16_t y, uint16_t z, uint16_t w)
		{
			w &= 0xF;  x &= 0xF; y &= 0xF; z &= 0xF;
			v = (w << 12) | (z << 8) | (y << 4) | x;
		}
		dmXMUNIBBLE4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUNibble4((XMUNIBBLE4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint16_t)Marshal::PtrToStructure(m_handle, uint16_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMUNIBBLE4([Out] uint16_t% x, [Out] uint16_t% y, [Out] uint16_t% z, [Out] uint16_t% w)
		{
			x = v & 0xF;
			y = (v >> 4) & 0xF;
			z = (v >> 8) & 0xF;
			w = (v >> 12) & 0xF;
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMUSHORT2
	{
		[FieldOffset(0)]
		uint16_t x;
		[FieldOffset(2)]
		uint16_t y;
		[FieldOffset(0)]
		uint32_t v;

		dmXMUSHORT2() {}
		dmXMUSHORT2(uint16_t _x, uint16_t _y) { x = _x; y = _y; }
		dmXMUSHORT2(float _x, float _y)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUShort2((XMUSHORT2*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, 0.0f, 0.0f));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMUSHORTN2
	{
		[FieldOffset(0)]
		uint16_t x;
		[FieldOffset(2)]
		uint16_t y;
		[FieldOffset(0)]
		uint32_t v;

		dmXMUSHORTN2() {}
		dmXMUSHORTN2(uint16_t _x, uint16_t _y) { x = _x; y = _y; }
		dmXMUSHORTN2(float _x, float _y)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUShortN2((XMUSHORTN2*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, 0.0f, 0.0f));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMUSHORT4
	{
		[FieldOffset(0)]
		uint16_t x;
		[FieldOffset(2)]
		uint16_t y;
		[FieldOffset(4)]
		uint16_t z;
		[FieldOffset(6)]
		uint16_t w;
		[FieldOffset(0)]
		uint64_t v;

		dmXMUSHORT4() {}
		dmXMUSHORT4(uint16_t _x, uint16_t _y, uint16_t _z, uint16_t _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMUSHORT4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUShort4((XMUSHORT4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint64_t)Marshal::PtrToStructure(m_handle, uint64_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Explicit)]
	public ref struct dmXMUSHORTN4
	{
		[FieldOffset(0)]
		uint16_t x;
		[FieldOffset(2)]
		uint16_t y;
		[FieldOffset(4)]
		uint16_t z;
		[FieldOffset(6)]
		uint16_t w;
		[FieldOffset(0)]
		uint64_t v;

		dmXMUSHORTN4() {}
		dmXMUSHORTN4(uint16_t _x, uint16_t _y, uint16_t _z, uint16_t _w) { x = _x; y = _y; z = _z; w = _w; }
		dmXMUSHORTN4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreUShortN4((XMUSHORTN4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint64_t)Marshal::PtrToStructure(m_handle, uint64_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMXDEC4
	{
		uint32_t v;

		dmXMXDEC4() {}
		dmXMXDEC4(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
		{
			w &= 0x3;  x &= 0x3FF; y &= 0x3FF; z &= 0x3FF;
			v = (w << 30) | (z << 20) | (y << 10) | x;
		}
		dmXMXDEC4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreXDec4((XMXDEC4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMXDEC4([Out] int32_t% x, [Out] int32_t% y, [Out] int32_t% z, [Out] int32_t% w)
		{
			x = v & 0x3FF;
			y = (v >> 10) & 0x3FF;
			z = (v >> 20) & 0x3FF;
			w = (v >> 30) & 3;
		}
	};

	[StructLayout(LayoutKind::Sequential)]
	public ref struct dmXMXDECN4
	{
		uint32_t v;

		dmXMXDECN4() {}
		dmXMXDECN4(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
		{
			w &= 0x3;  x &= 0x3FF; y &= 0x3FF; z &= 0x3FF;
			v = (w << 30) | (z << 20) | (y << 10) | x;
		}
		dmXMXDECN4(float _x, float _y, float _z, float _w)
		{
			IntPtr m_handle = static_cast<IntPtr>(GCHandle::Alloc(this, GCHandleType::Pinned));
			DDMath::XMStoreXDecN4((XMXDECN4*)m_handle.ToPointer(), DDMath::XMVectorSet(_x, _y, _z, _w));
			v = (uint32_t)Marshal::PtrToStructure(m_handle, uint32_t::typeid);
			static_cast<GCHandle>(m_handle).Free();
		}
		void decomposeXMXDECN4([Out] int32_t% x, [Out] int32_t% y, [Out] int32_t% z, [Out] int32_t% w)
		{
			x = v & 0x3FF;
			y = (v >> 10) & 0x3FF;
			z = (v >> 20) & 0x3FF;
			w = (v >> 30) & 3;
		}
	};

	public ref struct DMathClass
	{
	public:

		// Color Functions - Start
		inline static dmXMVECTOR^ XMColorSRGBToRGB(dmXMVECTOR^ srgb)
		{
			XMVECTOR xsrgb;
			int thesize = Marshal::SizeOf(srgb);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(srgb, pnt, false);
			memcpy(&xsrgb, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorSRGBToRGB(xsrgb);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorRGBToSRGB(dmXMVECTOR^ rgb)
		{
			XMVECTOR xrgb;
			int thesize = Marshal::SizeOf(rgb);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(rgb, pnt, false);
			memcpy(&xrgb, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorRGBToSRGB(xrgb);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorAdjustContrast(dmXMVECTOR^ vColor, float fContrast)
		{
			XMVECTOR xvColor;
			int thesize = Marshal::SizeOf(vColor);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor, pnt, false);
			memcpy(&xvColor, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorAdjustContrast(xvColor, fContrast);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorAdjustSaturation(dmXMVECTOR^ vColor, float fContrast)
		{
			XMVECTOR xvColor;
			int thesize = Marshal::SizeOf(vColor);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor, pnt, false);
			memcpy(&xvColor, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorAdjustSaturation(xvColor, fContrast);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMColorEqual(dmXMVECTOR^ vColor1, dmXMVECTOR^ vColor2)
		{
			XMVECTOR xvColor1;
			XMVECTOR xvColor2;
			int thesize = Marshal::SizeOf(vColor1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor1, pnt, false);
			memcpy(&xvColor1, (void*)pnt, thesize);
			Marshal::StructureToPtr(vColor2, pnt, true);
			memcpy(&xvColor2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMColorEqual(xvColor1, xvColor2);
		}
		inline static bool XMColorGreater(dmXMVECTOR^ vColor1, dmXMVECTOR^ vColor2)
		{
			XMVECTOR xvColor1;
			XMVECTOR xvColor2;
			int thesize = Marshal::SizeOf(vColor1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor1, pnt, false);
			memcpy(&xvColor1, (void*)pnt, thesize);
			Marshal::StructureToPtr(vColor2, pnt, true);
			memcpy(&xvColor2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMColorGreater(xvColor1, xvColor2);
		}
		inline static bool XMColorGreaterOrEqual(dmXMVECTOR^ vColor1, dmXMVECTOR^ vColor2)
		{
			XMVECTOR xvColor1;
			XMVECTOR xvColor2;
			int thesize = Marshal::SizeOf(vColor1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor1, pnt, false);
			memcpy(&xvColor1, (void*)pnt, thesize);
			Marshal::StructureToPtr(vColor2, pnt, true);
			memcpy(&xvColor2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMColorGreaterOrEqual(xvColor1, xvColor2);
		}
		inline static dmXMVECTOR^ XMColorHSLToRGB(dmXMVECTOR^ hsl)
		{
			XMVECTOR xHsl;
			int thesize = Marshal::SizeOf(hsl);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(hsl, pnt, false);
			memcpy(&xHsl, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorHSLToRGB(xHsl);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorHSVToRGB(dmXMVECTOR^ hsv)
		{
			XMVECTOR xHsv;
			int thesize = Marshal::SizeOf(hsv);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(hsv, pnt, false);
			memcpy(&xHsv, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorHSVToRGB(xHsv);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMColorIsInfinite(dmXMVECTOR^ vColor)
		{
			XMVECTOR xvColor;
			int thesize = Marshal::SizeOf(vColor);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor, pnt, false);
			memcpy(&xvColor, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMColorIsInfinite(xvColor);
		}
		inline static bool XMColorIsNaN(dmXMVECTOR^ vColor)
		{
			XMVECTOR xvColor;
			int thesize = Marshal::SizeOf(vColor);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor, pnt, false);
			memcpy(&xvColor, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMColorIsNaN(xvColor);
		}
		inline static bool XMColorLess(dmXMVECTOR^ vColor1, dmXMVECTOR^ vColor2)
		{
			XMVECTOR xvColor1;
			XMVECTOR xvColor2;
			int thesize = Marshal::SizeOf(vColor1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor1, pnt, false);
			memcpy(&xvColor1, (void*)pnt, thesize);
			Marshal::StructureToPtr(vColor2, pnt, true);
			memcpy(&xvColor2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMColorLess(xvColor1, xvColor2);
		}
		inline static bool XMColorLessOrEqual(dmXMVECTOR^ vColor1, dmXMVECTOR^ vColor2)
		{
			XMVECTOR xvColor1;
			XMVECTOR xvColor2;
			int thesize = Marshal::SizeOf(vColor1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor1, pnt, false);
			memcpy(&xvColor1, (void*)pnt, thesize);
			Marshal::StructureToPtr(vColor2, pnt, true);
			memcpy(&xvColor2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMColorLessOrEqual(xvColor1, xvColor2);
		}
		inline static dmXMVECTOR^ XMColorModulate(dmXMVECTOR^ vColor1, dmXMVECTOR^ vColor2)
		{
			XMVECTOR xvColor1;
			XMVECTOR xvColor2;
			int thesize = Marshal::SizeOf(vColor1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor1, pnt, false);
			memcpy(&xvColor1, (void*)pnt, thesize);
			Marshal::StructureToPtr(vColor2, pnt, true);
			memcpy(&xvColor2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorModulate(xvColor1, xvColor2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorNegative(dmXMVECTOR^ vColor)
		{
			XMVECTOR xvColor;
			int thesize = Marshal::SizeOf(vColor);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor, pnt, false);
			memcpy(&xvColor, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorNegative(xvColor);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMColorNotEqual(dmXMVECTOR^ vColor1, dmXMVECTOR^ vColor2)
		{
			XMVECTOR xvColor1;
			XMVECTOR xvColor2;
			int thesize = Marshal::SizeOf(vColor1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vColor1, pnt, false);
			memcpy(&xvColor1, (void*)pnt, thesize);
			Marshal::StructureToPtr(vColor2, pnt, true);
			memcpy(&xvColor2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMColorNotEqual(xvColor1, xvColor2);
		}
		inline static dmXMVECTOR^ XMColorRGBToHSL(dmXMVECTOR^ rgb)
		{
			XMVECTOR xrgb;
			int thesize = Marshal::SizeOf(rgb);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(rgb, pnt, false);
			memcpy(&xrgb, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorRGBToHSL(xrgb);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorRGBToHSV(dmXMVECTOR^ rgb)
		{
			XMVECTOR xrgb;
			int thesize = Marshal::SizeOf(rgb);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(rgb, pnt, false);
			memcpy(&xrgb, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorRGBToHSV(xrgb);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorRGBToXYZ(dmXMVECTOR^ rgb)
		{
			XMVECTOR xrgb;
			int thesize = Marshal::SizeOf(rgb);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(rgb, pnt, false);
			memcpy(&xrgb, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorRGBToXYZ(xrgb);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorRGBToYUV(dmXMVECTOR^ rgb)
		{
			XMVECTOR xrgb;
			int thesize = Marshal::SizeOf(rgb);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(rgb, pnt, false);
			memcpy(&xrgb, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorRGBToYUV(xrgb);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorRGBToYUV_HD(dmXMVECTOR^ rgb)
		{
			XMVECTOR xrgb;
			int thesize = Marshal::SizeOf(rgb);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(rgb, pnt, false);
			memcpy(&xrgb, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorRGBToYUV_HD(xrgb);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorSRGBToXYZ(dmXMVECTOR^ rgb)
		{
			XMVECTOR xrgb;
			int thesize = Marshal::SizeOf(rgb);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(rgb, pnt, false);
			memcpy(&xrgb, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorSRGBToXYZ(xrgb);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorXYZToRGB(dmXMVECTOR^ xyz)
		{
			XMVECTOR xXyz;
			int thesize = Marshal::SizeOf(xyz);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(xyz, pnt, false);
			memcpy(&xXyz, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorXYZToRGB(xXyz);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorXYZToSRGB(dmXMVECTOR^ xyz)
		{
			XMVECTOR xXyz;
			int thesize = Marshal::SizeOf(xyz);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(xyz, pnt, false);
			memcpy(&xXyz, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorXYZToSRGB(xXyz);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorYUVToRGB(dmXMVECTOR^ yuv)
		{
			XMVECTOR xYuv;
			int thesize = Marshal::SizeOf(yuv);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(yuv, pnt, false);
			memcpy(&xYuv, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorYUVToRGB(xYuv);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMColorYUVToRGB_HD(dmXMVECTOR^ yuv)
		{
			XMVECTOR xYuv;
			int thesize = Marshal::SizeOf(yuv);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(yuv, pnt, false);
			memcpy(&xYuv, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMColorYUVToRGB_HD(xYuv);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Color Functions - End

		// Conversion Functions - Start
		inline static HALF XMConvertFloatToHalf(float Value)
		{
			return DDMath::XMConvertFloatToHalf(Value);
		}
		inline static void XMConvertFloatToHalfStream([Out] array<HALF>^% pOutputStream, uint32_t OutputStride, array<float>^ pInputStream, int32_t InputStride, int32_t FloatCount)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<HALF>(FloatCount);
			}
			pin_ptr<float> locaInputStream = &pInputStream[0];
			pin_ptr<HALF> locaOutputStream = &pOutputStream[0];
			DDMath::XMConvertFloatToHalfStream(locaOutputStream, OutputStride, locaInputStream, InputStride, FloatCount);
			return;
		}
		inline static float XMConvertHalfToFloat(HALF Value)
		{
			return DDMath::XMConvertHalfToFloat(Value);
		}
		inline static void XMConvertHalfToFloatStream([Out] array<float>^% pOutputStream, uint32_t OutputStride, array<HALF>^ pInputStream, int32_t InputStride, int32_t FloatCount)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<float>(FloatCount);
			}

			assert(pOutputStream);
			assert(pInputStream);
			assert(InputStride >= sizeof(HALF));
			assert(OutputStride >= sizeof(float));
			pin_ptr<HALF> locaInputStream = &pInputStream[0];
			pin_ptr<float> locaOutputStream = &pOutputStream[0];
			DDMath::XMConvertHalfToFloatStream(locaOutputStream, OutputStride, locaInputStream, InputStride, FloatCount);
			return;
		}
		inline static float XMConvertToDegrees(float Value)
		{
			return DDMath::XMConvertToDegrees(Value);
		}
		inline static float XMConvertToRadians(float Value)
		{
			return DDMath::XMConvertToRadians(Value);
		}
		inline static dmXMVECTOR^ XMConvertVectorFloatToInt(dmXMVECTOR^ vFloat, uint32_t MulExponent)
		{
			XMVECTOR xvFloat;
			int thesize = Marshal::SizeOf(vFloat);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vFloat, pnt, false);
			memcpy(&xvFloat, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMConvertVectorFloatToInt(xvFloat, MulExponent);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMConvertVectorFloatToUInt(dmXMVECTOR^ vFloat, uint32_t MulExponent)
		{
			XMVECTOR xvFloat;
			int thesize = Marshal::SizeOf(vFloat);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vFloat, pnt, false);
			memcpy(&xvFloat, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMConvertVectorFloatToUInt(xvFloat, MulExponent);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMConvertVectorIntToFloat(dmXMVECTOR^ vInt, uint32_t DivExponent)
		{
			XMVECTOR xvInt;
			int thesize = Marshal::SizeOf(vInt);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vInt, pnt, false);
			memcpy(&xvInt, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMConvertVectorIntToFloat(xvInt, DivExponent);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMConvertVectorUIntToFloat(dmXMVECTOR^ vUInt, uint32_t DivExponent)
		{
			XMVECTOR xvUInt;
			int thesize = Marshal::SizeOf(vUInt);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(vUInt, pnt, false);
			memcpy(&xvUInt, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMConvertVectorUIntToFloat(xvUInt, DivExponent);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}

		// Conversion Functions -End

		// Matrix Functions . Start

		inline static dmXMMATRIX^ XMMatrixAffineTransformation(dmXMVECTOR^ Scaling, dmXMVECTOR^ RotationOrigin, dmXMVECTOR^ RotationQuaternion, dmXMVECTOR^ Translation)
		{
			XMVECTOR xScaling;
			XMVECTOR xRotationOrigin;
			XMVECTOR xRotationQuaternion;
			XMVECTOR xTranslation;
			int thesize = Marshal::SizeOf(Scaling);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Scaling, pnt, false);
			memcpy(&xScaling, (void*)pnt, thesize);
			Marshal::StructureToPtr(RotationOrigin, pnt, true);
			memcpy(&xRotationOrigin, (void*)pnt, thesize);
			Marshal::StructureToPtr(RotationQuaternion, pnt, true);
			memcpy(&xRotationQuaternion, (void*)pnt, thesize);
			Marshal::StructureToPtr(Translation, pnt, true);
			memcpy(&xTranslation, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixAffineTransformation(xScaling, xRotationOrigin, xRotationQuaternion, xTranslation);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixAffineTransformation2D(dmXMVECTOR^ Scaling, dmXMVECTOR^ RotationOrigin, float Rotation, dmXMVECTOR^ Translation)
		{
			XMVECTOR xScaling;
			XMVECTOR xRotationOrigin;
			XMVECTOR xTranslation;
			int thesize = Marshal::SizeOf(Scaling);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Scaling, pnt, false);
			memcpy(&xScaling, (void*)pnt, thesize);
			Marshal::StructureToPtr(RotationOrigin, pnt, true);
			memcpy(&xRotationOrigin, (void*)pnt, thesize);
			Marshal::StructureToPtr(Translation, pnt, true);
			memcpy(&xTranslation, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixAffineTransformation2D(xScaling, xRotationOrigin, Rotation, xTranslation);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static bool XMMatrixDecompose([Out] dmXMVECTOR^% outScale, [Out] dmXMVECTOR^% outRotQuat, [Out] dmXMVECTOR^% outTrans, dmXMMATRIX^ M)
		{
			if (outScale == nullptr)
			{
				outScale = gcnew dmXMVECTOR();
			}
			if (outRotQuat == nullptr)
			{
				outRotQuat = gcnew dmXMVECTOR();
			}
			if (outTrans == nullptr)
			{
				outTrans = gcnew dmXMVECTOR();
			}

			assert(outScale != nullptr);
			assert(outRotQuat != nullptr);
			assert(outTrans != nullptr);

			XMVECTOR xoutScale;
			XMVECTOR xoutRotQuat;
			XMVECTOR xoutTrans;
			XMMATRIX xM;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			bool retBool = DDMath::XMMatrixDecompose(&xoutScale, &xoutRotQuat, &xoutTrans, xM);
			if (retBool)
			{
				thesize = Marshal::SizeOf(outScale);
				memcpy((void*)pnt, &xoutScale, thesize);
				Marshal::PtrToStructure(pnt, outScale);
				memcpy((void*)pnt, &xoutRotQuat, thesize);
				Marshal::PtrToStructure(pnt, outRotQuat);
				memcpy((void*)pnt, &xoutTrans, thesize);
				Marshal::PtrToStructure(pnt, outTrans);
			}
			Marshal::FreeHGlobal(pnt);
			return retBool;
		}
		inline static dmXMVECTOR^ XMMatrixDeterminant(dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMMatrixDeterminant(xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMMATRIX^ XMMatrixIdentity()
		{
			XMMATRIX xM = DDMath::XMMatrixIdentity();
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &xM, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixInverse([Out] dmXMVECTOR^% pDeterminant, dmXMMATRIX^ M)
		{
			if (pDeterminant == nullptr)
			{
				pDeterminant = gcnew dmXMVECTOR();
			}
			XMMATRIX xM;
			XMVECTOR xpDeterminant;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			XMMATRIX result = DDMath::XMMatrixInverse(&xpDeterminant, xM);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			thesize = Marshal::SizeOf(pDeterminant);
			memcpy((void*)pnt, &xpDeterminant, thesize);
			Marshal::PtrToStructure(pnt, pDeterminant);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static bool XMMatrixIsIdentity(dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMMatrixIsIdentity(xM);
		}
		inline static bool XMMatrixIsInfinite(dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMMatrixIsInfinite(xM);
		}
		inline static bool XMMatrixIsNaN(dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMMatrixIsNaN(xM);
		}
		inline static dmXMMATRIX^ XMMatrixLookAtLH(dmXMVECTOR^ EyePosition, dmXMVECTOR^ FocusPosition, dmXMVECTOR^ UpDirection)
		{
			XMVECTOR xEyePosition;
			XMVECTOR xFocusPosition;
			XMVECTOR xUpDirection;
			int thesize = Marshal::SizeOf(EyePosition);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(EyePosition, pnt, false);
			memcpy(&xEyePosition, (void*)pnt, thesize);
			Marshal::StructureToPtr(FocusPosition, pnt, true);
			memcpy(&xFocusPosition, (void*)pnt, thesize);
			Marshal::StructureToPtr(UpDirection, pnt, true);
			memcpy(&xUpDirection, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixLookAtLH(xEyePosition, xFocusPosition, xUpDirection);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}

		inline static dmXMMATRIX^ XMMatrixLookAtRH(dmXMVECTOR^ EyePosition, dmXMVECTOR^ FocusPosition, dmXMVECTOR^ UpDirection)
		{
			XMVECTOR xEyePosition;
			XMVECTOR xFocusPosition;
			XMVECTOR xUpDirection;
			int thesize = Marshal::SizeOf(EyePosition);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(EyePosition, pnt, false);
			memcpy(&xEyePosition, (void*)pnt, thesize);
			Marshal::StructureToPtr(FocusPosition, pnt, true);
			memcpy(&xFocusPosition, (void*)pnt, thesize);
			Marshal::StructureToPtr(UpDirection, pnt, true);
			memcpy(&xUpDirection, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixLookAtRH(xEyePosition, xFocusPosition, xUpDirection);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixLookToLH(dmXMVECTOR^ EyePosition, dmXMVECTOR^ EyeDirection, dmXMVECTOR^ UpDirection)
		{
			XMVECTOR xEyePosition;
			XMVECTOR xEyeDirection;
			XMVECTOR xUpDirection;
			int thesize = Marshal::SizeOf(EyePosition);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(EyePosition, pnt, false);
			memcpy(&xEyePosition, (void*)pnt, thesize);
			Marshal::StructureToPtr(EyeDirection, pnt, true);
			memcpy(&xEyeDirection, (void*)pnt, thesize);
			Marshal::StructureToPtr(UpDirection, pnt, true);
			memcpy(&xUpDirection, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			assert(!DDMath::XMVector3Equal(xEyeDirection, DDMath::XMVectorZero()));
			assert(!DDMath::XMVector3IsInfinite(xEyeDirection));
			assert(!DDMath::XMVector3Equal(xUpDirection, DDMath::XMVectorZero()));
			assert(!DDMath::XMVector3IsInfinite(xUpDirection));

			XMMATRIX mat = DDMath::XMMatrixLookToLH(xEyePosition, xEyeDirection, xUpDirection);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixLookToRH(dmXMVECTOR^ EyePosition, dmXMVECTOR^ FocusPosition, dmXMVECTOR^ UpDirection)
		{
			XMVECTOR xEyePosition;
			XMVECTOR xFocusPosition;
			XMVECTOR xUpDirection;
			int thesize = Marshal::SizeOf(EyePosition);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(EyePosition, pnt, false);
			memcpy(&xEyePosition, (void*)pnt, thesize);
			Marshal::StructureToPtr(FocusPosition, pnt, true);
			memcpy(&xFocusPosition, (void*)pnt, thesize);
			Marshal::StructureToPtr(UpDirection, pnt, true);
			memcpy(&xUpDirection, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixLookToRH(xEyePosition, xFocusPosition, xUpDirection);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixMultiply(dmXMMATRIX^ M1, dmXMMATRIX^ M2)
		{
			XMMATRIX xM1;
			XMMATRIX xM2;
			int thesize = Marshal::SizeOf(M1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M1, pnt, false);
			memcpy(&xM1, (void*)pnt, thesize);
			Marshal::StructureToPtr(M2, pnt, true);
			memcpy(&xM2, (void*)pnt, thesize);
			XMMATRIX result = DDMath::XMMatrixMultiply(xM1, xM2);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixMultiplyTranspose(dmXMMATRIX^ M1, dmXMMATRIX^ M2)
		{
			XMMATRIX xM1;
			XMMATRIX xM2;
			int thesize = Marshal::SizeOf(M1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M1, pnt, false);
			memcpy(&xM1, (void*)pnt, thesize);
			Marshal::StructureToPtr(M2, pnt, true);
			memcpy(&xM2, (void*)pnt, thesize);
			XMMATRIX result = DDMath::XMMatrixMultiplyTranspose(xM1, xM2);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixOrthographicLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(ViewWidth, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(ViewHeight, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixOrthographicLH(ViewWidth, ViewHeight, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixOrthographicOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(ViewRight, ViewLeft, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(ViewTop, ViewBottom, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixOrthographicOffCenterLH(ViewLeft, ViewRight, ViewBottom, ViewTop, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixOrthographicOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(ViewRight, ViewLeft, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(ViewTop, ViewBottom, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixOrthographicOffCenterRH(ViewLeft, ViewRight, ViewBottom, ViewTop, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixOrthographicRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(ViewWidth, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(ViewHeight, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixOrthographicRH(ViewWidth, ViewHeight, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixPerspectiveFovLH(float FovAngleY, float AspectHByW, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(FovAngleY, 0.0f, 0.00001f * 2.0f));
			assert(!DDMath::XMScalarNearEqual(AspectHByW, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixPerspectiveFovLH(FovAngleY, AspectHByW, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixPerspectiveFovRH(float FovAngleY, float AspectHByW, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(FovAngleY, 0.0f, 0.00001f * 2.0f));
			assert(!DDMath::XMScalarNearEqual(AspectHByW, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixPerspectiveFovRH(FovAngleY, AspectHByW, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixPerspectiveLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(ViewWidth, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(ViewHeight, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixPerspectiveLH(ViewWidth, ViewHeight, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixPerspectiveOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(ViewRight, ViewLeft, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(ViewTop, ViewBottom, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixPerspectiveOffCenterLH(ViewLeft, ViewRight, ViewBottom, ViewTop, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixPerspectiveOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(ViewRight, ViewLeft, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(ViewTop, ViewBottom, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixPerspectiveOffCenterRH(ViewLeft, ViewRight, ViewBottom, ViewTop, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixPerspectiveRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ)
		{
			assert(!DDMath::XMScalarNearEqual(ViewWidth, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(ViewHeight, 0.0f, 0.00001f));
			assert(!DDMath::XMScalarNearEqual(FarZ, NearZ, 0.00001f));
			XMMATRIX result = DDMath::XMMatrixPerspectiveRH(ViewWidth, ViewHeight, NearZ, FarZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixReflect(dmXMVECTOR^ ReflectionPlane)
		{
			XMVECTOR xReflectionPlane;
			int thesize = Marshal::SizeOf(ReflectionPlane);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(ReflectionPlane, pnt, false);
			memcpy(&xReflectionPlane, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			assert(!DDMath::XMVector3Equal(xReflectionPlane, DDMath::XMVectorZero()));
			assert(!DDMath::XMPlaneIsInfinite(xReflectionPlane));

			XMMATRIX mat = DDMath::XMMatrixReflect(xReflectionPlane);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixRotationAxis(dmXMVECTOR^ Axis, float Angle)
		{
			XMVECTOR xAxis;
			int thesize = Marshal::SizeOf(Axis);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Axis, pnt, false);
			memcpy(&xAxis, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			assert(!DDMath::XMVector3Equal(xAxis, DDMath::XMVectorZero()));
			assert(!DDMath::XMVector3IsInfinite(xAxis));
			XMMATRIX mat = DDMath::XMMatrixRotationAxis(xAxis, Angle);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixRotationNormal(dmXMVECTOR^ NormalAxis, float Angle)
		{
			XMVECTOR xNormalAxis;
			int thesize = Marshal::SizeOf(NormalAxis);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(NormalAxis, pnt, false);
			memcpy(&xNormalAxis, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixRotationNormal(xNormalAxis, Angle);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixRotationQuaternion(dmXMVECTOR^ Quaternion)
		{
			XMVECTOR xQuaternion;
			int thesize = Marshal::SizeOf(Quaternion);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Quaternion, pnt, false);
			memcpy(&xQuaternion, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixRotationQuaternion(xQuaternion);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixRotationRollPitchYaw(float Pitch, float Yaw, float Roll)
		{
			XMMATRIX result = DDMath::XMMatrixRotationRollPitchYaw(Pitch, Yaw, Roll);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixRotationRollPitchYawFromVector(dmXMVECTOR^ Angles)
		{
			XMVECTOR xAngles;
			int thesize = Marshal::SizeOf(Angles);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Angles, pnt, false);
			memcpy(&xAngles, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixRotationRollPitchYawFromVector(xAngles);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixRotationX(float Angle)
		{
			XMMATRIX result = DDMath::XMMatrixRotationX(Angle);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixRotationY(float Angle)
		{
			XMMATRIX result = DDMath::XMMatrixRotationY(Angle);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixRotationZ(float Angle)
		{
			XMMATRIX result = DDMath::XMMatrixRotationZ(Angle);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixScaling(float ScaleX, float ScaleY, float ScaleZ)
		{
			XMMATRIX result = DDMath::XMMatrixScaling(ScaleX, ScaleY, ScaleZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixScalingFromVector(dmXMVECTOR^ Scale)
		{
			XMVECTOR xScale;
			int thesize = Marshal::SizeOf(Scale);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Scale, pnt, false);
			memcpy(&xScale, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixScalingFromVector(xScale);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixSet(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33)
		{
			XMMATRIX result = DDMath::XMMatrixSet(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixShadow(dmXMVECTOR^ ShadowPlane, dmXMVECTOR^ LightPosition)
		{
			XMVECTOR xShadowPlane;
			XMVECTOR xLightPosition;
			int thesize = Marshal::SizeOf(ShadowPlane);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(ShadowPlane, pnt, false);
			memcpy(&xShadowPlane, (void*)pnt, thesize);
			Marshal::StructureToPtr(LightPosition, pnt, true);
			memcpy(&xLightPosition, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			assert(!DDMath::XMVector3Equal(xShadowPlane, DDMath::XMVectorZero()));
			assert(!DDMath::XMPlaneIsInfinite(xShadowPlane));
			XMMATRIX mat = DDMath::XMMatrixShadow(xShadowPlane, xLightPosition);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixTransformation(dmXMVECTOR^ ScalingOrigin, dmXMVECTOR^ ScalingOrientationQuaternion,
			dmXMVECTOR^ Scaling, dmXMVECTOR^ RotationOrigin, dmXMVECTOR^ RotationQuaternion, dmXMVECTOR^ Translation)
		{
			XMVECTOR xScalingOrigin;
			XMVECTOR xScalingOrientationQuaternion;
			XMVECTOR xScaling;
			XMVECTOR xRotationOrigin;
			XMVECTOR xRotationQuaternion;
			XMVECTOR xTranslation;
			int thesize = Marshal::SizeOf(ScalingOrigin);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(ScalingOrigin, pnt, false);
			memcpy(&xScalingOrigin, (void*)pnt, thesize);
			Marshal::StructureToPtr(ScalingOrientationQuaternion, pnt, true);
			memcpy(&xScalingOrientationQuaternion, (void*)pnt, thesize);
			Marshal::StructureToPtr(Scaling, pnt, true);
			memcpy(&xScaling, (void*)pnt, thesize);
			Marshal::StructureToPtr(RotationOrigin, pnt, true);
			memcpy(&xRotationOrigin, (void*)pnt, thesize);
			Marshal::StructureToPtr(RotationQuaternion, pnt, true);
			memcpy(&xRotationQuaternion, (void*)pnt, thesize);
			Marshal::StructureToPtr(Translation, pnt, true);
			memcpy(&xTranslation, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixTransformation(xScalingOrigin, xScalingOrientationQuaternion, xScaling, xRotationOrigin, xRotationQuaternion, xTranslation);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixTransformation2D(dmXMVECTOR^ ScalingOrigin, float ScalingOrientation,
			dmXMVECTOR^ Scaling, dmXMVECTOR^ RotationOrigin, float Rotation, dmXMVECTOR^ Translation)
		{
			XMVECTOR xScalingOrigin;
			XMVECTOR xScaling;
			XMVECTOR xRotationOrigin;
			XMVECTOR xTranslation;
			int thesize = Marshal::SizeOf(ScalingOrigin);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(ScalingOrigin, pnt, false);
			memcpy(&xScalingOrigin, (void*)pnt, thesize);
			Marshal::StructureToPtr(Scaling, pnt, true);
			memcpy(&xScaling, (void*)pnt, thesize);
			Marshal::StructureToPtr(RotationOrigin, pnt, true);
			memcpy(&xRotationOrigin, (void*)pnt, thesize);
			Marshal::StructureToPtr(Translation, pnt, true);
			memcpy(&xTranslation, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixTransformation2D(xScalingOrigin, ScalingOrientation, xScaling, xRotationOrigin, Rotation, xTranslation);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixTranslation(float OffsetX, float OffsetY, float OffsetZ)
		{
			XMMATRIX result = DDMath::XMMatrixTranslation(OffsetX, OffsetY, OffsetZ);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			int thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixTranslationFromVector(dmXMVECTOR^ Offset)
		{
			XMVECTOR xOffset;
			int thesize = Marshal::SizeOf(Offset);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Offset, pnt, false);
			memcpy(&xOffset, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			XMMATRIX mat = DDMath::XMMatrixTranslationFromVector(xOffset);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &mat, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMMatrixTranspose(dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			XMMATRIX matRet = DDMath::XMMatrixTranspose(xM);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			memcpy((void*)pnt, &matRet, thesize);
			Marshal::PtrToStructure(pnt, mydmXMMATRIX);
			Marshal::FreeHGlobal(pnt);
			return mydmXMMATRIX;
		}

		// Matrix Functions - End

		// Library Plane Functions - Start

		inline static dmXMVECTOR^ XMPlaneDot(dmXMVECTOR^ P, dmXMVECTOR^ V)
		{
			XMVECTOR xP;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneDot(xP, xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMPlaneDotCoord(dmXMVECTOR^ P, dmXMVECTOR^ V)
		{
			XMVECTOR xP;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneDotCoord(xP, xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMPlaneDotNormal(dmXMVECTOR^ P, dmXMVECTOR^ V)
		{
			XMVECTOR xP;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneDotNormal(xP, xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMPlaneEqual(dmXMVECTOR^ P, dmXMVECTOR^ V)
		{
			XMVECTOR xP;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMPlaneEqual(xP, xV);
		}
		inline static dmXMVECTOR^ XMPlaneFromPointNormal(dmXMVECTOR^ Point, dmXMVECTOR^ Normal)
		{
			XMVECTOR xPoint;
			XMVECTOR xNormal;
			int thesize = Marshal::SizeOf(Point);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Point, pnt, false);
			memcpy(&xPoint, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneFromPointNormal(xPoint, xNormal);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMPlaneFromPoints(dmXMVECTOR^ Point1, dmXMVECTOR^ Point2, dmXMVECTOR^ Point3)
		{
			XMVECTOR xPoint1;
			XMVECTOR xPoint2;
			XMVECTOR xPoint3;
			int thesize = Marshal::SizeOf(Point1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Point1, pnt, false);
			memcpy(&xPoint1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Point2, pnt, true);
			memcpy(&xPoint2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Point3, pnt, true);
			memcpy(&xPoint3, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneFromPoints(xPoint1, xPoint2, xPoint3);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMPlaneIntersectLine(dmXMVECTOR^ P, dmXMVECTOR^ LinePoint1, dmXMVECTOR^ LinePoint2)
		{
			XMVECTOR xP;
			XMVECTOR xLinePoint1;
			XMVECTOR xLinePoint2;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			Marshal::StructureToPtr(LinePoint1, pnt, true);
			memcpy(&xLinePoint1, (void*)pnt, thesize);
			Marshal::StructureToPtr(LinePoint2, pnt, true);
			memcpy(&xLinePoint2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneIntersectLine(xP, xLinePoint1, xLinePoint2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMPlaneIntersectPlane([Out] dmXMVECTOR^% pLinePoint1, [Out] dmXMVECTOR^% pLinePoint2, dmXMVECTOR^ P1, dmXMVECTOR^ P2)
		{
			if (pLinePoint1 == nullptr)
			{
				pLinePoint1 = gcnew dmXMVECTOR();
			}
			if (pLinePoint2 == nullptr)
			{
				pLinePoint2 = gcnew dmXMVECTOR();
			}

			assert(!(pLinePoint1 == nullptr));
			assert(!(pLinePoint2 == nullptr));

			XMVECTOR xpLinePoint1;
			XMVECTOR xpLinePoint2;
			XMVECTOR xP1;
			XMVECTOR xP2;
			int thesize = Marshal::SizeOf(P1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P1, pnt, false);
			memcpy(&xP1, (void*)pnt, thesize);
			Marshal::StructureToPtr(P2, pnt, true);
			memcpy(&xP2, (void*)pnt, thesize);
			DDMath::XMPlaneIntersectPlane(&xpLinePoint1, &xpLinePoint2, xP1, xP2);
			memcpy((void*)pnt, &xpLinePoint1, thesize);
			Marshal::PtrToStructure(pnt, pLinePoint1);
			memcpy((void*)pnt, &xpLinePoint2, thesize);
			Marshal::PtrToStructure(pnt, pLinePoint2);
			Marshal::FreeHGlobal(pnt);
		}
		inline static bool XMPlaneIsInfinite(dmXMVECTOR^ P)
		{
			XMVECTOR xP;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMPlaneIsInfinite(xP);
		}
		inline static bool XMPlaneIsNaN(dmXMVECTOR^ P)
		{
			XMVECTOR xP;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMPlaneIsNaN(xP);
		}
		inline static bool XMPlaneNearEqual(dmXMVECTOR^ P1, dmXMVECTOR^ P2, dmXMVECTOR^ Epsilon)
		{
			XMVECTOR xP1;
			XMVECTOR xP2;
			XMVECTOR xEpsilon;
			int thesize = Marshal::SizeOf(P1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P1, pnt, false);
			memcpy(&xP1, (void*)pnt, thesize);
			Marshal::StructureToPtr(P2, pnt, true);
			memcpy(&xP2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Epsilon, pnt, true);
			memcpy(&xEpsilon, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMPlaneNearEqual(xP1, xP2, xEpsilon);
		}
		inline static dmXMVECTOR^ XMPlaneNormalize(dmXMVECTOR^ P)
		{
			XMVECTOR xP;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneNormalize(xP);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMPlaneNormalizeEst(dmXMVECTOR^ P)
		{
			XMVECTOR xP;
			int thesize = Marshal::SizeOf(P);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P, pnt, false);
			memcpy(&xP, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneNormalizeEst(xP);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMPlaneNotEqual(dmXMVECTOR^ P1, dmXMVECTOR^ P2)
		{
			XMVECTOR xP1;
			XMVECTOR xP2;
			int thesize = Marshal::SizeOf(P1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P1, pnt, false);
			memcpy(&xP1, (void*)pnt, thesize);
			Marshal::StructureToPtr(P2, pnt, true);
			memcpy(&xP2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMPlaneNotEqual(xP1, xP2);
		}
		inline static dmXMVECTOR^ XMPlaneTransform(dmXMVECTOR^ P, dmXMMATRIX^ M)
		{
			XMVECTOR xP;
			XMMATRIX xM;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(P);
			Marshal::StructureToPtr(P, pnt, true);
			memcpy(&xP, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMPlaneTransform(xP, xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMPlaneTransformStream([Out] array<dmXMFLOAT4^>^% pOutputStream, int32_t OutputStride, array<dmXMFLOAT4^>^ pInputStream, int32_t InputStride, int32_t PlaneCount, dmXMMATRIX^ M)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT4^>(PlaneCount);
				for (int i = 0; i < PlaneCount; i++)
					pOutputStream[i] = gcnew dmXMFLOAT4();
			}
			XMMATRIX xM;
			XMFLOAT4* plocaInputStream = new XMFLOAT4[PlaneCount];
			XMFLOAT4* plocaOutputStream = new XMFLOAT4[PlaneCount];

			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < PlaneCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
				plocaInputStream[i].z = pInputStream[i]->z;
				plocaInputStream[i].w = pInputStream[i]->w;
			}

			DDMath::XMPlaneTransformStream((XMFLOAT4*)plocaOutputStream, OutputStride, (XMFLOAT4*)plocaInputStream, InputStride, PlaneCount, xM);
			pin_ptr< dmXMFLOAT4^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < PlaneCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
				locaIOut[i]->z = plocaOutputStream[i].z;
				locaIOut[i]->w = plocaOutputStream[i].w;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;
			return;
		}

		// Library Plane Function - End

		// Quaternion Functions - Start

		inline static dmXMVECTOR^ XMQuaternionBaryCentric(dmXMVECTOR^ Q0, dmXMVECTOR^ Q1, dmXMVECTOR^ Q2, float f, float g)
		{
			XMVECTOR xQ0;
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			int thesize = Marshal::SizeOf(Q0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q0, pnt, false);
			memcpy(&xQ0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q1, pnt, true);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionBaryCentric(xQ0, xQ1, xQ2, f, g);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionBaryCentricV(dmXMVECTOR^ Q0, dmXMVECTOR^ Q1, dmXMVECTOR^ Q2, dmXMVECTOR^ F, dmXMVECTOR^ G)
		{
			XMVECTOR xQ0;
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			XMVECTOR xF;
			XMVECTOR xG;
			int thesize = Marshal::SizeOf(Q0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q0, pnt, false);
			memcpy(&xQ0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q1, pnt, true);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			Marshal::StructureToPtr(F, pnt, true);
			memcpy(&xF, (void*)pnt, thesize);
			Marshal::StructureToPtr(G, pnt, true);
			memcpy(&xG, (void*)pnt, thesize);
			assert((DDMath::XMVectorGetY(xF) == DDMath::XMVectorGetX(xF)) && (DDMath::XMVectorGetZ(xF) == DDMath::XMVectorGetX(xF)) && (DDMath::XMVectorGetW(xF) == DDMath::XMVectorGetX(xF)));
			assert((DDMath::XMVectorGetY(xG) == DDMath::XMVectorGetX(xG)) && (DDMath::XMVectorGetZ(xG) == DDMath::XMVectorGetX(xG)) && (DDMath::XMVectorGetW(xG) == DDMath::XMVectorGetX(xG)));
			XMVECTOR result = DDMath::XMQuaternionBaryCentricV(xQ0, xQ1, xQ2, xF, xG);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionConjugate(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionConjugate(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionDot(dmXMVECTOR^ Q1, dmXMVECTOR^ Q2)
		{
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			int thesize = Marshal::SizeOf(Q1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q1, pnt, false);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionDot(xQ1, xQ2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMQuaternionEqual(dmXMVECTOR^ Q1, dmXMVECTOR^ Q2)
		{
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			int thesize = Marshal::SizeOf(Q1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q1, pnt, false);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMQuaternionEqual(xQ1, xQ2);
		}
		inline static dmXMVECTOR^ XMQuaternionExp(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionExp(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionIdentity()
		{
			XMVECTOR result = DDMath::XMQuaternionIdentity();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionInverse(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionInverse(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMQuaternionIsIdentity(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMQuaternionIsIdentity(xQ);
		}
		inline static bool XMQuaternionIsInfinite(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMQuaternionIsInfinite(xQ);
		}
		inline static bool XMQuaternionIsNaN(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMQuaternionIsNaN(xQ);
		}
		inline static dmXMVECTOR^ XMQuaternionLength(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionLength(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionLengthSq(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionLengthSq(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionLn(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionLn(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionMultiply(dmXMVECTOR^ Q1, dmXMVECTOR^ Q2)
		{
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			int thesize = Marshal::SizeOf(Q1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q1, pnt, false);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionMultiply(xQ1, xQ2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionNormalize(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionNormalize(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionNormalizeEst(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionNormalizeEst(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMQuaternionNotEqual(dmXMVECTOR^ Q1, dmXMVECTOR^ Q2)
		{
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			int thesize = Marshal::SizeOf(Q1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q1, pnt, false);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMQuaternionNotEqual(xQ1, xQ2);
		}
		inline static dmXMVECTOR^ XMQuaternionReciprocalLength(dmXMVECTOR^ Q)
		{
			XMVECTOR xQ;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionReciprocalLength(xQ);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionRotationAxis(dmXMVECTOR^ Axis, float Angle)
		{
			XMVECTOR xAxis;
			int thesize = Marshal::SizeOf(Axis);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Axis, pnt, false);
			memcpy(&xAxis, (void*)pnt, thesize);
			assert(!DDMath::XMVector3Equal(xAxis, DDMath::XMVectorZero()));
			assert(!DDMath::XMVector3IsInfinite(xAxis));
			XMVECTOR result = DDMath::XMQuaternionRotationAxis(xAxis, Angle);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionRotationMatrix(dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionRotationMatrix(xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionRotationNormal(dmXMVECTOR^ NormalAxis, float Angle)
		{
			XMVECTOR xNormalAxis;
			int thesize = Marshal::SizeOf(NormalAxis);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(NormalAxis, pnt, false);
			memcpy(&xNormalAxis, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionRotationNormal(xNormalAxis, Angle);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionRotationRollPitchYaw(float Pitch, float Yaw, float Roll)
		{
			XMVECTOR result = DDMath::XMQuaternionRotationRollPitchYaw(Pitch, Yaw, Roll);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionRotationRollPitchYawFromVector(dmXMVECTOR^ Angles)
		{
			XMVECTOR xAngles;
			int thesize = Marshal::SizeOf(Angles);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Angles, pnt, false);
			memcpy(&xAngles, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionRotationRollPitchYawFromVector(xAngles);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionSlerp(dmXMVECTOR^ Q0, dmXMVECTOR^ Q1, float t)
		{
			XMVECTOR xQ0;
			XMVECTOR xQ1;
			int thesize = Marshal::SizeOf(Q0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q0, pnt, false);
			memcpy(&xQ0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q1, pnt, true);
			memcpy(&xQ1, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionSlerp(xQ0, xQ1, t);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionSlerpV(dmXMVECTOR^ Q0, dmXMVECTOR^ Q1, dmXMVECTOR^ T)
		{
			XMVECTOR xQ0;
			XMVECTOR xQ1;
			XMVECTOR xT;
			int thesize = Marshal::SizeOf(Q0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q0, pnt, false);
			memcpy(&xQ0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q1, pnt, true);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(T, pnt, true);
			memcpy(&xT, (void*)pnt, thesize);
			assert((DDMath::XMVectorGetY(xT) == DDMath::XMVectorGetX(xT)) && (DDMath::XMVectorGetZ(xT) == DDMath::XMVectorGetX(xT)) && (DDMath::XMVectorGetW(xT) == DDMath::XMVectorGetX(xT)));
			XMVECTOR result = DDMath::XMQuaternionSlerpV(xQ0, xQ1, xT);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMQuaternionSquad(dmXMVECTOR^ Q0, dmXMVECTOR^ Q1, dmXMVECTOR^ Q2, dmXMVECTOR^ Q3, float t)
		{
			XMVECTOR xQ0;
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			XMVECTOR xQ3;
			int thesize = Marshal::SizeOf(Q0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q0, pnt, false);
			memcpy(&xQ0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q1, pnt, true);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q3, pnt, true);
			memcpy(&xQ3, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMQuaternionSquad(xQ0, xQ1, xQ2, xQ3, t);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMQuaternionSquadSetup([Out] dmXMVECTOR^% pA, [Out] dmXMVECTOR^% pB, [Out] dmXMVECTOR^% pC,
			dmXMVECTOR^ Q0, dmXMVECTOR^ Q1, dmXMVECTOR^ Q2, dmXMVECTOR^ Q3)
		{
			if (pA == nullptr)
				pA = gcnew dmXMVECTOR();
			if (pB == nullptr)
				pB = gcnew dmXMVECTOR();
			if (pC == nullptr)
				pC = gcnew dmXMVECTOR();

			XMVECTOR xpA;
			XMVECTOR xpB;
			XMVECTOR xpC;
			XMVECTOR xQ0;
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			XMVECTOR xQ3;
			assert(!(pA == nullptr) && !(pB == nullptr) && !(pC == nullptr));
			int thesize = Marshal::SizeOf(Q0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q0, pnt, false);
			memcpy(&xQ0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q1, pnt, true);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q3, pnt, true);
			memcpy(&xQ3, (void*)pnt, thesize);
			DDMath::XMQuaternionSquadSetup(&xpA, &xpB, &xpC, xQ0, xQ1, xQ2, xQ3);
			memcpy((void*)pnt, &xpA, thesize);
			Marshal::PtrToStructure(pnt, pA);
			memcpy((void*)pnt, &xpB, thesize);
			Marshal::PtrToStructure(pnt, pB);
			memcpy((void*)pnt, &xpC, thesize);
			Marshal::PtrToStructure(pnt, pC);
			Marshal::FreeHGlobal(pnt);
		}
		inline static dmXMVECTOR^ XMQuaternionSquadV(dmXMVECTOR^ Q0, dmXMVECTOR^ Q1, dmXMVECTOR^ Q2, dmXMVECTOR^ Q3, dmXMVECTOR^ T)
		{
			XMVECTOR xQ0;
			XMVECTOR xQ1;
			XMVECTOR xQ2;
			XMVECTOR xQ3;
			XMVECTOR xT;
			int thesize = Marshal::SizeOf(Q0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q0, pnt, false);
			memcpy(&xQ0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q1, pnt, true);
			memcpy(&xQ1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q2, pnt, true);
			memcpy(&xQ2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Q3, pnt, true);
			memcpy(&xQ3, (void*)pnt, thesize);
			Marshal::StructureToPtr(T, pnt, true);
			memcpy(&xT, (void*)pnt, thesize);
			assert((DDMath::XMVectorGetY(xT) == DDMath::XMVectorGetX(xT)) && (DDMath::XMVectorGetZ(xT) == DDMath::XMVectorGetX(xT)) && (DDMath::XMVectorGetW(xT) == DDMath::XMVectorGetX(xT)));
			XMVECTOR result = DDMath::XMQuaternionSquadV(xQ0, xQ1, xQ2, xQ3, xT);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMQuaternionToAxisAngle([Out] dmXMVECTOR^% pAxis, [Out]float% pAngle, dmXMVECTOR^ Q)
		{
			if (pAxis == nullptr)
				pAxis = gcnew dmXMVECTOR();
			assert(!(pAxis == nullptr));
			XMVECTOR xQ;
			XMVECTOR xpAxis;
			float xpAngle;
			int thesize = Marshal::SizeOf(Q);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Q, pnt, false);
			memcpy(&xQ, (void*)pnt, thesize);
			DDMath::XMQuaternionToAxisAngle(&xpAxis, &xpAngle, xQ);
			memcpy((void*)pnt, &xpAxis, thesize);
			Marshal::PtrToStructure(pnt, pAxis);
			pAngle = xpAngle;
			Marshal::FreeHGlobal(pnt);
		}
		// Quaternion Functions - End

		// Scalar Functions - Start

		inline static float XMScalarACos(float Value)
		{
			return DDMath::XMScalarACos(Value);
		}
		inline static float XMScalarACosEst(float Value)
		{
			return DDMath::XMScalarACosEst(Value);
		}
		inline static float XMScalarASin(float Value)
		{
			return DDMath::XMScalarASin(Value);
		}
		inline static float XMScalarASinEst(float Value)
		{
			return DDMath::XMScalarASinEst(Value);
		}
		inline static float XMScalarCos(float Value)
		{
			return DDMath::XMScalarCos(Value);
		}
		inline static float XMScalarCosEst(float Value)
		{
			return DDMath::XMScalarCosEst(Value);
		}
		inline static float XMScalarModAngle(float Value)
		{
			return DDMath::XMScalarModAngle(Value);
		}
		inline static bool XMScalarNearEqual(float S1, float S2, float Epsilon)
		{
			return DDMath::XMScalarNearEqual(S1, S2, Epsilon);
		}
		inline static float XMScalarSin(float Value)
		{
			return DDMath::XMScalarSin(Value);
		}
		inline static float XMScalarSinEst(float Value)
		{
			return DDMath::XMScalarSinEst(Value);
		}
		inline static void XMScalarSinCos([Out] float% pSin, [Out]float% pCos, float Value)
		{
			float xpSin, xpCos;
			DDMath::XMScalarSinCos(&xpSin, &xpCos, Value);
			pSin = xpSin;
			pCos = xpCos;
		}
		inline static void XMScalarSinCosEst([Out]float% pSin, [Out]float% pCos, float Value)
		{
			float xpSin, xpCos;
			DDMath::XMScalarSinCosEst(&xpSin, &xpCos, Value);
			pSin = xpSin;
			pCos = xpCos;
		}
		// Scalar Functions - End

		// Vector Arithmetic Functions - Start

		inline static dmXMVECTOR^ XMVectorAbs(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorAbs(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorAdd(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorAdd(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorAddAngles(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorAddAngles(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorCeiling(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorCeiling(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorClamp(dmXMVECTOR^ V, dmXMVECTOR^ Min, dmXMVECTOR^ Max)
		{
			XMVECTOR xV;
			XMVECTOR xMin;
			XMVECTOR xMax;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(Min, pnt, true);
			memcpy(&xMin, (void*)pnt, thesize);
			Marshal::StructureToPtr(Max, pnt, true);
			memcpy(&xMax, (void*)pnt, thesize);
			assert(DDMath::XMVector4LessOrEqual(xMin, xMax));
			XMVECTOR result = DDMath::XMVectorClamp(xV, xMin, xMax);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorDivide(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorDivide(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorFloor(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorFloor(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorIsInfinite(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorIsInfinite(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorIsNaN(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorIsNaN(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorMax(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorMax(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorMin(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorMin(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorMod(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorMod(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorModAngles(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorModAngles(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorMultiply(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorMultiply(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorMultiplyAdd(dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ V3)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xV3;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(V3, pnt, true);
			memcpy(&xV3, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorMultiplyAdd(xV1, xV2, xV3);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorNegate(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorNegate(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorNegativeMultiplySubtract(dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ V3)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xV3;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(V3, pnt, true);
			memcpy(&xV3, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorNegativeMultiplySubtract(xV1, xV2, xV3);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorPow(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorPow(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorReciprocal(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorReciprocal(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorReciprocalEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorReciprocalEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorReciprocalSqrt(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorReciprocalSqrt(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorReciprocalSqrtEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorReciprocalSqrtEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorRound(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorRound(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSaturate(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSaturate(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorScale(dmXMVECTOR^ V, float ScaleFactor)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorScale(xV, ScaleFactor);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSqrt(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSqrt(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSqrtEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSqrtEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSubtract(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSubtract(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSubtractAngles(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSubtractAngles(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorTruncate(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorTruncate(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Vector Arithmetic Functions - End

		// Bit-Wise Vector Functions - Start

		inline static dmXMVECTOR^ XMVectorAndCInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorAndCInt(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorAndInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorAndInt(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorNorInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorNorInt(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorNotEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorNotEqual(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorNotEqualInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorNotEqualInt(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorOrInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorOrInt(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorXorInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorXorInt(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Bit-Wise Vector Functions - End

		// Vector Comparison Functions - Start

		inline static dmXMVECTOR^ XMVectorEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorEqual(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorEqualInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorEqualInt(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorEqualIntR([Out] uint32_t% pCR, dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			uint32_t xpCR;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorEqualIntR(&xpCR, xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			pCR = xpCR;
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorEqualR([Out] uint32_t% pCR, dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			uint32_t xpCR;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorEqualR(&xpCR, xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			pCR = xpCR;
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorGreater(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorGreater(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorGreaterOrEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorGreaterOrEqual(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorGreaterOrEqualR([Out] uint32_t% pCR, dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			uint32_t xpCR;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorGreaterOrEqualR(&xpCR, xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			pCR = xpCR;
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorGreaterR([Out] uint32_t% pCR, dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			uint32_t xpCR;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorGreaterR(&xpCR, xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			pCR = xpCR;
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorLess(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorLess(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorLessOrEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorLessOrEqual(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorNearEqual(dmXMVECTOR^ P1, dmXMVECTOR^ P2, dmXMVECTOR^ Epsilon)
		{
			XMVECTOR xP1;
			XMVECTOR xP2;
			XMVECTOR xEpsilon;
			int thesize = Marshal::SizeOf(P1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(P1, pnt, false);
			memcpy(&xP1, (void*)pnt, thesize);
			Marshal::StructureToPtr(P2, pnt, true);
			memcpy(&xP2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Epsilon, pnt, true);
			memcpy(&xEpsilon, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorNearEqual(xP1, xP2, xEpsilon);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Vector Comparison Functions - End

		// Component-Wise Vector Functions - Start

		inline static dmXMVECTOR^ XMVectorInsert(dmXMVECTOR^ VD, dmXMVECTOR^ VS, uint32_t VSLeftRotateElements,
			uint32_t Select0, uint32_t Select1, uint32_t Select2, uint32_t Select3)
		{
			XMVECTOR xVD;
			XMVECTOR xVS;
			int thesize = Marshal::SizeOf(VD);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(VD, pnt, false);
			memcpy(&xVD, (void*)pnt, thesize);
			Marshal::StructureToPtr(VS, pnt, true);
			memcpy(&xVS, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorInsert(xVD, xVS, VSLeftRotateElements, Select0, Select1, Select2, Select3);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorMergeXY(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorMergeXY(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorMergeZW(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorMergeZW(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorPermute(dmXMVECTOR^ V1, dmXMVECTOR^ V2, uint32_t PermuteX, uint32_t PermuteY, uint32_t PermuteZ, uint32_t PermuteW)
		{
			assert(PermuteX <= 7 && PermuteY <= 7 && PermuteZ <= 7 && PermuteW <= 7);
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorPermute(xV1, xV2, PermuteX, PermuteY, PermuteZ, PermuteW);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorRotateLeft(dmXMVECTOR^ V, uint32_t Elements)
		{
			assert(Elements < 4);
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorRotateLeft(xV, Elements);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorRotateRight(dmXMVECTOR^ V, uint32_t Elements)
		{
			assert(Elements < 4);
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorRotateRight(xV, Elements);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSelect(dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ Control)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xControl;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Control, pnt, true);
			memcpy(&xControl, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSelect(xV1, xV2, xControl);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSelectControl(uint32_t VectorIndex0, uint32_t VectorIndex1, uint32_t VectorIndex2, uint32_t VectorIndex3)
		{
			assert(VectorIndex0 < 2);
			assert(VectorIndex1 < 2);
			assert(VectorIndex2 < 2);
			assert(VectorIndex3 < 2);
			XMVECTOR result = DDMath::XMVectorSelectControl(VectorIndex0, VectorIndex1, VectorIndex2, VectorIndex3);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorShiftLeft(dmXMVECTOR^ V1, dmXMVECTOR^ V2, uint32_t Elements)
		{
			assert(Elements < 4);
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorShiftLeft(xV1, xV2, Elements);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatW(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSplatW(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatX(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSplatX(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatY(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSplatY(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatZ(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSplatZ(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSwizzle(dmXMVECTOR^ V, uint32_t E0, uint32_t E1, uint32_t E2, uint32_t E3)
		{
			XMVECTOR xV;
			assert((E0 < 4) && (E1 < 4) && (E2 < 4) && (E3 < 4));
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSwizzle(xV, E0, E1, E2, E3);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Component-Wise Vector Functions - End 

		// Geometric Vector Functions - Start

		inline static dmXMVECTOR^ XMVectorBaryCentric(dmXMVECTOR^ Position0, dmXMVECTOR^ Position1, dmXMVECTOR^ Position2, float f, float g)
		{
			XMVECTOR xPosition0;
			XMVECTOR xPosition1;
			XMVECTOR xPosition2;
			int thesize = Marshal::SizeOf(Position0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Position0, pnt, false);
			memcpy(&xPosition0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position1, pnt, true);
			memcpy(&xPosition1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position2, pnt, true);
			memcpy(&xPosition2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorBaryCentric(xPosition0, xPosition1, xPosition2, f, g);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorBaryCentricV(dmXMVECTOR^ Position0, dmXMVECTOR^ Position1, dmXMVECTOR^ Position2, dmXMVECTOR^ F, dmXMVECTOR^ G)
		{
			XMVECTOR xPosition0;
			XMVECTOR xPosition1;
			XMVECTOR xPosition2;
			XMVECTOR xF;
			XMVECTOR xG;
			int thesize = Marshal::SizeOf(Position0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Position0, pnt, false);
			memcpy(&xPosition0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position1, pnt, true);
			memcpy(&xPosition1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position2, pnt, true);
			memcpy(&xPosition2, (void*)pnt, thesize);
			Marshal::StructureToPtr(F, pnt, true);
			memcpy(&xF, (void*)pnt, thesize);
			Marshal::StructureToPtr(G, pnt, true);
			memcpy(&xG, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorBaryCentricV(xPosition0, xPosition1, xPosition2, xF, xG);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorCatmullRom(dmXMVECTOR^ Position0, dmXMVECTOR^ Position1, dmXMVECTOR^ Position2, dmXMVECTOR^ Position3, float t)
		{
			XMVECTOR xPosition0;
			XMVECTOR xPosition1;
			XMVECTOR xPosition2;
			XMVECTOR xPosition3;
			int thesize = Marshal::SizeOf(Position0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Position0, pnt, false);
			memcpy(&xPosition0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position1, pnt, true);
			memcpy(&xPosition1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position2, pnt, true);
			memcpy(&xPosition2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position3, pnt, true);
			memcpy(&xPosition3, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorCatmullRom(xPosition0, xPosition1, xPosition2, xPosition3, t);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorCatmullRomV(dmXMVECTOR^ Position0, dmXMVECTOR^ Position1, dmXMVECTOR^ Position2, dmXMVECTOR^ Position3, dmXMVECTOR^ T)
		{
			XMVECTOR xPosition0;
			XMVECTOR xPosition1;
			XMVECTOR xPosition2;
			XMVECTOR xPosition3;
			XMVECTOR xT;
			int thesize = Marshal::SizeOf(Position0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Position0, pnt, false);
			memcpy(&xPosition0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position1, pnt, true);
			memcpy(&xPosition1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position2, pnt, true);
			memcpy(&xPosition2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position3, pnt, true);
			memcpy(&xPosition3, (void*)pnt, thesize);
			Marshal::StructureToPtr(T, pnt, true);
			memcpy(&xT, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorCatmullRomV(xPosition0, xPosition1, xPosition2, xPosition3, xT);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorHermite(dmXMVECTOR^ Position0, dmXMVECTOR^ Tangent0, dmXMVECTOR^ Position1, dmXMVECTOR^ Tangent1, float t)
		{
			XMVECTOR xPosition0;
			XMVECTOR xPosition1;
			XMVECTOR xTangent0;
			XMVECTOR xTangent1;
			int thesize = Marshal::SizeOf(Position0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Position0, pnt, false);
			memcpy(&xPosition0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position1, pnt, true);
			memcpy(&xPosition1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Tangent0, pnt, true);
			memcpy(&xTangent0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Tangent1, pnt, true);
			memcpy(&xTangent1, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorHermite(xPosition0, xTangent0, xPosition1, xTangent1, t);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorHermiteV(dmXMVECTOR^ Position0, dmXMVECTOR^ Tangent0, dmXMVECTOR^ Position1, dmXMVECTOR^ Tangent1, dmXMVECTOR^ T)
		{
			XMVECTOR xPosition0;
			XMVECTOR xPosition1;
			XMVECTOR xTangent0;
			XMVECTOR xTangent1;
			XMVECTOR xT;
			int thesize = Marshal::SizeOf(Position0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Position0, pnt, false);
			memcpy(&xPosition0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Position1, pnt, true);
			memcpy(&xPosition1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Tangent0, pnt, true);
			memcpy(&xTangent0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Tangent1, pnt, true);
			memcpy(&xTangent1, (void*)pnt, thesize);
			Marshal::StructureToPtr(T, pnt, true);
			memcpy(&xT, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorHermiteV(xPosition0, xTangent0, xPosition1, xTangent1, xT);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorInBounds(dmXMVECTOR^ V, dmXMVECTOR^ Bounds)
		{
			XMVECTOR xV;
			XMVECTOR xBounds;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(Bounds, pnt, true);
			memcpy(&xBounds, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorInBounds(xV, xBounds);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorInBoundsR([Out] uint32_t% pCR, dmXMVECTOR^ V, dmXMVECTOR^ Bounds)
		{
			XMVECTOR xV;
			XMVECTOR xBounds;
			uint32_t xpCR;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(Bounds, pnt, true);
			memcpy(&xBounds, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorInBoundsR(&xpCR, xV, xBounds);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			pCR = xpCR;
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorLerp(dmXMVECTOR^ V0, dmXMVECTOR^ V1, float t)
		{
			XMVECTOR xV0;
			XMVECTOR xV1;
			int thesize = Marshal::SizeOf(V0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V0, pnt, false);
			memcpy(&xV0, (void*)pnt, thesize);
			Marshal::StructureToPtr(V1, pnt, true);
			memcpy(&xV1, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorLerp(xV0, xV1, t);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorLerpV(dmXMVECTOR^ V0, dmXMVECTOR^ V1, dmXMVECTOR^ T)
		{
			XMVECTOR xV0;
			XMVECTOR xV1;
			XMVECTOR xT;
			int thesize = Marshal::SizeOf(V0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V0, pnt, false);
			memcpy(&xV0, (void*)pnt, thesize);
			Marshal::StructureToPtr(V1, pnt, true);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(T, pnt, true);
			memcpy(&xT, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorLerpV(xV0, xV1, xT);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Geometric Vector Functions - End

		// Vector Initialization Functions - Start
		inline static dmXMVECTOR^ XMVectorFalseInt()
		{
			XMVECTOR result = DDMath::XMVectorFalseInt();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorReplicate(float Value)
		{
			XMVECTOR result = DDMath::XMVectorReplicate(Value);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorReplicateInt(uint32_t Value)
		{
			XMVECTOR result = DDMath::XMVectorReplicateInt(Value);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorReplicateIntPtr(uint32_t% pValue)
		{
			uint32_t xValue = pValue;
			XMVECTOR result = DDMath::XMVectorReplicateIntPtr(&xValue);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorReplicatePtr(float% Value)
		{
			float xValue = Value;
			XMVECTOR result = DDMath::XMVectorReplicatePtr(&xValue);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSet(float x, float y, float z, float w)
		{
			XMVECTOR result = DDMath::XMVectorSet(x, y, z, w);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetBinaryConstant(uint32_t C0, uint32_t C1, uint32_t C2, uint32_t C3)
		{
			XMVECTOR result = DDMath::XMVectorSetBinaryConstant(C0, C1, C2, C3);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetInt(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
		{
			XMVECTOR result = DDMath::XMVectorSetInt(x, y, z, w);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatConstant(int32_t IntConstant, uint32_t DivExponent)
		{
			XMVECTOR result = DDMath::XMVectorSplatConstant(IntConstant, DivExponent);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			assert((IntConstant >= -16) && (IntConstant <= 15));
			assert(DivExponent < 32);
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatConstantInt(int32_t IntConstant)
		{
			XMVECTOR result = DDMath::XMVectorSplatConstantInt(IntConstant);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			assert((IntConstant >= -16) && (IntConstant <= 15));
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatEpsilon()
		{
			XMVECTOR result = DDMath::XMVectorSplatEpsilon();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatInfinity()
		{
			XMVECTOR result = DDMath::XMVectorSplatInfinity();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatOne()
		{
			XMVECTOR result = DDMath::XMVectorSplatOne();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatQNaN()
		{
			XMVECTOR result = DDMath::XMVectorSplatQNaN();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSplatSignMask()
		{
			XMVECTOR result = DDMath::XMVectorSplatSignMask();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorTrueInt()
		{
			XMVECTOR result = DDMath::XMVectorTrueInt();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorZero()
		{
			XMVECTOR result = DDMath::XMVectorZero();
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Vector Initialization Functions - End

		// Transcendental Vector Functions - Start

		inline static dmXMVECTOR^ XMVectorACos(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorACos(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorACosEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorACosEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorASin(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorASin(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorASinEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorASinEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorATan(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorATan(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorATanEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorATanEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorATan2(dmXMVECTOR^ Y, dmXMVECTOR^ X)
		{
			XMVECTOR xY;
			XMVECTOR xX;
			int thesize = Marshal::SizeOf(Y);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Y, pnt, false);
			memcpy(&xY, (void*)pnt, thesize);
			Marshal::StructureToPtr(X, pnt, true);
			memcpy(&xX, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorATan2(xY, xX);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorATan2Est(dmXMVECTOR^ Y, dmXMVECTOR^ X)
		{
			XMVECTOR xY;
			XMVECTOR xX;
			int thesize = Marshal::SizeOf(Y);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Y, pnt, false);
			memcpy(&xY, (void*)pnt, thesize);
			Marshal::StructureToPtr(X, pnt, true);
			memcpy(&xX, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorATan2Est(xY, xX);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorCos(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorCos(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorCosEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorCosEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorCosH(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorCosH(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorExp(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorExp(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorExp2(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorExp2(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorExpE(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorExpE(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorLog(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorLog(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorLog2(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorLog2(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorLogE(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorLogE(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSin(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSin(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSinEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSinEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVectorSinCos([Out] dmXMVECTOR^% sin, [Out] dmXMVECTOR^% cos, dmXMVECTOR^ V)
		{
			if (sin == nullptr)
				sin = gcnew dmXMVECTOR();
			if (cos == nullptr)
				cos = gcnew dmXMVECTOR();

			assert(sin != nullptr);
			assert(cos != nullptr);
			XMVECTOR xsin;
			XMVECTOR xcos;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			DDMath::XMVectorSinCos(&xsin, &xcos, xV);
			memcpy((void*)pnt, &xsin, thesize);
			Marshal::PtrToStructure(pnt, sin);
			memcpy((void*)pnt, &xcos, thesize);
			Marshal::PtrToStructure(pnt, cos);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMVectorSinCosEst([Out] dmXMVECTOR^% sin, [Out] dmXMVECTOR^% cos, dmXMVECTOR^ V)
		{
			if (sin == nullptr)
				sin = gcnew dmXMVECTOR();
			if (cos == nullptr)
				cos = gcnew dmXMVECTOR();

			assert(sin != nullptr);
			assert(cos != nullptr);
			XMVECTOR xsin;
			XMVECTOR xcos;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			DDMath::XMVectorSinCosEst(&xsin, &xcos, xV);
			memcpy((void*)pnt, &xsin, thesize);
			Marshal::PtrToStructure(pnt, sin);
			memcpy((void*)pnt, &xcos, thesize);
			Marshal::PtrToStructure(pnt, cos);
			Marshal::FreeHGlobal(pnt);
		}
		inline static dmXMVECTOR^ XMVectorSinH(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSinH(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorTan(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorTan(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorTanEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorTanEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorTanH(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorTanH(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Transcendental Vector Functions -End

		// 2D Vector Comparison Functions - Start

		inline static bool XMVector2Equal(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2Equal(xV1, xV2);
		}
		inline static bool XMVector2EqualInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2EqualInt(xV1, xV2);
		}
		inline static uint32_t XMVector2EqualIntR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2EqualIntR(xV1, xV2);
		}
		inline static uint32_t XMVector2EqualR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2EqualR(xV1, xV2);
		}
		inline static bool XMVector2Greater(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2Greater(xV1, xV2);
		}
		inline static bool XMVector2GreaterOrEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2GreaterOrEqual(xV1, xV2);
		}
		inline static uint32_t XMVector2GreaterOrEqualR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2GreaterOrEqualR(xV1, xV2);
		}
		inline static uint32_t XMVector2GreaterR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2GreaterR(xV1, xV2);
		}
		inline static bool XMVector2IsInfinite(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2IsInfinite(xV);
		}
		inline static bool XMVector2IsNaN(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2IsNaN(xV);
		}
		inline static bool XMVector2Less(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2Less(xV1, xV2);
		}
		inline static bool XMVector2LessOrEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2LessOrEqual(xV1, xV2);
		}
		inline static bool XMVector2NearEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ Epsilon)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xEpsilon;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Epsilon, pnt, true);
			memcpy(&xEpsilon, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2NearEqual(xV1, xV2, xEpsilon);
		}
		inline static bool XMVector2NotEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2NotEqual(xV1, xV2);
		}
		inline static bool XMVector2NotEqualInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2NotEqualInt(xV1, xV2);
		}
		// 2D Vector Comparison Functions - End

		// 2D Vector Geometric Functions - Start

		inline static dmXMVECTOR^ XMVector2AngleBetweenNormals(dmXMVECTOR^ N1, dmXMVECTOR^ N2)
		{
			XMVECTOR xN1;
			XMVECTOR xN2;
			int thesize = Marshal::SizeOf(N1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(N1, pnt, false);
			memcpy(&xN1, (void*)pnt, thesize);
			Marshal::StructureToPtr(N2, pnt, true);
			memcpy(&xN2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2AngleBetweenNormals(xN1, xN2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2AngleBetweenNormalsEst(dmXMVECTOR^ N1, dmXMVECTOR^ N2)
		{
			XMVECTOR xN1;
			XMVECTOR xN2;
			int thesize = Marshal::SizeOf(N1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(N1, pnt, false);
			memcpy(&xN1, (void*)pnt, thesize);
			Marshal::StructureToPtr(N2, pnt, true);
			memcpy(&xN2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2AngleBetweenNormalsEst(xN1, xN2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2AngleBetweenVectors(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2AngleBetweenVectors(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2ClampLength(dmXMVECTOR^ V, float LengthMin, float LengthMax)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2ClampLength(xV, LengthMin, LengthMax);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2ClampLengthV(dmXMVECTOR^ V, dmXMVECTOR^ LengthMin, dmXMVECTOR^ LengthMax)
		{
			XMVECTOR xV;
			XMVECTOR xLengthMin;
			XMVECTOR xLengthMax;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(LengthMin, pnt, true);
			memcpy(&xLengthMin, (void*)pnt, thesize);
			Marshal::StructureToPtr(LengthMax, pnt, true);
			memcpy(&xLengthMax, (void*)pnt, thesize);
			assert((DDMath::XMVectorGetY(xLengthMin) == DDMath::XMVectorGetX(xLengthMin)));
			assert((DDMath::XMVectorGetY(xLengthMax) == DDMath::XMVectorGetX(xLengthMax)));
			assert(DDMath::XMVector2GreaterOrEqual(xLengthMin, g_XMZero.v));
			assert(DDMath::XMVector2GreaterOrEqual(xLengthMax, g_XMZero.v));
			assert(DDMath::XMVector2GreaterOrEqual(xLengthMax, xLengthMin));
			XMVECTOR result = DDMath::XMVector2ClampLengthV(xV, xLengthMin, xLengthMax);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2Cross(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2Cross(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2Dot(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2Dot(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMVector2InBounds(dmXMVECTOR^ V, dmXMVECTOR^ Bounds)
		{
			XMVECTOR xV;
			XMVECTOR xBounds;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(Bounds, pnt, true);
			memcpy(&xBounds, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector2InBounds(xV, xBounds);
		}
		inline static dmXMVECTOR^ XMVector2IntersectLine(dmXMVECTOR^ Line1Point1, dmXMVECTOR^ Line1Point2, dmXMVECTOR^ Line2Point1, dmXMVECTOR^ Line2Point2)
		{
			XMVECTOR xLine1Point1;
			XMVECTOR xLine1Point2;
			XMVECTOR xLine2Point1;
			XMVECTOR xLine2Point2;
			int thesize = Marshal::SizeOf(Line1Point1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Line1Point1, pnt, false);
			memcpy(&xLine1Point1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Line1Point2, pnt, true);
			memcpy(&xLine1Point2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Line2Point1, pnt, true);
			memcpy(&xLine2Point1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Line2Point2, pnt, true);
			memcpy(&xLine2Point2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2IntersectLine(xLine1Point1, xLine1Point2, xLine2Point1, xLine2Point2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2Length(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2Length(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2LengthEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2LengthEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2LengthSq(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2LengthSq(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2LinePointDistance(dmXMVECTOR^ LinePoint1, dmXMVECTOR^ LinePoint2, dmXMVECTOR^ Point)
		{
			XMVECTOR xLinePoint1;
			XMVECTOR xLinePoint2;
			XMVECTOR xPoint;
			int thesize = Marshal::SizeOf(LinePoint1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(LinePoint1, pnt, false);
			memcpy(&xLinePoint1, (void*)pnt, thesize);
			Marshal::StructureToPtr(LinePoint2, pnt, true);
			memcpy(&xLinePoint2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Point, pnt, true);
			memcpy(&xPoint, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2LinePointDistance(xLinePoint1, xLinePoint2, xPoint);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2Normalize(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2Normalize(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2NormalizeEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2NormalizeEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2Orthogonal(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2Orthogonal(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2ReciprocalLength(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2ReciprocalLength(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2ReciprocalLengthEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2ReciprocalLengthEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2Reflect(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2Reflect(xIncident, xNormal);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2Refract(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal, float RefractionIndex)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2Refract(xIncident, xNormal, RefractionIndex);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2RefractV(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal, dmXMVECTOR^ RefractionIndex)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			XMVECTOR xRefractionIndex;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			Marshal::StructureToPtr(RefractionIndex, pnt, true);
			memcpy(&xRefractionIndex, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2RefractV(xIncident, xNormal, xRefractionIndex);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		//  2D Vector Geometric Functions - End

		// 2D Vector Transformation Functions - Start
		inline static dmXMVECTOR^ XMVector2Transform(dmXMVECTOR^ V, dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2Transform(xV, xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector2TransformCoord(dmXMVECTOR^ V, dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2TransformCoord(xV, xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVector2TransformCoordStream([Out] array<dmXMFLOAT2^>^% pOutputStream, int32_t OutputStride, array<dmXMFLOAT2^>^ pInputStream, int32_t InputStride, int32_t VectorCount, dmXMMATRIX^ M)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT2^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT2();
			}
			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT2));
			assert(OutputStride >= sizeof(XMFLOAT2));
			XMMATRIX xM;
			XMFLOAT2* plocaInputStream = new XMFLOAT2[VectorCount];
			XMFLOAT2* plocaOutputStream = new XMFLOAT2[VectorCount];

			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
			}

			DDMath::XMVector2TransformCoordStream((XMFLOAT2*)plocaOutputStream, OutputStride, (XMFLOAT2*)plocaInputStream, InputStride, VectorCount, xM);
			pin_ptr< dmXMFLOAT2^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;
			return;
		}
		inline static dmXMVECTOR^ XMVector2TransformNormal(dmXMVECTOR^ V, dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector2TransformNormal(xV, xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVector2TransformNormalStream([Out] array<dmXMFLOAT2^>^% pOutputStream, int32_t OutputStride, array<dmXMFLOAT2^>^ pInputStream, int32_t InputStride, int32_t VectorCount, dmXMMATRIX^ M)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT2^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT2();
			}
			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT2));
			assert(OutputStride >= sizeof(XMFLOAT2));
			XMMATRIX xM;
			XMFLOAT2* plocaInputStream = new XMFLOAT2[VectorCount];
			XMFLOAT2* plocaOutputStream = new XMFLOAT2[VectorCount];

			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
			}

			DDMath::XMVector2TransformNormalStream((XMFLOAT2*)plocaOutputStream, OutputStride, (XMFLOAT2*)plocaInputStream, InputStride, VectorCount, xM);
			pin_ptr< dmXMFLOAT2^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;
			return;
		}
		inline static void XMVector2TransformStream([Out] array<dmXMFLOAT4^>^% pOutputStream, int32_t OutputStride, array<dmXMFLOAT2^>^ pInputStream, int32_t InputStride, int32_t VectorCount, dmXMMATRIX^ M)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT4^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT4();
			}

			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT2));
			assert(OutputStride >= sizeof(XMFLOAT4));
			XMMATRIX xM;
			XMFLOAT2* plocaInputStream = new XMFLOAT2[VectorCount];
			XMFLOAT4* plocaOutputStream = new XMFLOAT4[VectorCount];

			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
			}

			DDMath::XMVector2TransformStream((XMFLOAT4*)plocaOutputStream, OutputStride, (XMFLOAT2*)plocaInputStream, InputStride, VectorCount, xM);
			pin_ptr< dmXMFLOAT4^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
				locaIOut[i]->z = plocaOutputStream[i].z;
				locaIOut[i]->w = plocaOutputStream[i].w;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;

			return;
		}
		// 2D Vector Transformation Functions - End

		// 3D Vector Comparison Functions - Start

		inline static bool XMVector3Equal(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3Equal(xV1, xV2);
		}
		inline static bool XMVector3EqualInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3EqualInt(xV1, xV2);
		}
		inline static uint32_t XMVector3EqualIntR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3EqualIntR(xV1, xV2);
		}
		inline static uint32_t XMVector3EqualR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3EqualR(xV1, xV2);
		}
		inline static bool XMVector3Greater(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3Greater(xV1, xV2);
		}
		inline static bool XMVector3GreaterOrEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3GreaterOrEqual(xV1, xV2);
		}
		inline static uint32_t XMVector3GreaterOrEqualR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3GreaterOrEqualR(xV1, xV2);
		}
		inline static uint32_t XMVector3GreaterR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3GreaterR(xV1, xV2);
		}
		inline static bool XMVector3IsInfinite(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3IsInfinite(xV);
		}
		inline static bool XMVector3IsNaN(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3IsNaN(xV);
		}
		inline static bool XMVector3Less(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3Less(xV1, xV2);
		}
		inline static bool XMVector3LessOrEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3LessOrEqual(xV1, xV2);
		}
		inline static bool XMVector3NearEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ Epsilon)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xEpsilon;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Epsilon, pnt, true);
			memcpy(&xEpsilon, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3NearEqual(xV1, xV2, xEpsilon);
		}
		inline static bool XMVector3NotEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3NotEqual(xV1, xV2);
		}
		inline static bool XMVector3NotEqualInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3NotEqualInt(xV1, xV2);
		}
		// 3D Vector Comparison Functions - End

		// 3D Vector Geometric Functions - Start

		inline static dmXMVECTOR^ XMVector3AngleBetweenNormals(dmXMVECTOR^ N1, dmXMVECTOR^ N2)
		{
			XMVECTOR xN1;
			XMVECTOR xN2;
			int thesize = Marshal::SizeOf(N1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(N1, pnt, false);
			memcpy(&xN1, (void*)pnt, thesize);
			Marshal::StructureToPtr(N2, pnt, true);
			memcpy(&xN2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3AngleBetweenNormals(xN1, xN2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3AngleBetweenNormalsEst(dmXMVECTOR^ N1, dmXMVECTOR^ N2)
		{
			XMVECTOR xN1;
			XMVECTOR xN2;
			int thesize = Marshal::SizeOf(N1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(N1, pnt, false);
			memcpy(&xN1, (void*)pnt, thesize);
			Marshal::StructureToPtr(N2, pnt, true);
			memcpy(&xN2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3AngleBetweenNormalsEst(xN1, xN2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3AngleBetweenVectors(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3AngleBetweenVectors(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3ClampLength(dmXMVECTOR^ V, float LengthMin, float LengthMax)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3ClampLength(xV, LengthMin, LengthMax);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3ClampLengthV(dmXMVECTOR^ V, dmXMVECTOR^ LengthMin, dmXMVECTOR^ LengthMax)
		{
			XMVECTOR xV;
			XMVECTOR xLengthMin;
			XMVECTOR xLengthMax;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(LengthMin, pnt, true);
			memcpy(&xLengthMin, (void*)pnt, thesize);
			Marshal::StructureToPtr(LengthMax, pnt, true);
			memcpy(&xLengthMax, (void*)pnt, thesize);
			assert((DDMath::XMVectorGetY(xLengthMin) == DDMath::XMVectorGetX(xLengthMin)) && (DDMath::XMVectorGetZ(xLengthMin) == DDMath::XMVectorGetX(xLengthMin)));
			assert((DDMath::XMVectorGetY(xLengthMax) == DDMath::XMVectorGetX(xLengthMax)) && (DDMath::XMVectorGetZ(xLengthMax) == DDMath::XMVectorGetX(xLengthMax)));
			assert(DDMath::XMVector3GreaterOrEqual(xLengthMin, g_XMZero.v));
			assert(DDMath::XMVector3GreaterOrEqual(xLengthMax, g_XMZero.v));
			assert(DDMath::XMVector3GreaterOrEqual(xLengthMax, xLengthMin));
			XMVECTOR result = DDMath::XMVector3ClampLengthV(xV, xLengthMin, xLengthMax);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVector3ComponentsFromNormal([Out] dmXMVECTOR^% pParallel, [Out] dmXMVECTOR^% pPerpendicular, dmXMVECTOR^ V, dmXMVECTOR^ Normal)
		{
			if (pParallel == nullptr)
				pParallel = gcnew dmXMVECTOR();
			if (pPerpendicular == nullptr)
				pPerpendicular = gcnew dmXMVECTOR();

			assert(pParallel != nullptr);
			assert(pPerpendicular != nullptr);
			XMVECTOR xpParallel;
			XMVECTOR xpPerpendicular;
			XMVECTOR xV;
			XMVECTOR xNormal;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			DDMath::XMVector3ComponentsFromNormal(&xpParallel, &xpPerpendicular, xV, xNormal);
			memcpy((void*)pnt, &xpParallel, thesize);
			Marshal::PtrToStructure(pnt, pParallel);
			memcpy((void*)pnt, &xpPerpendicular, thesize);
			Marshal::PtrToStructure(pnt, pPerpendicular);
			Marshal::FreeHGlobal(pnt);
		}
		inline static dmXMVECTOR^ XMVector3Cross(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Cross(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3Dot(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Dot(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMVector3InBounds(dmXMVECTOR^ V, dmXMVECTOR^ Bounds)
		{
			XMVECTOR xV;
			XMVECTOR xBounds;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(Bounds, pnt, true);
			memcpy(&xBounds, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector3InBounds(xV, xBounds);
		}
		inline static dmXMVECTOR^ XMVector3Length(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Length(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3LengthEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3LengthEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3LengthSq(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3LengthSq(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3LinePointDistance(dmXMVECTOR^ LinePoint1, dmXMVECTOR^ LinePoint2, dmXMVECTOR^ Point)
		{
			XMVECTOR xLinePoint1;
			XMVECTOR xLinePoint2;
			XMVECTOR xPoint;
			int thesize = Marshal::SizeOf(LinePoint1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(LinePoint1, pnt, false);
			memcpy(&xLinePoint1, (void*)pnt, thesize);
			Marshal::StructureToPtr(LinePoint2, pnt, true);
			memcpy(&xLinePoint2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Point, pnt, true);
			memcpy(&xPoint, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3LinePointDistance(xLinePoint1, xLinePoint2, xPoint);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3Normalize(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Normalize(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3NormalizeEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3NormalizeEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3Orthogonal(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Orthogonal(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3ReciprocalLength(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3ReciprocalLength(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3ReciprocalLengthEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3ReciprocalLengthEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3Reflect(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Reflect(xIncident, xNormal);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3Refract(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal, float RefractionIndex)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Refract(xIncident, xNormal, RefractionIndex);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3RefractV(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal, dmXMVECTOR^ RefractionIndex)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			XMVECTOR xRefractionIndex;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			Marshal::StructureToPtr(RefractionIndex, pnt, true);
			memcpy(&xRefractionIndex, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3RefractV(xIncident, xNormal, xRefractionIndex);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// 3D Vector Geometric Functions - End

		// 3D Vector Transformation Functions - Start

		inline static dmXMVECTOR^ XMVector3InverseRotate(dmXMVECTOR^ V, dmXMVECTOR^ RotationQuaternion)
		{
			XMVECTOR xV;
			XMVECTOR xRotationQuaternion;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(RotationQuaternion, pnt, true);
			memcpy(&xRotationQuaternion, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3InverseRotate(xV, xRotationQuaternion);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3Project(dmXMVECTOR^ V, float ViewportX, float ViewportY, float ViewportWidth,
			float ViewportHeight, float ViewportMinZ, float ViewportMaxZ, dmXMMATRIX^ Projection, dmXMMATRIX^ View, dmXMMATRIX^ World)
		{
			XMVECTOR xV;
			XMMATRIX xProjection;
			XMMATRIX xView;
			XMMATRIX xWorld;
			int thesize = Marshal::SizeOf(Projection);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Projection, pnt, false);
			memcpy(&xProjection, (void*)pnt, thesize);
			Marshal::StructureToPtr(View, pnt, true);
			memcpy(&xView, (void*)pnt, thesize);
			Marshal::StructureToPtr(World, pnt, true);
			memcpy(&xWorld, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Project(xV, ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ, xProjection, xView, xWorld);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVector3ProjectStream([Out]array<dmXMFLOAT3^>^% pOutputStream, int32_t OutputStride,
			array<dmXMFLOAT3^>^ pInputStream, int32_t InputStride, int32_t VectorCount, float ViewportX,
			float ViewportY, float ViewportWidth, float ViewportHeight, float ViewportMinZ, float ViewportMaxZ,
			dmXMMATRIX^ Projection, dmXMMATRIX^ View, dmXMMATRIX^ World)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT3^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT3();
			}
			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT3));
			assert(OutputStride >= sizeof(XMFLOAT3));
			XMMATRIX xProjection;
			XMMATRIX xView;
			XMMATRIX xWorld;
			XMFLOAT3* plocaInputStream = new XMFLOAT3[VectorCount];
			XMFLOAT3* plocaOutputStream = new XMFLOAT3[VectorCount];

			int thesize = Marshal::SizeOf(Projection);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Projection, pnt, false);
			memcpy(&xProjection, (void*)pnt, thesize);
			Marshal::StructureToPtr(View, pnt, true);
			memcpy(&xView, (void*)pnt, thesize);
			Marshal::StructureToPtr(World, pnt, true);
			memcpy(&xWorld, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
				plocaInputStream[i].z = pInputStream[i]->z;
			}

			DDMath::XMVector3ProjectStream((XMFLOAT3*)plocaOutputStream, OutputStride, (XMFLOAT3*)plocaInputStream,
				InputStride, VectorCount, ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ,
				xProjection, xView, xWorld);
			pin_ptr< dmXMFLOAT3^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
				locaIOut[i]->z = plocaOutputStream[i].z;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;

			return;
		}
		inline static dmXMVECTOR^ XMVector3Rotate(dmXMVECTOR^ V, dmXMVECTOR^ RotationQuaternion)
		{
			XMVECTOR xV;
			XMVECTOR xRotationQuaternion;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(RotationQuaternion, pnt, true);
			memcpy(&xRotationQuaternion, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Rotate(xV, xRotationQuaternion);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3Transform(dmXMVECTOR^ V, dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Transform(xV, xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector3TransformCoord(dmXMVECTOR^ V, dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3TransformCoord(xV, xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVector3TransformCoordStream([Out] array<dmXMFLOAT3^>^% pOutputStream, int32_t OutputStride, array<dmXMFLOAT3^>^ pInputStream, int32_t InputStride, int32_t VectorCount, dmXMMATRIX^ M)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT3^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT3();
			}
			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT3));
			assert(OutputStride >= sizeof(XMFLOAT3));
			XMMATRIX xM;
			XMFLOAT3* plocaInputStream = new XMFLOAT3[VectorCount];
			XMFLOAT3* plocaOutputStream = new XMFLOAT3[VectorCount];

			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
				plocaInputStream[i].z = pInputStream[i]->z;
			}

			DDMath::XMVector3TransformCoordStream((XMFLOAT3*)plocaOutputStream, OutputStride, (XMFLOAT3*)plocaInputStream, InputStride, VectorCount, xM);
			pin_ptr< dmXMFLOAT3^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
				locaIOut[i]->z = plocaOutputStream[i].z;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;

			return;
		}
		inline static dmXMVECTOR^ XMVector3TransformNormal(dmXMVECTOR^ V, dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3TransformNormal(xV, xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVector3TransformNormalStream([Out] array<dmXMFLOAT3^>^% pOutputStream, int32_t OutputStride, array<dmXMFLOAT3^>^ pInputStream, int32_t InputStride, int32_t VectorCount, dmXMMATRIX^ M)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT3^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT3();
			}
			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT3));
			assert(OutputStride >= sizeof(XMFLOAT3));
			XMMATRIX xM;
			XMFLOAT3* plocaInputStream = new XMFLOAT3[VectorCount];
			XMFLOAT3* plocaOutputStream = new XMFLOAT3[VectorCount];

			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
				plocaInputStream[i].z = pInputStream[i]->z;
			}

			DDMath::XMVector3TransformNormalStream((XMFLOAT3*)plocaOutputStream, OutputStride, (XMFLOAT3*)plocaInputStream, InputStride, VectorCount, xM);
			pin_ptr< dmXMFLOAT3^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
				locaIOut[i]->z = plocaOutputStream[i].z;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;

			return;
		}
		inline static void XMVector3TransformStream([Out]array<dmXMFLOAT4^>^% pOutputStream, int32_t OutputStride, array<dmXMFLOAT3^>^ pInputStream, int32_t InputStride, int32_t VectorCount, dmXMMATRIX^ M)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT4^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT4();
			}
			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT3));
			assert(OutputStride >= sizeof(XMFLOAT4));
			XMMATRIX xM;
			XMFLOAT3* plocaInputStream = new XMFLOAT3[VectorCount];
			XMFLOAT4* plocaOutputStream = new XMFLOAT4[VectorCount];

			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
				plocaInputStream[i].z = pInputStream[i]->z;
			}

			DDMath::XMVector3TransformStream((XMFLOAT4*)plocaOutputStream, OutputStride, (XMFLOAT3*)plocaInputStream, InputStride, VectorCount, xM);
			pin_ptr< dmXMFLOAT4^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
				locaIOut[i]->z = plocaOutputStream[i].z;
				locaIOut[i]->w = plocaOutputStream[i].w;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;

			return;
		}
		inline static dmXMVECTOR^ XMVector3Unproject(dmXMVECTOR^ V, float ViewportX, float ViewportY, float ViewportWidth,
			float ViewportHeight, float ViewportMinZ, float ViewportMaxZ, dmXMMATRIX^ Projection, dmXMMATRIX^ View, dmXMMATRIX^ World)
		{
			XMVECTOR xV;
			XMMATRIX xProjection;
			XMMATRIX xView;
			XMMATRIX xWorld;
			int thesize = Marshal::SizeOf(Projection);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Projection, pnt, false);
			memcpy(&xProjection, (void*)pnt, thesize);
			Marshal::StructureToPtr(View, pnt, true);
			memcpy(&xView, (void*)pnt, thesize);
			Marshal::StructureToPtr(World, pnt, true);
			memcpy(&xWorld, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector3Unproject(xV, ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ, xProjection, xView, xWorld);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVector3UnprojectStream([Out]array<dmXMFLOAT3^>^% pOutputStream, int32_t OutputStride,
			array<dmXMFLOAT3^>^ pInputStream, int32_t InputStride, int32_t VectorCount, float ViewportX,
			float ViewportY, float ViewportWidth, float ViewportHeight, float ViewportMinZ, float ViewportMaxZ,
			dmXMMATRIX^ Projection, dmXMMATRIX^ View, dmXMMATRIX^ World)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT3^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT3();
			}
			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT3));
			assert(OutputStride >= sizeof(XMFLOAT3));
			XMMATRIX xProjection;
			XMMATRIX xView;
			XMMATRIX xWorld;
			XMFLOAT3* plocaInputStream = new XMFLOAT3[VectorCount];
			XMFLOAT3* plocaOutputStream = new XMFLOAT3[VectorCount];

			int thesize = Marshal::SizeOf(Projection);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Projection, pnt, false);
			memcpy(&xProjection, (void*)pnt, thesize);
			Marshal::StructureToPtr(View, pnt, true);
			memcpy(&xView, (void*)pnt, thesize);
			Marshal::StructureToPtr(World, pnt, true);
			memcpy(&xWorld, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
				plocaInputStream[i].z = pInputStream[i]->z;
			}
			DDMath::XMVector3UnprojectStream((XMFLOAT3*)plocaOutputStream, OutputStride, (XMFLOAT3*)plocaInputStream,
				InputStride, VectorCount, ViewportX, ViewportY, ViewportWidth, ViewportHeight, ViewportMinZ, ViewportMaxZ,
				xProjection, xView, xWorld);
			pin_ptr< dmXMFLOAT3^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
				locaIOut[i]->z = plocaOutputStream[i].z;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;

			return;
		}
		// 3D Vector Transformation Functions - End

		// 4D Vector Comparison Functions - Start

		inline static bool XMVector4Equal(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4Equal(xV1, xV2);
		}
		inline static bool XMVector4EqualInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4EqualInt(xV1, xV2);
		}
		inline static uint32_t XMVector4EqualIntR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4EqualIntR(xV1, xV2);
		}
		inline static uint32_t XMVector4EqualR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4EqualR(xV1, xV2);
		}
		inline static bool XMVector4Greater(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4Greater(xV1, xV2);
		}
		inline static bool XMVector4GreaterOrEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4GreaterOrEqual(xV1, xV2);
		}
		inline static uint32_t XMVector4GreaterOrEqualR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4GreaterOrEqualR(xV1, xV2);
		}
		inline static uint32_t XMVector4GreaterR(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4GreaterR(xV1, xV2);
		}
		inline static bool XMVector4IsInfinite(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4IsInfinite(xV);
		}
		inline static bool XMVector4IsNaN(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4IsNaN(xV);
		}
		inline static bool XMVector4Less(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4Less(xV1, xV2);
		}
		inline static bool XMVector4LessOrEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4LessOrEqual(xV1, xV2);
		}
		inline static bool XMVector4NearEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ Epsilon)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xEpsilon;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Epsilon, pnt, true);
			memcpy(&xEpsilon, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4NearEqual(xV1, xV2, xEpsilon);
		}
		inline static bool XMVector4NotEqual(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4NotEqual(xV1, xV2);
		}
		inline static bool XMVector4NotEqualInt(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4NotEqualInt(xV1, xV2);
		}
		// 4D Vector Comparison Functions - End

		// 4D Vector Geometric Functions - Start

		inline static dmXMVECTOR^ XMVector4AngleBetweenNormals(dmXMVECTOR^ N1, dmXMVECTOR^ N2)
		{
			XMVECTOR xN1;
			XMVECTOR xN2;
			int thesize = Marshal::SizeOf(N1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(N1, pnt, false);
			memcpy(&xN1, (void*)pnt, thesize);
			Marshal::StructureToPtr(N2, pnt, true);
			memcpy(&xN2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4AngleBetweenNormals(xN1, xN2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4AngleBetweenNormalsEst(dmXMVECTOR^ N1, dmXMVECTOR^ N2)
		{
			XMVECTOR xN1;
			XMVECTOR xN2;
			int thesize = Marshal::SizeOf(N1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(N1, pnt, false);
			memcpy(&xN1, (void*)pnt, thesize);
			Marshal::StructureToPtr(N2, pnt, true);
			memcpy(&xN2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4AngleBetweenNormalsEst(xN1, xN2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4AngleBetweenVectors(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4AngleBetweenVectors(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4ClampLength(dmXMVECTOR^ V, float LengthMin, float LengthMax)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4ClampLength(xV, LengthMin, LengthMax);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4ClampLengthV(dmXMVECTOR^ V, dmXMVECTOR^ LengthMin, dmXMVECTOR^ LengthMax)
		{
			XMVECTOR xV;
			XMVECTOR xLengthMin;
			XMVECTOR xLengthMax;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(LengthMin, pnt, true);
			memcpy(&xLengthMin, (void*)pnt, thesize);
			Marshal::StructureToPtr(LengthMax, pnt, true);
			memcpy(&xLengthMax, (void*)pnt, thesize);
			assert((DDMath::XMVectorGetY(xLengthMin) == DDMath::XMVectorGetX(xLengthMin)) && (DDMath::XMVectorGetZ(xLengthMin) == DDMath::XMVectorGetX(xLengthMin)) && (DDMath::XMVectorGetW(xLengthMin) == DDMath::XMVectorGetX(xLengthMin)));
			assert((DDMath::XMVectorGetY(xLengthMax) == DDMath::XMVectorGetX(xLengthMax)) && (DDMath::XMVectorGetZ(xLengthMax) == DDMath::XMVectorGetX(xLengthMax)) && (DDMath::XMVectorGetW(xLengthMax) == DDMath::XMVectorGetX(xLengthMax)));
			assert(DDMath::XMVector4GreaterOrEqual(xLengthMin, g_XMZero.v));
			assert(DDMath::XMVector4GreaterOrEqual(xLengthMax, g_XMZero.v));
			assert(DDMath::XMVector4GreaterOrEqual(xLengthMax, xLengthMin));
			XMVECTOR result = DDMath::XMVector4ClampLengthV(xV, xLengthMin, xLengthMax);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4Cross(dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ V3)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xV3;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(V3, pnt, true);
			memcpy(&xV3, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4Cross(xV1, xV2, xV3);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4Dot(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
		{
			XMVECTOR xV1;
			XMVECTOR xV2;
			int thesize = Marshal::SizeOf(V1);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V1, pnt, false);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4Dot(xV1, xV2);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static bool XMVector4InBounds(dmXMVECTOR^ V, dmXMVECTOR^ Bounds)
		{
			XMVECTOR xV;
			XMVECTOR xBounds;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			Marshal::StructureToPtr(Bounds, pnt, true);
			memcpy(&xBounds, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::XMVector4InBounds(xV, xBounds);
		}
		inline static dmXMVECTOR^ XMVector4Length(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4Length(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4LengthEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4LengthEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4LengthSq(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4LengthSq(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4Normalize(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4Normalize(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4NormalizeEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4NormalizeEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4Orthogonal(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4Orthogonal(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4ReciprocalLength(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4ReciprocalLength(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4ReciprocalLengthEst(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4ReciprocalLengthEst(xV);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4Reflect(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4Reflect(xIncident, xNormal);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4Refract(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal, float RefractionIndex)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4Refract(xIncident, xNormal, RefractionIndex);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVector4RefractV(dmXMVECTOR^ Incident, dmXMVECTOR^ Normal, dmXMVECTOR^ RefractionIndex)
		{
			XMVECTOR xIncident;
			XMVECTOR xNormal;
			XMVECTOR xRefractionIndex;
			int thesize = Marshal::SizeOf(Incident);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Incident, pnt, false);
			memcpy(&xIncident, (void*)pnt, thesize);
			Marshal::StructureToPtr(Normal, pnt, true);
			memcpy(&xNormal, (void*)pnt, thesize);
			Marshal::StructureToPtr(RefractionIndex, pnt, true);
			memcpy(&xRefractionIndex, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4RefractV(xIncident, xNormal, xRefractionIndex);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// 4D Vector Geometric Functions - End

		//  4D Vector Transformation Functions - Start

		inline static dmXMVECTOR^ XMVector4Transform(dmXMVECTOR^ V, dmXMMATRIX^ M)
		{
			XMMATRIX xM;
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			thesize = Marshal::SizeOf(V);
			Marshal::StructureToPtr(V, pnt, true);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVector4Transform(xV, xM);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static void XMVector4TransformStream([Out]array<dmXMFLOAT4^>^% pOutputStream, int32_t OutputStride, array<dmXMFLOAT4^>^ pInputStream, int32_t InputStride, int32_t VectorCount, dmXMMATRIX^ M)
		{
			if (pOutputStream == nullptr)
			{
				pOutputStream = gcnew array<dmXMFLOAT4^>(VectorCount);
				for (int i = 0; i < VectorCount;i++)
					pOutputStream[i] = gcnew dmXMFLOAT4();
			}
			assert(pOutputStream != nullptr);
			assert(pInputStream != nullptr);
			assert(InputStride >= sizeof(XMFLOAT4));
			assert(OutputStride >= sizeof(XMFLOAT4));
			XMMATRIX xM;
			XMFLOAT4* plocaInputStream = new XMFLOAT4[VectorCount];
			XMFLOAT4* plocaOutputStream = new XMFLOAT4[VectorCount];

			int thesize = Marshal::SizeOf(M);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(M, pnt, false);
			memcpy(&xM, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);

			for (int i = 0; i < VectorCount;i++)
			{
				plocaInputStream[i].x = pInputStream[i]->x;
				plocaInputStream[i].y = pInputStream[i]->y;
				plocaInputStream[i].z = pInputStream[i]->z;
				plocaInputStream[i].w = pInputStream[i]->w;
			}

			DDMath::XMVector4TransformStream((XMFLOAT4*)plocaOutputStream, OutputStride, (XMFLOAT4*)plocaInputStream, InputStride, VectorCount, xM);
			pin_ptr< dmXMFLOAT4^ > locaIOut = &pOutputStream[0];
			for (int i = 0; i < VectorCount;i++)
			{
				locaIOut[i]->x = plocaOutputStream[i].x;
				locaIOut[i]->y = plocaOutputStream[i].y;
				locaIOut[i]->z = plocaOutputStream[i].z;
				locaIOut[i]->w = plocaOutputStream[i].w;
			}
			delete[] plocaInputStream;
			delete[] plocaOutputStream;

			return;
		}
		//  4D Vector Transformation Functions - End

		// Other - Start

		generic <typename T> inline static T XMMin(T a, T b)
		{
			Type^typ = T::typeid;
			if (typ == int::typeid)
			{
				int32_t aInt = (int32_t)a;
				int32_t bInt = (int32_t)b;
				return (T)((aInt < bInt) ? aInt : bInt);
			}
			else if (typ == uint32_t::typeid)
			{
				uint32_t aUInt = (uint32_t)a;
				uint32_t bUInt = (uint32_t)b;
				return (T)((aUInt < bUInt) ? aUInt : bUInt);
			}
			else if (typ == float::typeid)
			{
				float aFloat = (float)a;
				float bFloat = (float)b;
				return (T)((aFloat < bFloat) ? aFloat : bFloat);
			}
			else if (typ == dmXMVECTOR::typeid)
			{
				dmXMVECTOR^ aVect1 = (dmXMVECTOR^)a;
				dmXMVECTOR^ aVect2 = (dmXMVECTOR^)b;
				dmXMVECTOR^ aRes = gcnew dmXMVECTOR();
				aRes->dmXMVECTOR_f32->x = XMMin(aVect1->dmXMVECTOR_f32->x, aVect2->dmXMVECTOR_f32->x);
				aRes->dmXMVECTOR_f32->y = XMMin(aVect1->dmXMVECTOR_f32->y, aVect2->dmXMVECTOR_f32->y);
				aRes->dmXMVECTOR_f32->z = XMMin(aVect1->dmXMVECTOR_f32->z, aVect2->dmXMVECTOR_f32->z);
				aRes->dmXMVECTOR_f32->w = XMMin(aVect1->dmXMVECTOR_f32->w, aVect2->dmXMVECTOR_f32->w);
				return (T)(aRes);
			}
			else
				return (T)0; // Otherwise optimization breaks. May be there is a better solution. 
		}
		generic <typename T> inline static T XMMax(T a, T b)
		{
			Type^typ = T::typeid;
			if (typ == int32_t::typeid)
			{
				int32_t aInt = (int32_t)a;
				int32_t bInt = (int32_t)b;
				return (T)((aInt > bInt) ? aInt : bInt);
			}
			else if (typ == uint32_t::typeid)
			{
				uint32_t aUInt = (uint32_t)a;
				uint32_t bUInt = (uint32_t)b;
				return (T)((aUInt > bUInt) ? aUInt : bUInt);
			}
			else if (typ == float::typeid)
			{
				float aFloat = (float)a;
				float bFloat = (float)b;
				return (T)((aFloat > bFloat) ? aFloat : bFloat);
			}
			else if (typ == dmXMVECTOR::typeid)
			{
				dmXMVECTOR^ aVect1 = (dmXMVECTOR^)a;
				dmXMVECTOR^ aVect2 = (dmXMVECTOR^)b;
				dmXMVECTOR^ aRes = gcnew dmXMVECTOR();
				aRes->dmXMVECTOR_f32->x = XMMax(aVect1->dmXMVECTOR_f32->x, aVect2->dmXMVECTOR_f32->x);
				aRes->dmXMVECTOR_f32->y = XMMax(aVect1->dmXMVECTOR_f32->y, aVect2->dmXMVECTOR_f32->y);
				aRes->dmXMVECTOR_f32->z = XMMax(aVect1->dmXMVECTOR_f32->z, aVect2->dmXMVECTOR_f32->z);
				aRes->dmXMVECTOR_f32->w = XMMax(aVect1->dmXMVECTOR_f32->w, aVect2->dmXMVECTOR_f32->w);
				return (T)(aRes);
			}
			else
				return T(0); // Otherwise optimization breaks. May be there is a better solution.

		}
		// Other - End

		// Utility Functions - Start

		inline static bool XMComparisonAllFalse(uint32_t CR)
		{
			return DDMath::XMComparisonAllFalse(CR);
		}

		inline static bool XMComparisonAllInBounds(uint32_t CR)
		{
			return DDMath::XMComparisonAllInBounds(CR);
		}

		inline static bool XMComparisonAllTrue(uint32_t CR)
		{
			return DDMath::XMComparisonAllTrue(CR);
		}

		inline static bool XMComparisonAnyFalse(uint32_t CR)
		{
			return DDMath::XMComparisonAnyFalse(CR);
		}

		inline static bool XMComparisonAnyOutOfBounds(uint32_t CR)
		{
			return DDMath::XMComparisonAnyOutOfBounds(CR);
		}

		inline static bool XMComparisonAnyTrue(uint32_t CR)
		{
			return DDMath::XMComparisonAnyTrue(CR);
		}

		inline static bool XMComparisonMixed(uint32_t CR)
		{
			return DDMath::XMComparisonMixed(CR);
		}
		inline static dmXMVECTOR^ XMFresnelTerm(dmXMVECTOR^ CosIncidentAngle, dmXMVECTOR^ RefractionIndex)
		{
			XMVECTOR xCosIncidentAngle;
			XMVECTOR xRefractionIndex;
			int thesize = Marshal::SizeOf(CosIncidentAngle);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(CosIncidentAngle, pnt, false);
			memcpy(&xCosIncidentAngle, (void*)pnt, thesize);
			Marshal::StructureToPtr(RefractionIndex, pnt, true);
			memcpy(&xRefractionIndex, (void*)pnt, thesize);
			assert(!DDMath::XMVector4IsInfinite(xCosIncidentAngle));
			XMVECTOR result = DDMath::XMFresnelTerm(xCosIncidentAngle, xRefractionIndex);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}

		inline static bool XMVerifyCPUSupport()
		{
			return DDMath::XMVerifyCPUSupport();
		}
		// Utility Functions - End

		// Vector Accessor Functions - Start

		inline static float XMVectorGetByIndex(dmXMVECTOR^ V, int32_t i)
		{
			assert(i < 4);
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetByIndex(xV, i);
		}
		inline static void XMVectorGetByIndexPtr([Out] float% f, dmXMVECTOR^ V, int32_t i)
		{
			assert(i < 4);
			XMVECTOR xV;
			float xf;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetByIndexPtr(&xf, xV, i);
			f = xf;
		}
		inline static uint32_t XMVectorGetIntByIndex(dmXMVECTOR^ V, int32_t i)
		{
			assert(i < 4);
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetIntByIndex(xV, i);
		}
		inline static void XMVectorGetIntByIndexPtr([Out] uint32_t% x, dmXMVECTOR^ V, int32_t i)
		{
			assert(i < 4);
			XMVECTOR xV;
			uint32_t xx;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetIntByIndexPtr(&xx, xV, i);
			x = xx;
		}
		inline static uint32_t XMVectorGetIntW(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetIntW(xV);
		}
		inline static void XMVectorGetIntWPtr([Out] uint32_t% w, dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			uint32_t xw;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetIntWPtr(&xw, xV);
			w = xw;
		}
		inline static uint32_t XMVectorGetIntX(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetIntX(xV);
		}
		inline static void XMVectorGetIntXPtr([Out] uint32_t% x, dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			uint32_t xx;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetIntXPtr(&xx, xV);
			x = xx;
		}
		inline static uint32_t XMVectorGetIntY(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetIntY(xV);
		}
		inline static void XMVectorGetIntYPtr([Out] uint32_t% y, dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			uint32_t xy;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetIntYPtr(&xy, xV);
			y = xy;
		}
		inline static uint32_t XMVectorGetIntZ(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetIntZ(xV);
		}
		inline static void XMVectorGetIntZPtr([Out] uint32_t% z, dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			uint32_t xz;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetIntZPtr(&xz, xV);
			z = xz;
		}
		inline static float XMVectorGetW(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetW(xV);
		}
		inline static void XMVectorGetWPtr([Out] float% f, dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			float_t xf;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetWPtr(&xf, xV);
			f = xf;
		}
		inline static float XMVectorGetX(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetX(xV);
		}
		inline static void XMVectorGetXPtr([Out] float% f, dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			float_t xf;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetXPtr(&xf, xV);
			f = xf;
		}
		inline static float XMVectorGetY(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetY(xV);
		}
		inline static void XMVectorGetYPtr([Out] float% f, dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			float_t xf;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetYPtr(&xf, xV);
			f = xf;
		}
		inline static float XMVectorGetZ(dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			return DDMath::XMVectorGetZ(xV);
		}
		inline static void XMVectorGetZPtr([Out] float% f, dmXMVECTOR^ V)
		{
			XMVECTOR xV;
			float_t xf;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMVectorGetZPtr(&xf, xV);
			f = xf;
		}
		inline static dmXMVECTOR^ XMVectorSetByIndex(dmXMVECTOR^ V, float f, int32_t i)
		{
			assert(i < 4);
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetByIndex(xV, f, i);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetByIndexPtr(dmXMVECTOR^ V, float% f, int32_t i)
		{
			assert(i < 4);
			XMVECTOR xV;
			float xf = f;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetByIndexPtr(xV, &xf, i);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntByIndex(dmXMVECTOR^ V, uint32_t x, int32_t i)
		{
			assert(i < 4);
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntByIndex(xV, x, i);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntByIndexPtr(dmXMVECTOR^ V, uint32_t% x, int32_t i)
		{
			assert(i < 4);
			XMVECTOR xV;
			uint32_t xx = x;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntByIndexPtr(xV, &xx, i);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntW(dmXMVECTOR^ V, uint32_t w)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntW(xV, w);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntWPtr(dmXMVECTOR^ V, uint32_t% w)
		{
			XMVECTOR xV;
			uint32_t xw = w;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntWPtr(xV, &xw);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntX(dmXMVECTOR^ V, uint32_t x)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntX(xV, x);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntXPtr(dmXMVECTOR^ V, uint32_t% x)
		{
			XMVECTOR xV;
			uint32_t xx = x;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntXPtr(xV, &xx);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntY(dmXMVECTOR^ V, uint32_t y)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntY(xV, y);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntYPtr(dmXMVECTOR^ V, uint32_t% y)
		{
			XMVECTOR xV;
			uint32_t xy = y;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntYPtr(xV, &xy);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntZ(dmXMVECTOR^ V, uint32_t z)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntZ(xV, z);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetIntZPtr(dmXMVECTOR^ V, uint32_t% z)
		{
			XMVECTOR xV;
			uint32_t xz = z;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetIntZPtr(xV, &xz);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetW(dmXMVECTOR^ V, float w)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetW(xV, w);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetWPtr(dmXMVECTOR^ V, float% w)
		{
			XMVECTOR xV;
			float xw = w;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetWPtr(xV, &xw);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetX(dmXMVECTOR^ V, float x)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetX(xV, x);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetXPtr(dmXMVECTOR^ V, float% x)
		{
			XMVECTOR xV;
			float xx = x;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetXPtr(xV, &xx);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetY(dmXMVECTOR^ V, float y)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetY(xV, y);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetYPtr(dmXMVECTOR^ V, float% y)
		{
			XMVECTOR xV;
			float xy = y;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetYPtr(xV, &xy);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetZ(dmXMVECTOR^ V, float z)
		{
			XMVECTOR xV;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetZ(xV, z);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMVectorSetZPtr(dmXMVECTOR^ V, float% z)
		{
			XMVECTOR xV;
			float xz = z;
			int thesize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, thesize);
			XMVECTOR result = DDMath::XMVectorSetZPtr(xV, &xz);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		// Vector Accessor Functions - End

		// Vector Load Functions Start

		inline static dmXMVECTOR^ XMLoadByte2(dmXMBYTE2^ pSource)
		{
			assert(pSource);
			XMBYTE2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadByte2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}

		inline static dmXMVECTOR^ XMLoadFloat3PK(dmXMFLOAT3PK^ pSource)
		{
			assert(pSource);
			XMFLOAT3PK xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadFloat3PK(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}

		inline static dmXMVECTOR^ XMLoadFloat3SE(dmXMFLOAT3SE^ pSource)
		{
			assert(pSource);
			XMFLOAT3SE xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadFloat3SE(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}

		inline static dmXMVECTOR^ XMLoadByteN2(dmXMBYTEN2^ pSource)
		{
			assert(pSource);
			XMBYTEN2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadByteN2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadByte4(dmXMBYTE4^ pSource)
		{
			assert(pSource);
			XMBYTE4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadByte4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadByteN4(dmXMBYTEN4^ pSource)
		{
			assert(pSource);
			XMBYTEN4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadByteN4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadColor(dmXMCOLOR^ pSource)
		{
			assert(pSource);
			XMCOLOR xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadColor(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadDec4(dmXMDEC4^ pSource)
		{
			assert(pSource);
			XMDEC4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadDec4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadDecN4(dmXMDECN4^ pSource)
		{
			assert(pSource);
			XMDECN4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadDecN4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadFloat(float% pSource)
		{
			float xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadFloat(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMMATRIX^ XMLoadFloat3x3(dmXMFLOAT3X3^ pSource)
		{
			XMFLOAT3X3 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMMATRIX result = DDMath::XMLoadFloat3x3(&xpSource);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMMATRIX = (dmXMMATRIX^)Marshal::PtrToStructure(pnt2, dmXMMATRIX::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMMATRIX;
		}
		inline static dmXMVECTOR^ XMLoadFloat3(dmXMFLOAT3^ pSource)
		{
			XMFLOAT3 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadFloat3(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadFloat3A(dmXMFLOAT3A^ pSource)
		{
			return XMLoadFloat3(pSource);
		}
		inline static dmXMVECTOR^ XMLoadFloat2(dmXMFLOAT2^ pSource)
		{
			XMFLOAT2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadFloat2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}

		inline static dmXMVECTOR^ XMLoadFloat2A(dmXMFLOAT2A^ pSource)
		{
			return XMLoadFloat2(pSource);
		}

		inline static dmXMVECTOR^ XMLoadFloat4(dmXMFLOAT4^ pSource)
		{
			XMFLOAT4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadFloat4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadFloat4A(dmXMFLOAT4A^ pSource)
		{
			return XMLoadFloat4(pSource);
		}

		inline static dmXMMATRIX^ XMLoadFloat4x3(dmXMFLOAT4X3^ pSource)
		{
			XMFLOAT4X3 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMMATRIX result = DDMath::XMLoadFloat4x3(&xpSource);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMMATRIX = (dmXMMATRIX^)Marshal::PtrToStructure(pnt2, dmXMMATRIX::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMMATRIX;
		}

		inline static dmXMMATRIX^ XMLoadFloat4x3A(dmXMFLOAT4X3A^ pSource)
		{
			return XMLoadFloat4x3(pSource);
		}

		inline static dmXMMATRIX^ XMLoadFloat4x4(dmXMFLOAT4X4^ pSource)
		{
			XMFLOAT4X4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMMATRIX result = DDMath::XMLoadFloat4x4(&xpSource);
			dmXMMATRIX^ mydmXMMATRIX = gcnew dmXMMATRIX();
			thesize = Marshal::SizeOf(mydmXMMATRIX);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMMATRIX = (dmXMMATRIX^)Marshal::PtrToStructure(pnt2, dmXMMATRIX::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMMATRIX;
		}
		inline static dmXMMATRIX^ XMLoadFloat4x4A(dmXMFLOAT4X4A^ pSource)
		{
			return XMLoadFloat4x4(pSource);
		}
		inline static dmXMVECTOR^ XMLoadHalf2(dmXMHALF2^ pSource)
		{
			assert(pSource);
			XMHALF2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadHalf2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadHalf4(dmXMHALF4^ pSource)
		{
			assert(pSource);
			XMHALF4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadHalf4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadInt(uint32_t% pSource)
		{
			uint32_t xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadInt(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadInt2(array<uint32_t>^ pSource)
		{
			uint32_t xpSource[2];
			xpSource[0] = pSource[0];
			xpSource[1] = pSource[1];
			XMVECTOR result = DDMath::XMLoadInt2(xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadInt2A(array<uint32_t>^ pSource)
		{
			return XMLoadInt2(pSource);
		}
		inline static dmXMVECTOR^ XMLoadInt3(array<uint32_t>^ pSource)
		{
			uint32_t xpSource[3];
			xpSource[0] = pSource[0];
			xpSource[1] = pSource[1];
			xpSource[2] = pSource[2];
			XMVECTOR result = DDMath::XMLoadInt3(xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadInt3A(array<uint32_t>^ pSource)
		{
			return XMLoadInt3(pSource);
		}
		inline static dmXMVECTOR^ XMLoadInt4(array<uint32_t>^ pSource)
		{
			uint32_t xpSource[4];
			xpSource[0] = pSource[0];
			xpSource[1] = pSource[1];
			xpSource[2] = pSource[2];
			xpSource[3] = pSource[3];
			XMVECTOR result = DDMath::XMLoadInt4(xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			int thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadInt4A(array<uint32_t>^ pSource)
		{
			return XMLoadInt4(pSource);
		}
		inline static dmXMVECTOR^ XMLoadShort2(dmXMSHORT2^ pSource)
		{
			assert(pSource);
			XMSHORT2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadShort2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadShort4(dmXMSHORT4^ pSource)
		{
			assert(pSource);
			XMSHORT4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadShort4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadShortN2(dmXMSHORTN2^ pSource)
		{
			assert(pSource);
			XMSHORTN2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadShortN2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadShortN4(dmXMSHORTN4^ pSource)
		{
			assert(pSource);
			XMSHORTN4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadShortN4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadSInt2(dmXMINT2^ pSource)
		{
			XMINT2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadSInt2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadSInt3(dmXMINT3^ pSource)
		{
			XMINT3 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadSInt3(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadSInt4(dmXMINT4^ pSource)
		{
			XMINT4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadSInt4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadU555(dmXMU555^ pSource)
		{
			assert(pSource);
			XMU555 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadU555(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadU565(dmXMU565^ pSource)
		{
			assert(pSource);
			XMU565 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadU565(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUByte2(dmXMUBYTE2^ pSource)
		{
			assert(pSource);
			XMUBYTE2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUByte2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUByte4(dmXMUBYTE4^ pSource)
		{
			assert(pSource);
			XMUBYTE4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUByte4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUByteN2(dmXMUBYTEN2^ pSource)
		{
			assert(pSource);
			XMUBYTEN2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUByteN2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUByteN4(dmXMUBYTEN4^ pSource)
		{
			assert(pSource);
			XMUBYTEN4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUByteN4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUDec4(dmXMUDEC4^ pSource)
		{
			assert(pSource);
			XMUDEC4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUDec4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUDecN4(dmXMUDECN4^ pSource)
		{
			assert(pSource);
			XMUDECN4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUDecN4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUDecN4_XR(dmXMUDECN4^ pSource)
		{
			assert(pSource);
			XMUDECN4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUDecN4_XR(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUInt2(dmXMUINT2^ pSource)
		{
			XMUINT2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUInt2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUInt3(dmXMUINT3^ pSource)
		{
			XMUINT3 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUInt3(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUInt4(dmXMUINT4^ pSource)
		{
			XMUINT4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUInt4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUNibble4(dmXMUNIBBLE4^ pSource)
		{
			assert(pSource);
			XMUNIBBLE4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUNibble4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUShort2(dmXMUSHORT2^ pSource)
		{
			assert(pSource);
			XMUSHORT2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUShort2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}

		inline static dmXMVECTOR^ XMLoadUShort4(dmXMUSHORT4^ pSource)
		{
			assert(pSource);
			XMUSHORT4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUShort4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUShortN2(dmXMUSHORTN2^ pSource)
		{
			assert(pSource);
			XMUSHORTN2 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUShortN2(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadUShortN4(dmXMUSHORTN4^ pSource)
		{
			assert(pSource);
			XMUSHORTN4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadUShortN4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadXDec4(dmXMXDEC4^ pSource)
		{
			assert(pSource);
			XMXDEC4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadXDec4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		inline static dmXMVECTOR^ XMLoadXDecN4(dmXMXDECN4^ pSource)
		{
			assert(pSource);
			XMXDECN4 xpSource;
			int thesize = Marshal::SizeOf(pSource);
			IntPtr pnt1 = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(pSource, pnt1, false);
			memcpy(&xpSource, (void*)pnt1, thesize);
			Marshal::FreeHGlobal(pnt1);
			XMVECTOR result = DDMath::XMLoadXDecN4(&xpSource);
			dmXMVECTOR^ mydmXMVECTOR = gcnew dmXMVECTOR();
			thesize = Marshal::SizeOf(mydmXMVECTOR);
			IntPtr pnt2 = Marshal::AllocHGlobal(thesize);
			memcpy((void*)pnt2, &result, thesize);
			mydmXMVECTOR = (dmXMVECTOR^)Marshal::PtrToStructure(pnt2, dmXMVECTOR::typeid);
			Marshal::FreeHGlobal(pnt2);
			return mydmXMVECTOR;
		}
		// Vector Load Functions End

		// Vector Store Functions Start
		inline static void XMStoreByte2([Out] dmXMBYTE2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMBYTE2();

			assert(pDestination);
			XMBYTE2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreByte2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreByte4([Out] dmXMBYTE4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMBYTE4();

			assert(pDestination);
			XMBYTE4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreByte4(&xpDestination, xV);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreByteN2([Out] dmXMBYTEN2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMBYTEN2();

			assert(pDestination);
			XMBYTEN2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreByteN2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreByteN4([Out] dmXMBYTEN4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMBYTEN4();

			assert(pDestination);
			XMBYTEN4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreByteN4(&xpDestination, xV);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreColor([Out] dmXMCOLOR^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMCOLOR();

			assert(pDestination);
			XMCOLOR xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreColor(&xpDestination, xV);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreDec4([Out] dmXMDEC4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMDEC4();

			XMDEC4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreDec4(&xpDestination, xV);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreDecN4([Out] dmXMDECN4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMDECN4();

			assert(pDestination);
			XMDECN4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreDecN4(&xpDestination, xV);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreFloat([Out] float% pDestination, dmXMVECTOR^ V)
		{
			float xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreFloat(&xpDestination, xV);
			pDestination = xpDestination;
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreFloat2([Out] dmXMFLOAT2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT2();

			XMFLOAT2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreFloat2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreFloat2A([Out] dmXMFLOAT2A^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT2A();

			XMFLOAT2A xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreFloat2A(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreFloat3([Out] dmXMFLOAT3^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT3();

			XMFLOAT3 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreFloat3(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreFloat3A([Out] dmXMFLOAT3A^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT3A();

			XMFLOAT3A xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreFloat3A(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreFloat3PK([Out] dmXMFLOAT3PK^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT3PK();

			assert(pDestination);
			XMFLOAT3PK xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreFloat3PK(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreFloat3SE([Out] dmXMFLOAT3SE^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT3SE();

			assert(pDestination);
			XMFLOAT3SE xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreFloat3SE(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreFloat3x3([Out] dmXMFLOAT3X3^% pDestination, dmXMMATRIX^ M)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT3X3();

			XMFLOAT3X3 xpDestination;
			XMMATRIX xM;
			int theSize = Marshal::SizeOf(M);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(M, pnt1, false);
			memcpy(&xM, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreFloat3x3(&xpDestination, xM);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreFloat4([Out] dmXMFLOAT4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT4();

			XMFLOAT4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreFloat4(&xpDestination, xV);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreFloat4A([Out] dmXMFLOAT4A^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT4A();

			XMFLOAT4A xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt1, false);
			memcpy(&xV, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreFloat4A(&xpDestination, xV);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreFloat4x3([Out] dmXMFLOAT4X3^% pDestination, dmXMMATRIX^ M)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT4X3();

			XMFLOAT4X3 xpDestination;
			XMMATRIX xM;
			int theSize = Marshal::SizeOf(M);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(M, pnt1, false);
			memcpy(&xM, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreFloat4x3(&xpDestination, xM);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreFloat4x3A([Out] dmXMFLOAT4X3A^% pDestination, dmXMMATRIX^ M)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT4X3A();

			XMFLOAT4X3A xpDestination;
			XMMATRIX xM;
			int theSize = Marshal::SizeOf(M);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(M, pnt1, false);
			memcpy(&xM, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreFloat4x3A(&xpDestination, xM);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreFloat4x4([Out] dmXMFLOAT4X4^% pDestination, dmXMMATRIX^ M)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT4X4();

			XMFLOAT4X4 xpDestination;
			XMMATRIX xM;
			int theSize = Marshal::SizeOf(M);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(M, pnt1, false);
			memcpy(&xM, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreFloat4x4(&xpDestination, xM);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);
		}
		inline static void XMStoreFloat4x4A([Out] dmXMFLOAT4X4A^% pDestination, dmXMMATRIX^ M)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMFLOAT4X4A();

			XMFLOAT4X4A xpDestination;
			XMMATRIX xM;
			int theSize = Marshal::SizeOf(M);
			IntPtr pnt1 = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(M, pnt1, false);
			memcpy(&xM, (void*)pnt1, theSize);
			Marshal::FreeHGlobal(pnt1);
			DDMath::XMStoreFloat4x4A(&xpDestination, xM);

			theSize = Marshal::SizeOf(pDestination);
			IntPtr pnt2 = Marshal::AllocHGlobal(theSize);
			memcpy((void*)pnt2, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt2, pDestination);
			Marshal::FreeHGlobal(pnt2);

		}
		inline static void XMStoreHalf2([Out] dmXMHALF2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMHALF2();

			assert(pDestination);
			XMHALF2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreHalf2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreHalf4([Out] dmXMHALF4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMHALF4();

			assert(pDestination);
			XMHALF4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreHalf4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreInt([Out] uint32_t% pDestination, dmXMVECTOR^ V)
		{
			uint32_t xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreInt(&xpDestination, xV);
			pDestination = xpDestination;
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreInt2([Out] array<uint32_t>^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew array<uint32_t>(2);

			uint32_t xpDestination[2];
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreInt2(xpDestination, xV);

			pDestination[0] = xpDestination[0];
			pDestination[1] = xpDestination[1];
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreInt2A([Out] array<uint32_t>^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew array<uint32_t>(2);

			uint32_t xpDestination[2];
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreInt2A(xpDestination, xV);

			pDestination[0] = xpDestination[0];
			pDestination[1] = xpDestination[1];
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreInt3([Out] array<uint32_t>^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew array<uint32_t>(3);

			uint32_t xpDestination[3];
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreInt3(xpDestination, xV);

			pDestination[0] = xpDestination[0];
			pDestination[1] = xpDestination[1];
			pDestination[2] = xpDestination[2];
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreInt3A([Out] array<uint32_t>^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew array<uint32_t>(3);

			uint32_t xpDestination[3];
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreInt3A(xpDestination, xV);

			pDestination[0] = xpDestination[0];
			pDestination[1] = xpDestination[1];
			pDestination[2] = xpDestination[2];
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreInt4([Out] array<uint32_t>^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew array<uint32_t>(4);

			uint32_t xpDestination[4];
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreInt4(xpDestination, xV);

			pDestination[0] = xpDestination[0];
			pDestination[1] = xpDestination[1];
			pDestination[2] = xpDestination[2];
			pDestination[3] = xpDestination[3];
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreInt4A([Out] array<uint32_t>^% pDestination, dmXMVECTOR^ V)
		{
			XMStoreInt4(pDestination, V);
		}
		inline static void XMStoreShort2([Out] dmXMSHORT2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMSHORT2();

			assert(pDestination);
			XMSHORT2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreShort2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreShort4([Out] dmXMSHORT4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMSHORT4();

			assert(pDestination);
			XMSHORT4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreShort4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreShortN2([Out] dmXMSHORTN2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMSHORTN2();

			assert(pDestination);
			XMSHORTN2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreShortN2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreShortN4([Out] dmXMSHORTN4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMSHORTN4();

			assert(pDestination);
			XMSHORTN4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreShortN4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreSInt2([Out] dmXMINT2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMINT2();

			XMINT2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreSInt2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreSInt3([Out] dmXMINT3^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMINT3();

			XMINT3 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreSInt3(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreSInt4([Out] dmXMINT4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMINT4();

			XMINT4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreSInt4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreU555([Out] dmXMU555^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMU555();

			assert(pDestination);
			XMU555 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreU555(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreU565([Out] dmXMU565^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMU565();

			assert(pDestination);
			XMU565 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreU565(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUByte2([Out] dmXMUBYTE2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUBYTE2();

			assert(pDestination);
			XMUBYTE2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUByte2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUByte4([Out] dmXMUBYTE4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUBYTE4();

			assert(pDestination);
			XMUBYTE4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUByte4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUByteN2([Out] dmXMUBYTEN2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUBYTEN2();

			assert(pDestination);
			XMUBYTEN2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUByteN2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUByteN4([Out] dmXMUBYTEN4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUBYTEN4();

			assert(pDestination);
			XMUBYTEN4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUByteN4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUDec4([Out] dmXMUDEC4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUDEC4();

			assert(pDestination);
			XMUDEC4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUDec4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUDecN4([Out] dmXMUDECN4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUDECN4();

			assert(pDestination);
			XMUDECN4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUDecN4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUDecN4_XR([Out] dmXMUDECN4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUDECN4();

			assert(pDestination);
			XMUDECN4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUDecN4_XR(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUInt2([Out] dmXMUINT2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUINT2();

			XMUINT2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUInt2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUInt3([Out] dmXMUINT3^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUINT3();

			XMUINT3 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUInt3(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUInt4([Out] dmXMUINT4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUINT4();

			XMUINT4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUInt4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUNibble4([Out]dmXMUNIBBLE4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUNIBBLE4();

			assert(pDestination);
			XMUNIBBLE4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUNibble4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUShort4([Out] dmXMUSHORT4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUSHORT4();

			assert(pDestination);
			XMUSHORT4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUShort4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUShort2([Out]dmXMUSHORT2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUSHORT2();

			assert(pDestination);
			XMUSHORT2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUShort2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUShortN2([Out] dmXMUSHORTN2^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUSHORTN2();

			assert(pDestination);
			XMUSHORTN2 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUShortN2(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreUShortN4([Out]dmXMUSHORTN4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMUSHORTN4();

			assert(pDestination);
			XMUSHORTN4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreUShortN4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreXDec4([Out]dmXMXDEC4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMXDEC4();

			assert(pDestination);
			XMXDEC4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreXDec4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}
		inline static void XMStoreXDecN4([Out]dmXMXDECN4^% pDestination, dmXMVECTOR^ V)
		{
			if (pDestination == nullptr)
				pDestination = gcnew dmXMXDECN4();

			assert(pDestination);
			XMXDECN4 xpDestination;
			XMVECTOR xV;
			int theSize = Marshal::SizeOf(V);
			IntPtr pnt = Marshal::AllocHGlobal(theSize);
			Marshal::StructureToPtr(V, pnt, false);
			memcpy(&xV, (void*)pnt, theSize);
			DDMath::XMStoreXDecN4(&xpDestination, xV);
			memcpy((void*)pnt, &xpDestination, theSize);
			Marshal::PtrToStructure(pnt, pDestination);
			Marshal::FreeHGlobal(pnt);
		}

	};

	inline dmXMVECTOR^ operator+ (dmXMVECTOR^ V1, dmXMVECTOR^ V2)
	{
		return DMathClass::XMVectorAdd(V1, V2);
	}
	inline dmXMVECTOR^ operator*	(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
	{
		return DMathClass::XMVectorMultiply(V1, V2);
	}
	inline dmXMVECTOR^ operator-(dmXMVECTOR^ V1, dmXMVECTOR^ V2)
	{
		return DMathClass::XMVectorSubtract(V1, V2);
	}
	inline dmXMVECTOR^ operator- (dmXMVECTOR^ V)
	{
		return DMathClass::XMVectorNegate(V);
	}

	inline dmXMVECTOR^ operator*	(dmXMVECTOR^ V, float S)
	{
		return DMathClass::XMVectorScale(V, S);
	}
}

using namespace DMathLib;
namespace Collision
{
	public enum class PlaneIntersectionType { FRONT = 0, INTERSECTING = 1, BACK = 2 };
	public enum class ContainmentType { DISJOINT = 0, INTERSECTS = 1, CONTAINS = 2 };


	public ref struct TriangleTests
	{
	public:
		inline static bool Intersects(dmXMVECTOR^ Origin, dmXMVECTOR^ Direction, dmXMVECTOR^ V0, dmXMVECTOR^ V1, dmXMVECTOR^ V2, [Out] float% Dist)
		{
			XMVECTOR xOrigin;
			XMVECTOR xDirection;
			XMVECTOR xV0;
			XMVECTOR xV1;
			XMVECTOR xV2;
			float xDist;
			int thesize = Marshal::SizeOf(Origin);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(Origin, pnt, false);
			memcpy(&xOrigin, (void*)pnt, thesize);
			Marshal::StructureToPtr(Direction, pnt, true);
			memcpy(&xDirection, (void*)pnt, thesize);
			Marshal::StructureToPtr(V0, pnt, true);
			memcpy(&xV0, (void*)pnt, thesize);
			Marshal::StructureToPtr(V1, pnt, true);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			bool resBool = DDMath::Intersects1(xOrigin, xDirection, xV0, xV1, xV2, xDist);
			Dist = xDist;
			return resBool;
		}
		inline static bool Intersects(dmXMVECTOR^ A0, dmXMVECTOR^ A1, dmXMVECTOR^ A2, dmXMVECTOR^ B0, dmXMVECTOR^ B1, dmXMVECTOR^ B2)
		{
			XMVECTOR xA0;
			XMVECTOR xA1;
			XMVECTOR xA2;
			XMVECTOR xB0;
			XMVECTOR xB1;
			XMVECTOR xB2;
			int thesize = Marshal::SizeOf(A0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(A0, pnt, false);
			memcpy(&xA0, (void*)pnt, thesize);
			Marshal::StructureToPtr(A1, pnt, true);
			memcpy(&xA1, (void*)pnt, thesize);
			Marshal::StructureToPtr(A2, pnt, true);
			memcpy(&xA2, (void*)pnt, thesize);
			Marshal::StructureToPtr(B0, pnt, true);
			memcpy(&xB0, (void*)pnt, thesize);
			Marshal::StructureToPtr(B1, pnt, true);
			memcpy(&xB1, (void*)pnt, thesize);
			Marshal::StructureToPtr(B2, pnt, true);
			memcpy(&xB2, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return DDMath::Intersects2(xA0, xA1, xA2, xB0, xB1, xB2);
		}
		inline static PlaneIntersectionType Intersects(dmXMVECTOR^ V0, dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ Plane)
		{
			XMVECTOR xV0;
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xPlane;
			int thesize = Marshal::SizeOf(V0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V0, pnt, false);
			memcpy(&xV0, (void*)pnt, thesize);
			Marshal::StructureToPtr(V1, pnt, true);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Plane, pnt, true);
			memcpy(&xPlane, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return (PlaneIntersectionType)DDMath::Intersects3(xV0, xV1, xV2, xPlane);
		}
		inline static ContainmentType ContainedBy(dmXMVECTOR^ V0, dmXMVECTOR^ V1, dmXMVECTOR^ V2, dmXMVECTOR^ Plane0, dmXMVECTOR^ Plane1, dmXMVECTOR^ Plane2, dmXMVECTOR^ Plane3, dmXMVECTOR^ Plane4, dmXMVECTOR^ Plane5)
		{
			XMVECTOR xV0;
			XMVECTOR xV1;
			XMVECTOR xV2;
			XMVECTOR xPlane0;
			XMVECTOR xPlane1;
			XMVECTOR xPlane2;
			XMVECTOR xPlane3;
			XMVECTOR xPlane4;
			XMVECTOR xPlane5;

			int thesize = Marshal::SizeOf(V0);
			IntPtr pnt = Marshal::AllocHGlobal(thesize);
			Marshal::StructureToPtr(V0, pnt, false);
			memcpy(&xV0, (void*)pnt, thesize);
			Marshal::StructureToPtr(V1, pnt, true);
			memcpy(&xV1, (void*)pnt, thesize);
			Marshal::StructureToPtr(V2, pnt, true);
			memcpy(&xV2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Plane0, pnt, true);
			memcpy(&xPlane0, (void*)pnt, thesize);
			Marshal::StructureToPtr(Plane1, pnt, true);
			memcpy(&xPlane1, (void*)pnt, thesize);
			Marshal::StructureToPtr(Plane2, pnt, true);
			memcpy(&xPlane2, (void*)pnt, thesize);
			Marshal::StructureToPtr(Plane3, pnt, true);
			memcpy(&xPlane3, (void*)pnt, thesize);
			Marshal::StructureToPtr(Plane4, pnt, true);
			memcpy(&xPlane4, (void*)pnt, thesize);
			Marshal::StructureToPtr(Plane5, pnt, true);
			memcpy(&xPlane5, (void*)pnt, thesize);
			Marshal::FreeHGlobal(pnt);
			return (ContainmentType)DDMath::TriangleTestsContainedBy(xV0, xV1, xV2, xPlane0, xPlane1, xPlane2, xPlane3, xPlane4, xPlane5);
		}
	};
};