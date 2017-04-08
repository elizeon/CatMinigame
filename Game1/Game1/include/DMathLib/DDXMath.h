#pragma once

#include <assert.h>
#include <stdint.h>
#include <BaseTsd.h>
#include <float.h>
#include <math.h>
#pragma warning(disable:4190 4201)

#ifndef XMGLOBALCONST
#define XMGLOBALCONST extern const __declspec(selectany)
#endif


namespace DDMath
{
#ifdef _WIN64
#define DXM_CALLCONV
#else
#define DXM_CALLCONV _cdecl
#endif

	//For static link remove comment on next line
	//#define STATIC_LINKING 1
#ifdef STATIC_LINKING
#define	DLL_IMPORT
#else
#define	DLL_IMPORT __declspec(dllimport)
#endif

	struct XMVECTOR
	{
		union
		{
			float       dmXMVECTOR_f32[4];
			uint32_t    dmXMVECTOR_u32[4];
			int32_t     dmXMVECTOR_i32[4];
		};
	};

	struct XMVECTORF32
	{
		union
		{
			float f[4];
			XMVECTOR v;
		};
	};

	struct XMVECTORU32
	{
		union
		{
			uint32_t u[4];
			XMVECTOR v;
		};
	};

	struct XMVECTORI32
	{
		union {
			int32_t i[4];
			XMVECTOR v;
		};
	};


	typedef const XMVECTOR& CXMVECTOR;
	typedef const XMVECTOR& FXMVECTOR;
	typedef const XMVECTOR& GXMVECTOR;
	typedef const XMVECTOR& HXMVECTOR;

	XMVECTOR    operator+ (FXMVECTOR V);
	XMVECTOR    operator- (FXMVECTOR V);

	XMVECTOR&   operator+= (XMVECTOR& V1, FXMVECTOR V2);
	XMVECTOR&   operator-= (XMVECTOR& V1, FXMVECTOR V2);
	XMVECTOR&   operator*= (XMVECTOR& V1, FXMVECTOR V2);
	XMVECTOR&   operator/= (XMVECTOR& V1, FXMVECTOR V2);

	XMVECTOR&   operator*= (XMVECTOR& V, float S);
	XMVECTOR&   operator/= (XMVECTOR& V, float S);

	XMVECTOR    operator+ (FXMVECTOR V1, FXMVECTOR V2);
	XMVECTOR    operator- (FXMVECTOR V1, FXMVECTOR V2);
	XMVECTOR    operator* (FXMVECTOR V1, FXMVECTOR V2);
	XMVECTOR    operator/ (FXMVECTOR V1, FXMVECTOR V2);
	XMVECTOR    operator* (FXMVECTOR V, float S);
	XMVECTOR    operator* (float S, FXMVECTOR V);
	XMVECTOR    operator/ (FXMVECTOR V, float S);

	typedef uint16_t HALF;
	struct XMMATRIX;
	typedef const XMMATRIX& FXMMATRIX;
	typedef const XMMATRIX& CXMMATRIX;

	struct XMMATRIX
	{
		union
		{
			XMVECTOR r[4];
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
		};
		XMMATRIX() {}

		XMMATRIX(FXMVECTOR R0, FXMVECTOR R1, FXMVECTOR R2, CXMVECTOR R3) { r[0] = R0; r[1] = R1; r[2] = R2; r[3] = R3; }
		XMMATRIX(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);
		explicit XMMATRIX(_In_reads_(16) const float *pArray);

		float       operator() (size_t Row, size_t Column) const { return m[Row][Column]; }
		float&      operator() (size_t Row, size_t Column) { return m[Row][Column]; }
		XMMATRIX&   operator= (const XMMATRIX& M) { r[0] = M.r[0]; r[1] = M.r[1]; r[2] = M.r[2]; r[3] = M.r[3]; return *this; }

		XMMATRIX    operator+ () const { return *this; }
		XMMATRIX    operator- () const;

		XMMATRIX&   operator+= (FXMMATRIX M);
		XMMATRIX&   operator-= (FXMMATRIX M);
		XMMATRIX&   operator*= (FXMMATRIX M);
		XMMATRIX&   operator*= (float S);
		XMMATRIX&   operator/= (float S);

		XMMATRIX    operator+ (FXMMATRIX M) const;
		XMMATRIX    operator- (FXMMATRIX M) const;
		XMMATRIX    operator* (FXMMATRIX M) const;
		XMMATRIX    operator* (float S) const;
		XMMATRIX    operator/ (float S) const;

		friend XMMATRIX  operator* (float S, FXMMATRIX M);
	};

	struct XMFLOAT4
	{
		float x;
		float y;
		float z;
		float w;
		XMFLOAT4() {}
		XMFLOAT4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; };
		explicit XMFLOAT4(_In_reads_(4) const float *pArray) {
			x = pArray[0]; y = pArray[1]; z = pArray[2]; w = pArray[3];
		};
		XMFLOAT4& operator= (const XMFLOAT4& Float4) { x = Float4.x; y = Float4.y; z = Float4.z; w = Float4.w; return *this; }
	};

	typedef XMFLOAT4 XMFLOAT4A;


	struct XMFLOAT2
	{
		float x;
		float y;
		XMFLOAT2() {}
		XMFLOAT2(float _x, float _y) {
			x = _x; y = _y;
		}
		explicit XMFLOAT2(_In_reads_(2) const float *pArray) { x = pArray[0]; y = pArray[1]; }
		XMFLOAT2& operator= (const XMFLOAT2& Float2) { x = Float2.x; y = Float2.y; return *this; }
	};

	typedef XMFLOAT2 XMFLOAT2A;

	struct XMFLOAT3
	{
		float x;
		float y;
		float z;
		XMFLOAT3() {}
		XMFLOAT3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; };
		explicit XMFLOAT3(_In_reads_(3) const float *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; };
		XMFLOAT3& operator= (const XMFLOAT3& Float3) { x = Float3.x; y = Float3.y; z = Float3.z; return *this; }
	};
	typedef XMFLOAT3 XMFLOAT3A;

	struct XMBYTE2
	{
		union
		{
			struct
			{
				int8_t x;
				int8_t y;
			};
			uint16_t v;
		};
		XMBYTE2() {}
		explicit XMBYTE2(uint16_t Packed) { v = Packed; }
		XMBYTE2(int8_t _x, int8_t _y) { x = _x; y = _y; }
		explicit XMBYTE2(_In_reads_(2) const int8_t *pArray) { x = pArray[0]; y = pArray[1]; }
		XMBYTE2(float _x, float _y);
		explicit XMBYTE2(_In_reads_(2) const float *pArray);
		XMBYTE2& operator= (const XMBYTE2& Byte2) { x = Byte2.x; y = Byte2.y; return *this; }
		XMBYTE2& operator= (uint16_t Packed) { v = Packed; return *this; }
	};

	struct XMBYTEN2
	{
		union
		{
			struct
			{
				int8_t x;
				int8_t y;
			};
			uint16_t v;
		};

		XMBYTEN2() {}
		explicit XMBYTEN2(uint16_t Packed) : v(Packed) {}
		XMBYTEN2(int8_t _x, int8_t _y) : x(_x), y(_y) {}
		explicit XMBYTEN2(_In_reads_(2) const int8_t *pArray) : x(pArray[0]), y(pArray[1]) {}
		XMBYTEN2(float _x, float _y);
		explicit XMBYTEN2(_In_reads_(2) const float *pArray);

		XMBYTEN2& operator= (const XMBYTEN2& ByteN2) { x = ByteN2.x; y = ByteN2.y; return *this; }
		XMBYTEN2& operator= (uint16_t Packed) { v = Packed; return *this; }
	};

	struct XMBYTE4
	{
		union
		{
			struct
			{
				int8_t x;
				int8_t y;
				int8_t z;
				int8_t w;
			};
			uint32_t v;
		};
		XMBYTE4() {}
		XMBYTE4(int8_t _x, int8_t _y, int8_t _z, int8_t _w) { x = _x; y = _y; z = _z; w = _w; }
		explicit XMBYTE4(uint32_t Packed) { v = Packed; }
		explicit XMBYTE4(_In_reads_(4) const int8_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; w = pArray[3]; }
		XMBYTE4(float _x, float _y, float _z, float _w);
		explicit XMBYTE4(_In_reads_(4) const float *pArray);
		XMBYTE4& operator= (const XMBYTE4& Byte4) { x = Byte4.x; y = Byte4.y; z = Byte4.z; w = Byte4.w; return *this; }
		XMBYTE4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMBYTEN4
	{
		union
		{
			struct
			{
				int8_t x;
				int8_t y;
				int8_t z;
				int8_t w;
			};
			uint32_t v;
		};

		XMBYTEN4() {}
		XMBYTEN4(int8_t _x, int8_t _y, int8_t _z, int8_t _w) : x(_x), y(_y), z(_z), w(_w) {}
		explicit XMBYTEN4(uint32_t Packed) : v(Packed) {}
		explicit XMBYTEN4(_In_reads_(4) const int8_t *pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
		XMBYTEN4(float _x, float _y, float _z, float _w);
		explicit XMBYTEN4(_In_reads_(4) const float *pArray);

		XMBYTEN4& operator= (const XMBYTEN4& ByteN4) { x = ByteN4.x; y = ByteN4.y; z = ByteN4.z; w = ByteN4.w; return *this; }
		XMBYTEN4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMCOLOR
	{
		union
		{
			struct
			{
				uint8_t b;  // Blue:    0/255 to 255/255
				uint8_t g;  // Green:   0/255 to 255/255
				uint8_t r;  // Red:     0/255 to 255/255
				uint8_t a;  // Alpha:   0/255 to 255/255
			};
			uint32_t c;
		};
		XMCOLOR() {}
		XMCOLOR(uint32_t Color) { c = Color; }
		XMCOLOR(float _r, float _g, float _b, float _a);
		explicit XMCOLOR(_In_reads_(4) const float *pArray);
		operator uint32_t () const { return c; }
		XMCOLOR& operator= (const XMCOLOR& Color) { c = Color.c; return *this; }
		XMCOLOR& operator= (const uint32_t Color) { c = Color; return *this; }
	};

	struct XMDEC4
	{
		union
		{
			struct
			{
				int32_t  x : 10;    // -511 to 511
				int32_t  y : 10;    // -511 to 511
				int32_t  z : 10;    // -511 to 511
				int32_t  w : 2;     //   -1 to   1
			};
			uint32_t v;
		};
		XMDEC4() {}
		explicit XMDEC4(uint32_t Packed) { v = Packed; }
		XMDEC4(float _x, float _y, float _z, float _w);
		explicit XMDEC4(_In_reads_(4) const float *pArray);
		operator uint32_t () const { return v; }
		XMDEC4& operator= (const XMDEC4& Dec4) { v = Dec4.v; return *this; }
		XMDEC4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMDECN4
	{
		union
		{
			struct
			{
				int32_t x : 10;    // -511/511 to 511/511
				int32_t y : 10;    // -511/511 to 511/511
				int32_t z : 10;    // -511/511 to 511/511
				int32_t w : 2;     //     -1/1 to     1/1
			};
			uint32_t v;
		};

		XMDECN4() {}
		explicit XMDECN4(uint32_t Packed) : v(Packed) {}
		XMDECN4(float _x, float _y, float _z, float _w);
		explicit XMDECN4(_In_reads_(4) const float *pArray);

		operator uint32_t () const { return v; }

		XMDECN4& operator= (const XMDECN4& DecN4) { v = DecN4.v; return *this; }
		XMDECN4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMUDECN4
	{
		union
		{
			struct
			{
				uint32_t x : 10;    // 0/1023 to 1023/1023
				uint32_t y : 10;    // 0/1023 to 1023/1023
				uint32_t z : 10;    // 0/1023 to 1023/1023
				uint32_t w : 2;     //    0/3 to       3/3
			};
			uint32_t v;
		};

		XMUDECN4() {}
		explicit XMUDECN4(uint32_t Packed) : v(Packed) {}
		XMUDECN4(float _x, float _y, float _z, float _w);
		explicit XMUDECN4(_In_reads_(4) const float *pArray);

		operator uint32_t () const { return v; }

		XMUDECN4& operator= (const XMUDECN4& UDecN4) { v = UDecN4.v; return *this; }
		XMUDECN4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMFLOAT3PK
	{
		union
		{
			struct
			{
				uint32_t xm : 6; // x-mantissa
				uint32_t xe : 5; // x-exponent
				uint32_t ym : 6; // y-mantissa
				uint32_t ye : 5; // y-exponent
				uint32_t zm : 5; // z-mantissa
				uint32_t ze : 5; // z-exponent
			};
			uint32_t v;
		};
		XMFLOAT3PK() {}
		explicit XMFLOAT3PK(uint32_t Packed) { v = Packed; }
		XMFLOAT3PK(float _x, float _y, float _z);
		explicit XMFLOAT3PK(_In_reads_(3) const float *pArray);
		operator uint32_t () const { return v; }
		XMFLOAT3PK& operator= (const XMFLOAT3PK& float3pk) { v = float3pk.v; return *this; }
		XMFLOAT3PK& operator= (uint32_t Packed) { v = Packed; return *this; }
	};
	struct XMFLOAT3SE
	{
		union
		{
			struct
			{
				uint32_t xm : 9; // x-mantissa
				uint32_t ym : 9; // y-mantissa
				uint32_t zm : 9; // z-mantissa
				uint32_t e : 5; // shared exponent
			};
			uint32_t v;
		};
		XMFLOAT3SE() {}
		explicit XMFLOAT3SE(uint32_t Packed) { v = Packed; }
		XMFLOAT3SE(float _x, float _y, float _z);
		explicit XMFLOAT3SE(_In_reads_(3) const float *pArray);
		operator uint32_t () const { return v; }
		XMFLOAT3SE& operator= (const XMFLOAT3SE& float3se) { v = float3se.v; return *this; }
		XMFLOAT3SE& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMFLOAT3X3
	{
		union
		{
			struct
			{
				float _11, _12, _13;
				float _21, _22, _23;
				float _31, _32, _33;
			};
			float m[3][3];
		};
		XMFLOAT3X3() {}
		XMFLOAT3X3(float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22);
		explicit XMFLOAT3X3(_In_reads_(9) const float *pArray);
		float       operator() (size_t Row, size_t Column) const { return m[Row][Column]; }
		float&      operator() (size_t Row, size_t Column) { return m[Row][Column]; }
		XMFLOAT3X3& operator= (const XMFLOAT3X3& Float3x3);
	};

	struct XMFLOAT4X3
	{
		union
		{
			struct
			{
				float _11, _12, _13;
				float _21, _22, _23;
				float _31, _32, _33;
				float _41, _42, _43;
			};
			float m[4][3];
		};
		XMFLOAT4X3() {}
		XMFLOAT4X3(float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22,
			float m30, float m31, float m32);
		explicit XMFLOAT4X3(_In_reads_(12) const float *pArray);
		float       operator() (size_t Row, size_t Column) const { return m[Row][Column]; }
		float&      operator() (size_t Row, size_t Column) { return m[Row][Column]; }
		XMFLOAT4X3& operator= (const XMFLOAT4X3& Float4x3);
	};

	typedef XMFLOAT4X3 XMFLOAT4X3A;

	struct XMFLOAT4X4
	{
		union
		{
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
		};
		XMFLOAT4X4() {}
		XMFLOAT4X4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);
		explicit XMFLOAT4X4(_In_reads_(16) const float *pArray);
		float       operator() (size_t Row, size_t Column) const { return m[Row][Column]; }
		float&      operator() (size_t Row, size_t Column) { return m[Row][Column]; }
		XMFLOAT4X4& operator= (const XMFLOAT4X4& Float4x4);
	};
	typedef XMFLOAT4X4 XMFLOAT4X4A;

	struct XMHALF2
	{
		union
		{
			struct
			{
				HALF x;
				HALF y;
			};
			uint32_t v;
		};
		XMHALF2() {}
		explicit XMHALF2(uint32_t Packed) { v = Packed; }
		XMHALF2(HALF _x, HALF _y) { x = _x; y = _y; }
		explicit XMHALF2(_In_reads_(2) const HALF *pArray) { x = pArray[0]; y = pArray[1]; }
		XMHALF2(float _x, float _y);
		explicit XMHALF2(_In_reads_(2) const float *pArray);
		XMHALF2& operator= (const XMHALF2& Half2) { x = Half2.x; y = Half2.y; return *this; }
		XMHALF2& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMHALF4
	{
		union
		{
			struct
			{
				HALF x;
				HALF y;
				HALF z;
				HALF w;
			};
			uint64_t v;
		};
		XMHALF4() {}
		explicit XMHALF4(uint64_t Packed) { v = Packed; }
		XMHALF4(HALF _x, HALF _y, HALF _z, HALF _w) { x = _x; y = _y; z = _z; w = _w; }
		explicit XMHALF4(_In_reads_(4) const HALF *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; w = pArray[3]; }
		XMHALF4(float _x, float _y, float _z, float _w);
		explicit XMHALF4(_In_reads_(4) const float *pArray);
		XMHALF4& operator= (const XMHALF4& Half4) { x = Half4.x; y = Half4.y; z = Half4.z; w = Half4.w; return *this; }
		XMHALF4& operator= (uint64_t Packed) { v = Packed; return *this; }

	};

	struct XMSHORT2
	{
		union
		{
			struct
			{
				int16_t x;
				int16_t y;
			};
			uint32_t v;
		};
		XMSHORT2() {}
		explicit XMSHORT2(uint32_t Packed) { v = Packed; }
		XMSHORT2(int16_t _x, int16_t _y) { x = _x; y = _y; }
		explicit XMSHORT2(_In_reads_(2) const int16_t *pArray) { x = pArray[0]; y = pArray[1]; }
		XMSHORT2(float _x, float _y);
		explicit XMSHORT2(_In_reads_(2) const float *pArray);
		XMSHORT2& operator= (const XMSHORT2& Short2) { x = Short2.x; y = Short2.y; return *this; }
		XMSHORT2& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMSHORTN2
	{
		union
		{
			struct
			{
				int16_t x;
				int16_t y;
			};
			uint32_t v;
		};

		XMSHORTN2() {}
		explicit XMSHORTN2(uint32_t Packed) : v(Packed) {}
		XMSHORTN2(int16_t _x, int16_t _y) : x(_x), y(_y) {}
		explicit XMSHORTN2(_In_reads_(2) const int16_t *pArray) : x(pArray[0]), y(pArray[1]) {}
		XMSHORTN2(float _x, float _y);
		explicit XMSHORTN2(_In_reads_(2) const float *pArray);

		XMSHORTN2& operator= (const XMSHORTN2& ShortN2) { x = ShortN2.x; y = ShortN2.y; return *this; }
		XMSHORTN2& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMSHORT4
	{
		union
		{
			struct
			{
				int16_t x;
				int16_t y;
				int16_t z;
				int16_t w;
			};
			uint64_t v;
		};
		XMSHORT4() {}
		explicit XMSHORT4(uint64_t Packed) { v = Packed; }
		XMSHORT4(int16_t _x, int16_t _y, int16_t _z, int16_t _w) { x = _x; y = _y; z = _z; w = _w; }
		explicit XMSHORT4(_In_reads_(4) const int16_t *pArray) { x = pArray[0]; y = pArray[1];z = pArray[2]; w = pArray[3]; }
		XMSHORT4(float _x, float _y, float _z, float _w);
		explicit XMSHORT4(_In_reads_(4) const float *pArray);
		XMSHORT4& operator= (const XMSHORT4& Short4) { x = Short4.x; y = Short4.y; z = Short4.z; w = Short4.w; return *this; }
		XMSHORT4& operator= (uint64_t Packed) { v = Packed; return *this; }
	};

	struct XMSHORTN4
	{
		union
		{
			struct
			{
				int16_t x;
				int16_t y;
				int16_t z;
				int16_t w;
			};
			uint64_t v;
		};

		XMSHORTN4() {}
		explicit XMSHORTN4(uint64_t Packed) : v(Packed) {}
		XMSHORTN4(int16_t _x, int16_t _y, int16_t _z, int16_t _w) : x(_x), y(_y), z(_z), w(_w) {}
		explicit XMSHORTN4(_In_reads_(4) const int16_t *pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
		XMSHORTN4(float _x, float _y, float _z, float _w);
		explicit XMSHORTN4(_In_reads_(4) const float *pArray);

		XMSHORTN4& operator= (const XMSHORTN4& ShortN4) { x = ShortN4.x; y = ShortN4.y; z = ShortN4.z; w = ShortN4.w; return *this; }
		XMSHORTN4& operator= (uint64_t Packed) { v = Packed; return *this; }
	};

	struct XMINT2
	{
		int32_t x;
		int32_t y;
		XMINT2() {}
		XMINT2(int32_t _x, int32_t _y) { x = _x; y = _y; }
		explicit XMINT2(_In_reads_(2) const int32_t *pArray) { x = pArray[0]; y = pArray[1]; }
		XMINT2& operator= (const XMINT2& Int2) { x = Int2.x; y = Int2.y; return *this; }
	};

	struct XMINT3
	{
		int32_t x;
		int32_t y;
		int32_t z;
		XMINT3() {}
		XMINT3(int32_t _x, int32_t _y, int32_t _z) { x = _x; y = _y; z = _z; }
		explicit XMINT3(_In_reads_(3) const int32_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; }
		XMINT3& operator= (const XMINT3& i3) { x = i3.x; y = i3.y; z = i3.z; return *this; }
	};

	struct XMINT4
	{
		int32_t x;
		int32_t y;
		int32_t z;
		int32_t w;
		XMINT4() {}
		XMINT4(int32_t _x, int32_t _y, int32_t _z, int32_t _w) { x = _x; y = _y; z = _z; w = _w; }
		explicit XMINT4(_In_reads_(4) const int32_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; w = pArray[3]; }
		XMINT4& operator= (const XMINT4& Int4) { x = Int4.x; y = Int4.y; z = Int4.z; w = Int4.w; return *this; }
	};

	struct XMU555
	{
		union
		{
			struct
			{
				uint16_t x : 5;    // 0 to 31
				uint16_t y : 5;    // 0 to 31
				uint16_t z : 5;    // 0 to 31
				uint16_t w : 1;    // 0 or 1
			};
			uint16_t v;
		};
		XMU555() {}
		explicit XMU555(uint16_t Packed) { v = Packed; }
		XMU555(int8_t _x, int8_t _y, int8_t _z, bool _w) {
			x = _x; y = _y; z = _z; w = (_w ? 0x1 : 0);
		}
		XMU555(_In_reads_(3) const int8_t *pArray, _In_ bool _w) {
			x = pArray[0]; y = pArray[1]; z = pArray[2]; w = (_w ? 0x1 : 0);
		}
		XMU555(float _x, float _y, float _z, bool _w);
		XMU555(_In_reads_(3) const float *pArray, _In_ bool _w);
		operator uint16_t () const { return v; }
		XMU555& operator= (const XMU555& U555) { v = U555.v; return *this; }
		XMU555& operator= (uint16_t Packed) { v = Packed; return *this; }
	};

	struct XMU565
	{
		union
		{
			struct
			{
				uint16_t x : 5;    // 0 to 31
				uint16_t y : 6;    // 0 to 63
				uint16_t z : 5;    // 0 to 31
			};
			uint16_t v;
		};
		XMU565() {}
		explicit XMU565(uint16_t Packed) { v = Packed; }
		XMU565(uint8_t _x, uint8_t _y, uint8_t _z) { x = _x; y = _y; z = _z; }
		explicit XMU565(_In_reads_(3) const int8_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; }
		XMU565(float _x, float _y, float _z);
		explicit XMU565(_In_reads_(3) const float *pArray);
		operator uint16_t () const { return v; }
		XMU565& operator= (const XMU565& U565) { v = U565.v; return *this; }
		XMU565& operator= (uint16_t Packed) { v = Packed; return *this; }
	};

	struct XMUBYTE2
	{
		union
		{
			struct
			{
				uint8_t x;
				uint8_t y;
			};
			uint16_t v;
		};
		XMUBYTE2() {}
		explicit XMUBYTE2(uint16_t Packed) { v = Packed; }
		XMUBYTE2(uint8_t _x, uint8_t _y) { x = _x; y = _y; }
		explicit XMUBYTE2(_In_reads_(2) const uint8_t *pArray) { x = pArray[0]; y = pArray[1]; }
		XMUBYTE2(float _x, float _y);
		explicit XMUBYTE2(_In_reads_(2) const float *pArray);
		XMUBYTE2& operator= (const XMUBYTE2& UByte2) { x = UByte2.x; y = UByte2.y; return *this; }
		XMUBYTE2& operator= (uint16_t Packed) { v = Packed; return *this; }
	};

	struct XMUBYTEN2
	{
		union
		{
			struct
			{
				uint8_t x;
				uint8_t y;
			};
			uint16_t v;
		};

		XMUBYTEN2() {}
		explicit XMUBYTEN2(uint16_t Packed) : v(Packed) {}
		XMUBYTEN2(uint8_t _x, uint8_t _y) : x(_x), y(_y) {}
		explicit XMUBYTEN2(_In_reads_(2) const uint8_t *pArray) : x(pArray[0]), y(pArray[1]) {}
		XMUBYTEN2(float _x, float _y);
		explicit XMUBYTEN2(_In_reads_(2) const float *pArray);

		XMUBYTEN2& operator= (const XMUBYTEN2& UByteN2) { x = UByteN2.x; y = UByteN2.y; return *this; }
		XMUBYTEN2& operator= (uint16_t Packed) { v = Packed; return *this; }
	};

	struct XMUBYTE4
	{
		union
		{
			struct
			{
				uint8_t x;
				uint8_t y;
				uint8_t z;
				uint8_t w;
			};
			uint32_t v;
		};
		XMUBYTE4() {}
		XMUBYTE4(uint8_t _x, uint8_t _y, uint8_t _z, uint8_t _w) { x = _x; y = _y; z = _z; w = _w; }
		explicit XMUBYTE4(uint32_t Packed) { v = Packed; }
		explicit XMUBYTE4(_In_reads_(4) const uint8_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; w = pArray[3]; }
		XMUBYTE4(float _x, float _y, float _z, float _w);
		explicit XMUBYTE4(_In_reads_(4) const float *pArray);
		XMUBYTE4& operator= (const XMUBYTE4& UByte4) { x = UByte4.x; y = UByte4.y; z = UByte4.z; w = UByte4.w; return *this; }
		XMUBYTE4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMUBYTEN4
	{
		union
		{
			struct
			{
				uint8_t x;
				uint8_t y;
				uint8_t z;
				uint8_t w;
			};
			uint32_t v;
		};

		XMUBYTEN4() {}
		XMUBYTEN4(uint8_t _x, uint8_t _y, uint8_t _z, uint8_t _w) : x(_x), y(_y), z(_z), w(_w) {}
		explicit XMUBYTEN4(uint32_t Packed) : v(Packed) {}
		explicit XMUBYTEN4(_In_reads_(4) const uint8_t *pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
		XMUBYTEN4(float _x, float _y, float _z, float _w);
		explicit XMUBYTEN4(_In_reads_(4) const float *pArray);

		XMUBYTEN4& operator= (const XMUBYTEN4& UByteN4) { x = UByteN4.x; y = UByteN4.y; z = UByteN4.z; w = UByteN4.w; return *this; }
		XMUBYTEN4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};


	struct XMUDEC4
	{
		union
		{
			struct
			{
				uint32_t x : 10;    // 0 to 1023
				uint32_t y : 10;    // 0 to 1023
				uint32_t z : 10;    // 0 to 1023
				uint32_t w : 2;     // 0 to    3
			};
			uint32_t v;
		};
		XMUDEC4() {}
		explicit XMUDEC4(uint32_t Packed) { v = Packed; }
		XMUDEC4(float _x, float _y, float _z, float _w);
		explicit XMUDEC4(_In_reads_(4) const float *pArray);
		operator uint32_t () const { return v; }
		XMUDEC4& operator= (const XMUDEC4& UDec4) { v = UDec4.v; return *this; }
		XMUDEC4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMUINT2
	{
		uint32_t x;
		uint32_t y;
		XMUINT2() {}
		XMUINT2(uint32_t _x, uint32_t _y) { x = _x; y = _y; }
		explicit XMUINT2(_In_reads_(2) const uint32_t *pArray) { x = pArray[0]; y = pArray[1]; }
		XMUINT2& operator= (const XMUINT2& UInt2) { x = UInt2.x; y = UInt2.y; return *this; }
	};

	struct XMUINT3
	{
		uint32_t x;
		uint32_t y;
		uint32_t z;

		XMUINT3() {}
		XMUINT3(uint32_t _x, uint32_t _y, uint32_t _z) { x = _x; y = _y; z = _z; }
		explicit XMUINT3(_In_reads_(3) const uint32_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; }
		XMUINT3& operator= (const XMUINT3& u3) { x = u3.x; y = u3.y; z = u3.z; return *this; }
	};


	struct XMUINT4
	{
		uint32_t x;
		uint32_t y;
		uint32_t z;
		uint32_t w;

		XMUINT4() {}
		XMUINT4(uint32_t _x, uint32_t _y, uint32_t _z, uint32_t _w) { x = _x; y = _y; z = _z; w = _w; }
		explicit XMUINT4(_In_reads_(4) const uint32_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; w = pArray[3]; }
		XMUINT4& operator= (const XMUINT4& UInt4) { x = UInt4.x; y = UInt4.y; z = UInt4.z; w = UInt4.w; return *this; }
	};

	struct XMUNIBBLE4
	{
		union
		{
			struct
			{
				uint16_t x : 4;    // 0 to 15
				uint16_t y : 4;    // 0 to 15
				uint16_t z : 4;    // 0 to 15
				uint16_t w : 4;    // 0 to 15
			};
			uint16_t v;
		};
		XMUNIBBLE4() {}
		explicit XMUNIBBLE4(uint16_t Packed) { v = Packed; }
		XMUNIBBLE4(int8_t _x, int8_t _y, int8_t _z, int8_t _w) { x = _x; y = _y; z = _z; w = _w; }
		explicit XMUNIBBLE4(_In_reads_(4) const int8_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; w = pArray[3]; }
		XMUNIBBLE4(float _x, float _y, float _z, float _w);
		explicit XMUNIBBLE4(_In_reads_(4) const float *pArray);
		operator uint16_t () const { return v; }
		XMUNIBBLE4& operator= (const XMUNIBBLE4& UNibble4) { v = UNibble4.v; return *this; }
		XMUNIBBLE4& operator= (uint16_t Packed) { v = Packed; return *this; }
	};

	struct XMUSHORT2
	{
		union
		{
			struct
			{
				uint16_t x;
				uint16_t y;
			};
			uint32_t v;
		};
		XMUSHORT2() {}
		explicit XMUSHORT2(uint32_t Packed) { v = Packed; }
		XMUSHORT2(uint16_t _x, uint16_t _y) { x = _x; y = _y; }
		explicit XMUSHORT2(_In_reads_(2) const uint16_t *pArray) { x = pArray[0]; y = pArray[1]; }
		XMUSHORT2(float _x, float _y);
		explicit XMUSHORT2(_In_reads_(2) const float *pArray);
		XMUSHORT2& operator= (const XMUSHORT2& UShort2) { x = UShort2.x; y = UShort2.y; return *this; }
		XMUSHORT2& operator= (uint32_t Packed) { v = Packed; return *this; }

	};

	struct XMUSHORTN2
	{
		union
		{
			struct
			{
				uint16_t x;
				uint16_t y;
			};
			uint32_t v;
		};

		XMUSHORTN2() {}
		explicit XMUSHORTN2(uint32_t Packed) : v(Packed) {}
		XMUSHORTN2(uint16_t _x, uint16_t _y) : x(_x), y(_y) {}
		explicit XMUSHORTN2(_In_reads_(2) const uint16_t *pArray) : x(pArray[0]), y(pArray[1]) {}
		XMUSHORTN2(float _x, float _y);
		explicit XMUSHORTN2(_In_reads_(2) const float *pArray);

		XMUSHORTN2& operator= (const XMUSHORTN2& UShortN2) { x = UShortN2.x; y = UShortN2.y; return *this; }
		XMUSHORTN2& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMUSHORT4
	{
		union
		{
			struct
			{
				uint16_t x;
				uint16_t y;
				uint16_t z;
				uint16_t w;
			};
			uint64_t v;
		};
		XMUSHORT4() {}
		explicit XMUSHORT4(uint64_t Packed) { v = Packed; }
		XMUSHORT4(uint16_t _x, uint16_t _y, uint16_t _z, uint16_t _w) { x = _x; y = _y; z = _z; w = _w; }
		explicit XMUSHORT4(_In_reads_(4) const uint16_t *pArray) { x = pArray[0]; y = pArray[1]; z = pArray[2]; w = pArray[3]; }
		XMUSHORT4(float _x, float _y, float _z, float _w);
		explicit XMUSHORT4(_In_reads_(4) const float *pArray);
		XMUSHORT4& operator= (const XMUSHORT4& UShort4) { x = UShort4.x; y = UShort4.y; z = UShort4.z; w = UShort4.w; return *this; }
		XMUSHORT4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMUSHORTN4
	{
		union
		{
			struct
			{
				uint16_t x;
				uint16_t y;
				uint16_t z;
				uint16_t w;
			};
			uint64_t v;
		};

		XMUSHORTN4() {}
		explicit XMUSHORTN4(uint64_t Packed) : v(Packed) {}
		XMUSHORTN4(uint16_t _x, uint16_t _y, uint16_t _z, uint16_t _w) : x(_x), y(_y), z(_z), w(_w) {}
		explicit XMUSHORTN4(_In_reads_(4) const uint16_t *pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
		XMUSHORTN4(float _x, float _y, float _z, float _w);
		explicit XMUSHORTN4(_In_reads_(4) const float *pArray);

		XMUSHORTN4& operator= (const XMUSHORTN4& UShortN4) { x = UShortN4.x; y = UShortN4.y; z = UShortN4.z; w = UShortN4.w; return *this; }
		XMUSHORTN4& operator= (uint64_t Packed) { v = Packed; return *this; }
	};

	struct XMXDEC4
	{
		union
		{
			struct
			{
				int32_t x : 10;    // -511 to 511
				int32_t y : 10;    // -511 to 511
				int32_t z : 10;    // -511 to 511
				uint32_t w : 2;     // 0 to 3
			};
			uint32_t v;
		};
		XMXDEC4() {}
		explicit XMXDEC4(uint32_t Packed) { v = Packed; }
		XMXDEC4(float _x, float _y, float _z, float _w);
		explicit XMXDEC4(_In_reads_(4) const float *pArray);
		operator uint32_t () const { return v; }
		XMXDEC4& operator= (const XMXDEC4& XDec4) { v = XDec4.v; return *this; }
		XMXDEC4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};

	struct XMXDECN4
	{
		union
		{
			struct
			{
				int32_t x : 10;    // -511/511 to 511/511
				int32_t y : 10;    // -511/511 to 511/511
				int32_t z : 10;    // -511/511 to 511/511
				uint32_t w : 2;     //      0/3 to     3/3
			};
			uint32_t v;
		};

		XMXDECN4() {}
		explicit XMXDECN4(uint32_t Packed) : v(Packed) {}
		XMXDECN4(float _x, float _y, float _z, float _w);
		explicit XMXDECN4(_In_reads_(4) const float *pArray);

		operator uint32_t () const { return v; }

		XMXDECN4& operator= (const XMXDECN4& XDecN4) { v = XDecN4.v; return *this; }
		XMXDECN4& operator= (uint32_t Packed) { v = Packed; return *this; }
	};


	extern "C"
	{

		// Color Functions - 27 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorSRGBToRGB(FXMVECTOR srgb);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorRGBToSRGB(FXMVECTOR rgb);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorAdjustContrast(FXMVECTOR vColor, float fContrast);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorAdjustSaturation(FXMVECTOR vColor, float fSaturation);
		DLL_IMPORT bool DXM_CALLCONV XMColorEqual(FXMVECTOR C1, FXMVECTOR C2);
		DLL_IMPORT bool DXM_CALLCONV XMColorGreater(FXMVECTOR C1, FXMVECTOR C2);
		DLL_IMPORT bool DXM_CALLCONV XMColorGreaterOrEqual(FXMVECTOR C1, FXMVECTOR C2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorHue2Clr(FXMVECTOR p, FXMVECTOR q, FXMVECTOR h);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorHSLToRGB(FXMVECTOR hsl);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorHSVToRGB(FXMVECTOR hsv);
		DLL_IMPORT bool DXM_CALLCONV XMColorIsInfinite(FXMVECTOR C);
		DLL_IMPORT bool DXM_CALLCONV XMColorIsNaN(FXMVECTOR C);
		DLL_IMPORT bool DXM_CALLCONV XMColorLess(FXMVECTOR C1, FXMVECTOR C2);
		DLL_IMPORT bool DXM_CALLCONV XMColorLessOrEqual(FXMVECTOR C1, FXMVECTOR C2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorModulate(FXMVECTOR C1, FXMVECTOR C2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMColorNegative(FXMVECTOR C);
		DLL_IMPORT bool DXM_CALLCONV XMColorNotEqual(FXMVECTOR C1, FXMVECTOR C2);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorRGBToHSL(FXMVECTOR rgb);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorRGBToHSV(FXMVECTOR rgb);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorRGBToXYZ(FXMVECTOR rgb);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorRGBToYUV(FXMVECTOR rgb);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorRGBToYUV_HD(FXMVECTOR rgb);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorSRGBToXYZ(FXMVECTOR srgb);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorXYZToRGB(FXMVECTOR xyz);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorXYZToSRGB(FXMVECTOR xyz);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorYUVToRGB(FXMVECTOR xyz);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMColorYUVToRGB_HD(FXMVECTOR xyz);

		// Conversion Functions - 10 function
		DLL_IMPORT HALF  DXM_CALLCONV XMConvertFloatToHalf(float Value);
		DLL_IMPORT HALF* DXM_CALLCONV XMConvertFloatToHalfStream(_Out_writes_bytes_(sizeof(HALF) + OutputStride*(FloatCount - 1)) HALF* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(float) + InputStride*(FloatCount - 1)) const float* pInputStream,
			_In_ size_t InputStride, _In_ size_t FloatCount);
		DLL_IMPORT float DXM_CALLCONV XMConvertHalfToFloat(HALF Value);
		DLL_IMPORT float* DXM_CALLCONV XMConvertHalfToFloatStream(_Out_writes_bytes_(sizeof(float) + OutputStride*(HalfCount - 1)) float* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(HALF) + InputStride*(HalfCount - 1)) const HALF* pInputStream,
			_In_ size_t InputStride, _In_ size_t HalfCount);
		DLL_IMPORT float XMConvertToDegrees(float fRadians);
		DLL_IMPORT float XMConvertToRadians(float fDegrees);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMConvertVectorFloatToInt(FXMVECTOR VFloat, uint32_t MulExponent);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMConvertVectorFloatToUInt(FXMVECTOR VFloat, uint32_t MulExponent);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMConvertVectorIntToFloat(FXMVECTOR VInt, uint32_t DivExponent);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMConvertVectorUIntToFloat(FXMVECTOR VUInt, uint32_t DivExponent);

		// Matrix Functions  - 43 functions
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixAffineTransformation(FXMVECTOR Scaling, FXMVECTOR RotationOrigin, FXMVECTOR RotationQuaternion, GXMVECTOR Translation);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixAffineTransformation2D(FXMVECTOR Scaling, FXMVECTOR RotationOrigin, float Rotation, FXMVECTOR Translation);
		DLL_IMPORT bool DXM_CALLCONV XMMatrixDecompose(_Out_ XMVECTOR *outScale, _Out_ XMVECTOR *outRotQuat, _Out_ XMVECTOR *outTrans, _In_ FXMMATRIX M);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMMatrixDeterminant(FXMMATRIX M);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixIdentity();
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixInverse(_Out_opt_ XMVECTOR* pDeterminant, _In_ FXMMATRIX M);
		DLL_IMPORT bool DXM_CALLCONV XMMatrixIsIdentity(FXMMATRIX M);
		DLL_IMPORT bool DXM_CALLCONV XMMatrixIsInfinite(FXMMATRIX M);
		DLL_IMPORT bool DXM_CALLCONV XMMatrixIsNaN(FXMMATRIX M);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixLookAtLH(FXMVECTOR EyePosition, FXMVECTOR FocusPosition, FXMVECTOR UpDirection);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixLookAtRH(FXMVECTOR EyePosition, FXMVECTOR FocusPosition, FXMVECTOR UpDirection);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixLookToLH(FXMVECTOR EyePosition, FXMVECTOR EyeDirection, FXMVECTOR UpDirection);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixLookToRH(FXMVECTOR EyePosition, FXMVECTOR EyeDirection, FXMVECTOR UpDirection);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixMultiply(FXMMATRIX M1, CXMMATRIX M2);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixMultiplyTranspose(FXMMATRIX M1, CXMMATRIX M2);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixOrthographicLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixOrthographicOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixOrthographicOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixOrthographicRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixPerspectiveFovLH(float FovAngleY, float AspectHByW, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixPerspectiveFovRH(float FovAngleY, float AspectHByW, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixPerspectiveLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixPerspectiveOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixPerspectiveOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixPerspectiveRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixReflect(FXMVECTOR ReflectionPlane);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixRotationAxis(FXMVECTOR Axis, float Angle);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixRotationNormal(FXMVECTOR NormalAxis, float Angle);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixRotationQuaternion(FXMVECTOR Quaternion);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixRotationRollPitchYaw(float Pitch, float Yaw, float Roll);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixRotationRollPitchYawFromVector(FXMVECTOR Angles);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixRotationX(float Angle);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixRotationY(float Angle);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixRotationZ(float Angle);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixScaling(float ScaleX, float ScaleY, float ScaleZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixScalingFromVector(FXMVECTOR Scale);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixSet(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixShadow(FXMVECTOR ShadowPlane, FXMVECTOR LightPosition);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixTransformation(FXMVECTOR ScalingOrigin, FXMVECTOR ScalingOrientationQuaternion, FXMVECTOR Scaling,
			GXMVECTOR RotationOrigin, HXMVECTOR RotationQuaternion, HXMVECTOR Translation);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixTransformation2D(FXMVECTOR ScalingOrigin, float ScalingOrientation, FXMVECTOR Scaling,
			FXMVECTOR RotationOrigin, float Rotation, GXMVECTOR Translation);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixTranslation(float OffsetX, float OffsetY, float OffsetZ);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixTranslationFromVector(FXMVECTOR Offset);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMMatrixTranspose(FXMMATRIX M);

		// Plane Functions - 16 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneDot(FXMVECTOR P, FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneDotCoord(FXMVECTOR P, FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneDotNormal(FXMVECTOR P, FXMVECTOR V);
		DLL_IMPORT bool DXM_CALLCONV XMPlaneEqual(FXMVECTOR P1, FXMVECTOR P2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneFromPointNormal(FXMVECTOR Point, FXMVECTOR Normal);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneFromPoints(FXMVECTOR Point1, FXMVECTOR Point2, FXMVECTOR Point3);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneIntersectLine(FXMVECTOR P, FXMVECTOR LinePoint1, FXMVECTOR LinePoint2);
		DLL_IMPORT void DXM_CALLCONV XMPlaneIntersectPlane(_Out_ XMVECTOR* pLinePoint1, _Out_ XMVECTOR* pLinePoint2, _In_ FXMVECTOR P1, _In_ FXMVECTOR P2);
		DLL_IMPORT bool DXM_CALLCONV XMPlaneIsInfinite(FXMVECTOR P);
		DLL_IMPORT bool DXM_CALLCONV XMPlaneIsNaN(FXMVECTOR P);
		DLL_IMPORT bool DXM_CALLCONV XMPlaneNearEqual(FXMVECTOR P1, FXMVECTOR P2, FXMVECTOR Epsilon);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneNormalize(FXMVECTOR P);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneNormalizeEst(FXMVECTOR P);
		DLL_IMPORT bool DXM_CALLCONV XMPlaneNotEqual(FXMVECTOR P1, FXMVECTOR P2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMPlaneTransform(FXMVECTOR P, FXMMATRIX M);
		DLL_IMPORT XMFLOAT4* DXM_CALLCONV XMPlaneTransformStream(_Out_writes_bytes_(sizeof(XMFLOAT4) + OutputStride*(PlaneCount - 1)) XMFLOAT4* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT4) + InputStride*(PlaneCount - 1)) const XMFLOAT4* pInputStream,
			_In_ size_t InputStride, _In_ size_t PlaneCount, _In_ FXMMATRIX M);

		// Quaternion Functions - 30 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionBaryCentric(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, float f, float g);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionBaryCentricV(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, GXMVECTOR F, HXMVECTOR G);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionConjugate(FXMVECTOR Q);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionDot(FXMVECTOR Q1, FXMVECTOR Q2);
		DLL_IMPORT bool DXM_CALLCONV XMQuaternionEqual(FXMVECTOR Q1, FXMVECTOR Q2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionExp(FXMVECTOR Q);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionIdentity();
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionInverse(FXMVECTOR Q);
		DLL_IMPORT bool DXM_CALLCONV XMQuaternionIsIdentity(FXMVECTOR Q);
		DLL_IMPORT bool DXM_CALLCONV XMQuaternionIsInfinite(FXMVECTOR Q);
		DLL_IMPORT bool DXM_CALLCONV XMQuaternionIsNaN(FXMVECTOR Q);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionLength(FXMVECTOR Q);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionLengthSq(FXMVECTOR Q);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionLn(FXMVECTOR Q);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionMultiply(FXMVECTOR Q1, FXMVECTOR Q2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionNormalize(FXMVECTOR Q);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionNormalizeEst(FXMVECTOR Q);
		DLL_IMPORT bool DXM_CALLCONV XMQuaternionNotEqual(FXMVECTOR Q1, FXMVECTOR Q2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionReciprocalLength(FXMVECTOR Q);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionRotationAxis(FXMVECTOR Axis, float Angle);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionRotationMatrix(FXMMATRIX M);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionRotationNormal(FXMVECTOR NormalAxis, float Angle);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionRotationRollPitchYaw(float Pitch, float Yaw, float Roll);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionRotationRollPitchYawFromVector(FXMVECTOR Angles);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionSlerp(FXMVECTOR Q0, FXMVECTOR Q1, float t);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionSlerpV(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR T);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionSquad(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, GXMVECTOR Q3, float t);
		DLL_IMPORT void  DXM_CALLCONV XMQuaternionSquadSetup(_Out_ XMVECTOR* pA, _Out_ XMVECTOR* pB, _Out_ XMVECTOR* pC, _In_ FXMVECTOR Q0, _In_ FXMVECTOR Q1, _In_ FXMVECTOR Q2, _In_ GXMVECTOR Q3);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMQuaternionSquadV(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, GXMVECTOR Q3, HXMVECTOR T);
		DLL_IMPORT void DXM_CALLCONV XMQuaternionToAxisAngle(_Out_ XMVECTOR* pAxis, _Out_ float* pAngle, _In_ FXMVECTOR Q);

		// Scalar Functions - 12 functions
		DLL_IMPORT float DXM_CALLCONV XMScalarACos(float Value);
		DLL_IMPORT float DXM_CALLCONV XMScalarACosEst(float Value);
		DLL_IMPORT float DXM_CALLCONV XMScalarASin(float Value);
		DLL_IMPORT float DXM_CALLCONV XMScalarASinEst(float Value);
		DLL_IMPORT float DXM_CALLCONV XMScalarCos(float Value);
		DLL_IMPORT float DXM_CALLCONV XMScalarCosEst(float Value);
		DLL_IMPORT float DXM_CALLCONV XMScalarModAngle(float Value);
		DLL_IMPORT bool DXM_CALLCONV XMScalarNearEqual(float S1, float S2, float Epsilon);
		DLL_IMPORT float DXM_CALLCONV XMScalarSin(float Value);
		DLL_IMPORT void DXM_CALLCONV XMScalarSinCos(_Out_ float* pSin, _Out_ float* pCos, float Value);
		DLL_IMPORT void DXM_CALLCONV XMScalarSinCosEst(_Out_ float* pSin, _Out_ float* pCos, float Value);
		DLL_IMPORT float DXM_CALLCONV XMScalarSinEst(float Value);

		// Vector Functions - Vector Arithmetic Functions - 30 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorAbs(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorAdd(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorAddAngles(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorCeiling(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorClamp(FXMVECTOR V, FXMVECTOR Min, FXMVECTOR Max);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorDivide(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorFloor(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorIsInfinite(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorIsNaN(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorMax(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorMin(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorMod(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorModAngles(FXMVECTOR Angles);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorMultiply(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorMultiplyAdd(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR V3);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorNegate(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorNegativeMultiplySubtract(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR V3);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorPow(FXMVECTOR V1, FXMVECTOR V2); // Faster and Better algorithm than in DirectXMath
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorReciprocal(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorReciprocalEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorReciprocalSqrt(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorReciprocalSqrtEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorRound(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSaturate(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorScale(FXMVECTOR V, float ScaleFactor);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSqrt(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSqrtEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSubtract(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSubtractAngles(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorTruncate(FXMVECTOR V);

		// Vector Functions - Bit-Wise Vector Functions - 7 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorAndCInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorAndInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorNorInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorNotEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorNotEqualInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorOrInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorXorInt(FXMVECTOR V1, FXMVECTOR V2);

		// Vector Functions - Comparison Functions - 11 function
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorEqualInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorEqualIntR(_Out_ uint32_t* pCR, _In_ FXMVECTOR V, _In_ FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorEqualR(_Out_ uint32_t* pCR, _In_ FXMVECTOR V1, _In_ FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorGreater(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorGreaterOrEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorGreaterOrEqualR(_Out_ uint32_t* pCR, _In_ FXMVECTOR V1, _In_ FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorGreaterR(_Out_ uint32_t* pCR, _In_ FXMVECTOR V1, _In_ FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorLess(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorLessOrEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorNearEqual(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Epsilon);

		// Vector Functions - Component-Wise Vector Functions - 14 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorInsert(FXMVECTOR VD, FXMVECTOR VS, uint32_t VSLeftRotateElements,
			uint32_t Select0, uint32_t Select1, uint32_t Select2, uint32_t Select3);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorMergeXY(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorMergeZW(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorPermute(FXMVECTOR V1, FXMVECTOR V2, uint32_t PermuteX, uint32_t PermuteY, uint32_t PermuteZ, uint32_t PermuteW);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorRotateLeft(FXMVECTOR V, uint32_t Elements);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorRotateRight(FXMVECTOR V, uint32_t Elements);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSelect(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Control);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSelectControl(uint32_t VectorIndex0, uint32_t VectorIndex1, uint32_t VectorIndex2, uint32_t VectorIndex3);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorShiftLeft(FXMVECTOR V1, FXMVECTOR V2, uint32_t Elements);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatW(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatX(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatY(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatZ(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSwizzle(FXMVECTOR V, uint32_t E0, uint32_t E1, uint32_t E2, uint32_t E3);

		// Vector Functions - Geometric Vector Functions - 10 functions
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorBaryCentric(FXMVECTOR Position0, FXMVECTOR Position1, FXMVECTOR Position2, float f, float g);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorBaryCentricV(FXMVECTOR Position0, FXMVECTOR Position1, FXMVECTOR Position2, GXMVECTOR F, HXMVECTOR G);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorCatmullRom(FXMVECTOR Position0, FXMVECTOR Position1, FXMVECTOR Position2, GXMVECTOR Position3, float t);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorCatmullRomV(FXMVECTOR Position0, FXMVECTOR Position1, FXMVECTOR Position2, GXMVECTOR Position3, HXMVECTOR T);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorHermite(FXMVECTOR Position0, FXMVECTOR Tangent0, FXMVECTOR Position1, GXMVECTOR Tangent1, float t);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorHermiteV(FXMVECTOR Position0, FXMVECTOR Tangent0, FXMVECTOR Position1, GXMVECTOR Tangent1, HXMVECTOR T);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorInBounds(FXMVECTOR V, FXMVECTOR Bounds);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorInBoundsR(_Out_ uint32_t* pCR, _In_ FXMVECTOR V, _In_ FXMVECTOR Bounds);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorLerp(FXMVECTOR V0, FXMVECTOR V1, float t);
		DLL_IMPORT XMVECTOR  DXM_CALLCONV XMVectorLerpV(FXMVECTOR V0, FXMVECTOR V1, FXMVECTOR T);

		// Vector Functions - Vector Initialization Functions - 17 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorFalseInt();
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorReplicate(float Value);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorReplicateInt(uint32_t Value);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorReplicateIntPtr(_In_ const uint32_t *pValue);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorReplicatePtr(_In_ const float *pValue);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSet(float x, float y, float z, float w);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetBinaryConstant(uint32_t C0, uint32_t C1, uint32_t C2, uint32_t C3);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetInt(uint32_t x, uint32_t y, uint32_t z, uint32_t w);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatConstant(int32_t IntConstant, uint32_t DivExponent);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatConstantInt(int32_t IntConstant);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatEpsilon();
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatInfinity();
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatOne();
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatQNaN();
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSplatSignMask();
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorTrueInt();
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorZero();

		// Vector Functions - Transcendental Vector Functions - 25 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorACos(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorACosEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorASin(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorASinEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorATan(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorATan2(FXMVECTOR Y, FXMVECTOR X);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorATan2Est(FXMVECTOR Y, FXMVECTOR X);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorATanEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorCos(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorCosEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorCosH(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorExp(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorExp2(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorExpE(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorLog(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorLog2(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorLogE(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSin(FXMVECTOR V);
		DLL_IMPORT void  DXM_CALLCONV XMVectorSinCos(_Out_ XMVECTOR* pSin, _Out_ XMVECTOR* pCos, _In_ FXMVECTOR V);
		DLL_IMPORT void  DXM_CALLCONV XMVectorSinCosEst(_Out_ XMVECTOR* pSin, _Out_ XMVECTOR* pCos, _In_ FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSinEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSinH(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorTan(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorTanEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorTanH(FXMVECTOR V);

		// 2D Vector Functions - 2D Vector Comparison Functions - 15 functions
		DLL_IMPORT bool  DXM_CALLCONV XMVector2Equal(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool  DXM_CALLCONV XMVector2EqualInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector2EqualIntR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector2EqualR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector2Greater(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector2GreaterOrEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector2GreaterOrEqualR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector2GreaterR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector2IsInfinite(FXMVECTOR V);
		DLL_IMPORT bool DXM_CALLCONV XMVector2IsNaN(FXMVECTOR V);
		DLL_IMPORT bool DXM_CALLCONV XMVector2Less(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector2LessOrEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector2NearEqual(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Epsilon);
		DLL_IMPORT bool DXM_CALLCONV XMVector2NotEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector2NotEqualInt(FXMVECTOR V1, FXMVECTOR V2);

		// 2D Vector Functions - 2D Vector Geometric Functions - 21 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2AngleBetweenNormals(FXMVECTOR N1, FXMVECTOR N2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2AngleBetweenNormalsEst(FXMVECTOR N1, FXMVECTOR N2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2AngleBetweenVectors(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2ClampLength(FXMVECTOR V, float LengthMin, float LengthMax);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2ClampLengthV(FXMVECTOR V, FXMVECTOR LengthMin, FXMVECTOR LengthMax);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2Cross(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2Dot(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector2InBounds(FXMVECTOR V, FXMVECTOR Bounds);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2IntersectLine(FXMVECTOR Line1Point1, FXMVECTOR Line1Point2, FXMVECTOR Line2Point1, GXMVECTOR Line2Point2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2Length(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2LengthEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2LengthSq(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2LinePointDistance(FXMVECTOR LinePoint1, FXMVECTOR LinePoint2, FXMVECTOR Point);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2Normalize(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2NormalizeEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2Orthogonal(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2ReciprocalLength(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2ReciprocalLengthEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2Reflect(FXMVECTOR Incident, FXMVECTOR Normal);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2Refract(FXMVECTOR Incident, FXMVECTOR Normal, float RefractionIndex);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2RefractV(FXMVECTOR Incident, FXMVECTOR Normal, FXMVECTOR RefractionIndex);

		// 2D Vector Functions - 2D Vector Transformation Functions - 6 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2Transform(FXMVECTOR V, FXMMATRIX M);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2TransformCoord(FXMVECTOR V, FXMMATRIX M);
		DLL_IMPORT XMFLOAT2* DXM_CALLCONV XMVector2TransformCoordStream(_Out_writes_bytes_(sizeof(XMFLOAT2) + OutputStride*(VectorCount - 1)) XMFLOAT2* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT2) + InputStride*(VectorCount - 1)) const XMFLOAT2* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount, _In_ FXMMATRIX M);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector2TransformNormal(FXMVECTOR V, FXMMATRIX M);
		DLL_IMPORT XMFLOAT2* DXM_CALLCONV XMVector2TransformNormalStream(_Out_writes_bytes_(sizeof(XMFLOAT2) + OutputStride*(VectorCount - 1)) XMFLOAT2* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT2) + InputStride*(VectorCount - 1)) const XMFLOAT2* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount, _In_ FXMMATRIX M);
		DLL_IMPORT XMFLOAT4* DXM_CALLCONV XMVector2TransformStream(_Out_writes_bytes_(sizeof(XMFLOAT4) + OutputStride*(VectorCount - 1)) XMFLOAT4* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT2) + InputStride*(VectorCount - 1)) const XMFLOAT2* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount, _In_ FXMMATRIX M);

		// 3D Vector Functions - 3D Vector Comparison Functions - 15 functions
		DLL_IMPORT bool DXM_CALLCONV XMVector3Equal(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector3EqualInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector3EqualIntR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector3EqualR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector3Greater(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector3GreaterOrEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector3GreaterOrEqualR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector3GreaterR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector3IsInfinite(FXMVECTOR V);
		DLL_IMPORT bool DXM_CALLCONV XMVector3IsNaN(FXMVECTOR V);
		DLL_IMPORT bool DXM_CALLCONV XMVector3Less(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector3LessOrEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector3NearEqual(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Epsilon);
		DLL_IMPORT bool DXM_CALLCONV XMVector3NotEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector3NotEqualInt(FXMVECTOR V1, FXMVECTOR V2);

		// 3D Vector Functions - 3D Vector Geometric Functions - 21 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3AngleBetweenNormals(FXMVECTOR N1, FXMVECTOR N2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3AngleBetweenNormalsEst(FXMVECTOR N1, FXMVECTOR N2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3AngleBetweenVectors(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3ClampLength(FXMVECTOR V, float LengthMin, float LengthMax);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3ClampLengthV(FXMVECTOR V, FXMVECTOR LengthMin, FXMVECTOR LengthMax);
		DLL_IMPORT void DXM_CALLCONV XMVector3ComponentsFromNormal(_Out_ XMVECTOR* pParallel, _Out_ XMVECTOR* pPerpendicular, _In_ FXMVECTOR V, _In_ FXMVECTOR Normal);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Cross(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Dot(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector3InBounds(FXMVECTOR V, FXMVECTOR Bounds);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Length(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3LengthEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3LengthSq(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3LinePointDistance(FXMVECTOR LinePoint1, FXMVECTOR LinePoint2, FXMVECTOR Point);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Normalize(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3NormalizeEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Orthogonal(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3ReciprocalLength(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3ReciprocalLengthEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Reflect(FXMVECTOR Incident, FXMVECTOR Normal);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Refract(FXMVECTOR Incident, FXMVECTOR Normal, float RefractionIndex);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3RefractV(FXMVECTOR Incident, FXMVECTOR Normal, FXMVECTOR RefractionIndex);

		// 3D Vector Functions - 3D Vector Transformation Functions - 12 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3InverseRotate(FXMVECTOR V, FXMVECTOR RotationQuaternion);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Project(FXMVECTOR V, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight, float ViewportMinZ, float ViewportMaxZ,
			FXMMATRIX Projection, CXMMATRIX View, CXMMATRIX World);
		DLL_IMPORT XMFLOAT3* DXM_CALLCONV XMVector3ProjectStream(_Out_writes_bytes_(sizeof(XMFLOAT3) + OutputStride*(VectorCount - 1)) XMFLOAT3* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT3) + InputStride*(VectorCount - 1)) const XMFLOAT3* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount,
			_In_ float ViewportX, _In_ float ViewportY, _In_ float ViewportWidth, _In_ float ViewportHeight, _In_ float ViewportMinZ, _In_ float ViewportMaxZ,
			_In_ FXMMATRIX Projection, _In_ CXMMATRIX View, _In_ CXMMATRIX World);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Rotate(FXMVECTOR V, FXMVECTOR RotationQuaternion);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Transform(FXMVECTOR V, FXMMATRIX M);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3TransformCoord(FXMVECTOR V, FXMMATRIX M);
		DLL_IMPORT XMFLOAT3* DXM_CALLCONV XMVector3TransformCoordStream(_Out_writes_bytes_(sizeof(XMFLOAT3) + OutputStride*(VectorCount - 1)) XMFLOAT3* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT3) + InputStride*(VectorCount - 1)) const XMFLOAT3* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount, _In_ FXMMATRIX M);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3TransformNormal(FXMVECTOR V, FXMMATRIX M);
		DLL_IMPORT XMFLOAT3* DXM_CALLCONV XMVector3TransformNormalStream(_Out_writes_bytes_(sizeof(XMFLOAT3) + OutputStride*(VectorCount - 1)) XMFLOAT3* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT3) + InputStride*(VectorCount - 1)) const XMFLOAT3* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount, _In_ FXMMATRIX M);
		DLL_IMPORT XMFLOAT4* DXM_CALLCONV XMVector3TransformStream(_Out_writes_bytes_(sizeof(XMFLOAT4) + OutputStride*(VectorCount - 1)) XMFLOAT4* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT3) + InputStride*(VectorCount - 1)) const XMFLOAT3* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount, _In_ FXMMATRIX M);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector3Unproject(FXMVECTOR V, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight, float ViewportMinZ, float ViewportMaxZ,
			FXMMATRIX Projection, CXMMATRIX View, CXMMATRIX World);
		DLL_IMPORT XMFLOAT3* DXM_CALLCONV XMVector3UnprojectStream(_Out_writes_bytes_(sizeof(XMFLOAT3) + OutputStride*(VectorCount - 1)) XMFLOAT3* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT3) + InputStride*(VectorCount - 1)) const XMFLOAT3* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount,
			_In_ float ViewportX, _In_ float ViewportY, _In_ float ViewportWidth, _In_ float ViewportHeight, _In_ float ViewportMinZ, _In_ float ViewportMaxZ,
			_In_ FXMMATRIX Projection, _In_ CXMMATRIX View, _In_ CXMMATRIX World);

		// 4D Vector Functions - 4D Vector Comparison Functions start - 15 functions
		DLL_IMPORT bool DXM_CALLCONV XMVector4Equal(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector4EqualInt(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector4EqualIntR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector4EqualR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector4Greater(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector4GreaterOrEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector4GreaterOrEqualR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVector4GreaterR(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector4IsInfinite(FXMVECTOR V);
		DLL_IMPORT bool DXM_CALLCONV XMVector4IsNaN(FXMVECTOR V);
		DLL_IMPORT bool DXM_CALLCONV XMVector4Less(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector4LessOrEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector4NearEqual(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Epsilon);
		DLL_IMPORT bool DXM_CALLCONV XMVector4NotEqual(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT bool DXM_CALLCONV XMVector4NotEqualInt(FXMVECTOR V1, FXMVECTOR V2);

		// 4D Vector Functions - 4D Vector Geometric Functions start - 19 function
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4AngleBetweenNormals(FXMVECTOR N1, FXMVECTOR N2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4AngleBetweenNormalsEst(FXMVECTOR N1, FXMVECTOR N2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4AngleBetweenVectors(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4ClampLength(FXMVECTOR V, float LengthMin, float LengthMax);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4ClampLengthV(FXMVECTOR V, FXMVECTOR LengthMin, FXMVECTOR LengthMax);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4Dot(FXMVECTOR V1, FXMVECTOR V2);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4Cross(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR V3);
		DLL_IMPORT bool DXM_CALLCONV XMVector4InBounds(FXMVECTOR V, FXMVECTOR Bounds);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4Length(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4LengthEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4LengthSq(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4Normalize(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4NormalizeEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4Orthogonal(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4ReciprocalLength(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4ReciprocalLengthEst(FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4Reflect(FXMVECTOR Incident, FXMVECTOR Normal);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4Refract(FXMVECTOR Incident, FXMVECTOR Normal, float RefractionIndex);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4RefractV(FXMVECTOR Incident, FXMVECTOR Normal, FXMVECTOR RefractionIndex);

		// 4D Vector Functions - DirectXMath Library 4D Vector Transformation Functions - 2 functions
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVector4Transform(FXMVECTOR V, FXMMATRIX M);
		DLL_IMPORT XMFLOAT4* DXM_CALLCONV XMVector4TransformStream(_Out_writes_bytes_(sizeof(XMFLOAT4) + OutputStride*(VectorCount - 1)) XMFLOAT4* pOutputStream,
			_In_ size_t OutputStride,
			_In_reads_bytes_(sizeof(XMFLOAT4) + InputStride*(VectorCount - 1)) const XMFLOAT4* pInputStream,
			_In_ size_t InputStride, _In_ size_t VectorCount, _In_ FXMMATRIX M);

		// Alternative to Template Functions- 4 functions
		DLL_IMPORT SSIZE_T DXM_CALLCONV XMIMax(SSIZE_T a, SSIZE_T c);
		DLL_IMPORT float DXM_CALLCONV XMFMax(float a, float c);
		DLL_IMPORT SSIZE_T DXM_CALLCONV XMIMin(SSIZE_T a, SSIZE_T c);
		DLL_IMPORT float DXM_CALLCONV XMFMin(float a, float c);

		// Utility Functions start - 9 functions
		DLL_IMPORT bool DXM_CALLCONV XMComparisonAllFalse(uint32_t CR);
		DLL_IMPORT bool DXM_CALLCONV XMComparisonAllInBounds(uint32_t CR);
		DLL_IMPORT bool DXM_CALLCONV XMComparisonAllTrue(uint32_t CR);
		DLL_IMPORT bool DXM_CALLCONV XMComparisonAnyFalse(uint32_t CR);
		DLL_IMPORT bool DXM_CALLCONV XMComparisonAnyOutOfBounds(uint32_t CR);
		DLL_IMPORT bool DXM_CALLCONV XMComparisonAnyTrue(uint32_t CR);
		DLL_IMPORT bool DXM_CALLCONV XMComparisonMixed(uint32_t CR);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMFresnelTerm(FXMVECTOR CosIncidentAngle, FXMVECTOR RefractionIndex);
		DLL_IMPORT bool DXM_CALLCONV XMVerifyCPUSupport(); // uses cpuid directly

		// Vector Accessor Functions - 40 functions
		DLL_IMPORT float DXM_CALLCONV XMVectorGetByIndex(FXMVECTOR V, size_t i);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetByIndexPtr(_Out_ float *f, _In_ FXMVECTOR V, _In_ size_t i);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVectorGetIntByIndex(FXMVECTOR V, size_t i);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetIntByIndexPtr(_Out_ uint32_t *x, _In_ FXMVECTOR V, _In_ size_t i);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVectorGetIntW(FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetIntWPtr(_Out_ uint32_t *w, _In_ FXMVECTOR V);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVectorGetIntX(FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetIntXPtr(_Out_ uint32_t *x, _In_ FXMVECTOR V);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVectorGetIntY(FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetIntYPtr(_Out_ uint32_t *y, _In_ FXMVECTOR V);
		DLL_IMPORT uint32_t DXM_CALLCONV XMVectorGetIntZ(FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetIntZPtr(_Out_ uint32_t *z, _In_ FXMVECTOR V);
		DLL_IMPORT float DXM_CALLCONV XMVectorGetW(FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetWPtr(_Out_ float *w, _In_ FXMVECTOR V);
		DLL_IMPORT float DXM_CALLCONV XMVectorGetX(FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetXPtr(_Out_ float *x, _In_ FXMVECTOR V);
		DLL_IMPORT float DXM_CALLCONV XMVectorGetY(FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetYPtr(_Out_ float *y, _In_ FXMVECTOR V);
		DLL_IMPORT float DXM_CALLCONV XMVectorGetZ(FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMVectorGetZPtr(_Out_ float *z, _In_ FXMVECTOR V);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetByIndex(FXMVECTOR V, float f, size_t i);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetByIndexPtr(_In_ FXMVECTOR V, _In_ const float *f, _In_ size_t i);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntByIndex(FXMVECTOR V, uint32_t x, size_t i);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntByIndexPtr(_In_ FXMVECTOR V, _In_ const uint32_t *x, _In_ size_t i);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntW(FXMVECTOR V, uint32_t w);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntWPtr(_In_ FXMVECTOR V, _In_ const uint32_t *w);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntX(FXMVECTOR V, uint32_t x);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntXPtr(_In_ FXMVECTOR V, _In_ const uint32_t *x);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntY(FXMVECTOR V, uint32_t y);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntYPtr(_In_ FXMVECTOR V, _In_ const uint32_t *y);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntZ(FXMVECTOR V, uint32_t z);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetIntZPtr(_In_ FXMVECTOR V, _In_ const uint32_t *z);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetW(FXMVECTOR V, float w);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetWPtr(_In_ FXMVECTOR V, _In_ const float *w);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetX(FXMVECTOR V, float x);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetXPtr(_In_ FXMVECTOR V, _In_ const float *x);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetY(FXMVECTOR V, float y);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetYPtr(_In_ FXMVECTOR V, _In_ const float *y);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetZ(FXMVECTOR V, float z);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMVectorSetZPtr(_In_ FXMVECTOR V, _In_ const float *z);

		// Vector Load Functions - 56 function
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadByte2(_In_ const XMBYTE2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadByteN2(_In_ const XMBYTEN2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadByte4(_In_ const XMBYTE4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadByteN4(_In_ const XMBYTEN4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadColor(_In_ const XMCOLOR* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadDec4(_In_ const XMDEC4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadDecN4(_In_ const XMDECN4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat(_In_ const float* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat3PK(_In_ const XMFLOAT3PK* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat3SE(_In_ const XMFLOAT3SE* pSource);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMLoadFloat3x3(_In_ const XMFLOAT3X3* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat3(_In_ const XMFLOAT3* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat3A(_In_ const XMFLOAT3A* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat2(_In_ const XMFLOAT2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat2A(_In_ const XMFLOAT2A* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat4(_In_ const XMFLOAT4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadFloat4A(_In_ const XMFLOAT4A* pSource);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMLoadFloat4x3(_In_ const XMFLOAT4X3* pSource);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMLoadFloat4x3A(_In_ const XMFLOAT4X3A* pSource);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMLoadFloat4x4(_In_ const XMFLOAT4X4* pSource);
		DLL_IMPORT XMMATRIX DXM_CALLCONV XMLoadFloat4x4A(_In_ const XMFLOAT4X4A* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadHalf2(_In_ const XMHALF2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadHalf4(_In_ const XMHALF4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadInt(_In_ const uint32_t* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadInt2(_In_reads_(2) const uint32_t* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadInt2A(_In_reads_(2) const uint32_t* PSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadInt3(_In_reads_(3) const uint32_t* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadInt3A(_In_reads_(3) const uint32_t* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadInt4(_In_reads_(4) const uint32_t* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadInt4A(_In_reads_(4) const uint32_t* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadShort2(_In_ const XMSHORT2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadShort4(_In_ const XMSHORT4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadShortN2(_In_ const XMSHORTN2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadShortN4(_In_ const XMSHORTN4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadSInt2(_In_ const XMINT2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadSInt3(_In_ const XMINT3* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadSInt4(_In_ const XMINT4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadU555(_In_ const XMU555* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadU565(_In_ const XMU565* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUByte2(_In_ const XMUBYTE2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUByte4(_In_ const XMUBYTE4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUByteN2(_In_ const XMUBYTEN2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUByteN4(_In_ const XMUBYTEN4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUDec4(_In_ const XMUDEC4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUDecN4(_In_ const XMUDECN4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUDecN4_XR(_In_ const XMUDECN4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUInt2(_In_ const XMUINT2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUInt3(_In_ const XMUINT3* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUInt4(_In_ const XMUINT4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUNibble4(_In_ const XMUNIBBLE4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUShort2(_In_ const XMUSHORT2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUShort4(_In_ const XMUSHORT4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUShortN2(_In_ const XMUSHORTN2* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadUShortN4(_In_ const XMUSHORTN4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadXDec4(_In_ const XMXDEC4* pSource);
		DLL_IMPORT XMVECTOR DXM_CALLCONV XMLoadXDecN4(_In_ const XMXDECN4* pSource);

		// Vector Store Functions start - 56 functions
		DLL_IMPORT void DXM_CALLCONV XMStoreByte2(_Out_ XMBYTE2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreByte4(_Out_ XMBYTE4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreByteN2(_Out_ XMBYTEN2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreByteN4(_Out_ XMBYTEN4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreColor(_Out_ XMCOLOR* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreDec4(_Out_ XMDEC4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreDecN4(_Out_ XMDECN4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat(_Out_ float* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat2(_Out_ XMFLOAT2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat2A(_Out_ XMFLOAT2A* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat3(_Out_ XMFLOAT3* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat3A(_Out_ XMFLOAT3A* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat3PK(_Out_ XMFLOAT3PK* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat3SE(_Out_ XMFLOAT3SE* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat3x3(_Out_ XMFLOAT3X3* pDestination, _In_ FXMMATRIX M);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat4(_Out_ XMFLOAT4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat4A(_Out_ XMFLOAT4A* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat4x3(_Out_ XMFLOAT4X3* pDestination, _In_ FXMMATRIX M);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat4x3A(_Out_ XMFLOAT4X3A* pDestination, _In_ FXMMATRIX M);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat4x4(_Out_ XMFLOAT4X4* pDestination, _In_ FXMMATRIX M);
		DLL_IMPORT void DXM_CALLCONV XMStoreFloat4x4A(_Out_ XMFLOAT4X4A* pDestination, _In_ FXMMATRIX M);
		DLL_IMPORT void DXM_CALLCONV XMStoreHalf2(_Out_ XMHALF2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreHalf4(_Out_ XMHALF4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreInt(_Out_ uint32_t* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreInt2(_Out_writes_(2) uint32_t* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreInt2A(_Out_writes_(2) uint32_t* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreInt3(_Out_writes_(3) uint32_t* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreInt3A(_Out_writes_(3) uint32_t* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreInt4(_Out_writes_(4) uint32_t* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreInt4A(_Out_writes_(4) uint32_t* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreShort2(_Out_ XMSHORT2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreShort4(_Out_ XMSHORT4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreShortN2(_Out_ XMSHORTN2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreShortN4(_Out_ XMSHORTN4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreSInt2(_Out_ XMINT2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreSInt3(_Out_ XMINT3* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreSInt4(_Out_ XMINT4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreU555(_Out_ XMU555* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreU565(_Out_ XMU565* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUByte2(_Out_ XMUBYTE2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUByte4(_Out_ XMUBYTE4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUByteN2(_Out_ XMUBYTEN2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUByteN4(_Out_ XMUBYTEN4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUDec4(_Out_ XMUDEC4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUDecN4(_Out_ XMUDECN4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUDecN4_XR(_Out_ XMUDECN4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUInt2(_Out_ XMUINT2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUInt3(_Out_ XMUINT3* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUInt4(_Out_ XMUINT4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUNibble4(_Out_ XMUNIBBLE4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUShort2(_Out_ XMUSHORT2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUShort4(_Out_ XMUSHORT4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUShortN2(_Out_ XMUSHORTN2* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreUShortN4(_Out_ XMUSHORTN4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreXDec4(_Out_ XMXDEC4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT void DXM_CALLCONV XMStoreXDecN4(_Out_ XMXDECN4* pDestination, _In_ FXMVECTOR V);
		DLL_IMPORT uint32_t  DXM_CALLCONV  TriangleTestsContainedBy(_In_ FXMVECTOR V0, _In_ FXMVECTOR V1, _In_ FXMVECTOR V2,
			_In_ GXMVECTOR Plane0, _In_ HXMVECTOR Plane1, _In_ HXMVECTOR Plane2,
			_In_ CXMVECTOR Plane3, _In_ CXMVECTOR Plane4, _In_ CXMVECTOR Plane5);
		DLL_IMPORT bool DXM_CALLCONV Intersects1(FXMVECTOR Origin, FXMVECTOR Direction, FXMVECTOR V0, GXMVECTOR V1, HXMVECTOR V2, float& Dist);
		DLL_IMPORT bool DXM_CALLCONV Intersects2(FXMVECTOR A0, FXMVECTOR A1, FXMVECTOR A2, GXMVECTOR B0, HXMVECTOR B1, HXMVECTOR B2);
		DLL_IMPORT uint32_t   DXM_CALLCONV  Intersects3(_In_ FXMVECTOR V0, _In_ FXMVECTOR V1, _In_ FXMVECTOR V2, _In_ GXMVECTOR Plane);

	};

	inline XMCOLOR::XMCOLOR(float _r, float _g, float _b, float _a)
	{
		XMStoreColor(this, XMVectorSet(_r, _g, _b, _a));
	}

	inline XMUDEC4::XMUDEC4(float _x, float _y, float _z, float _w)
	{
		XMStoreUDec4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMUDEC4::XMUDEC4(const float* pArray)
	{
		XMStoreUDec4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMUNIBBLE4::XMUNIBBLE4(float _x, float _y, float _z, float _w)
	{
		XMStoreUNibble4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMUNIBBLE4::XMUNIBBLE4(const float *pArray)
	{
		XMStoreUNibble4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMUSHORT2::XMUSHORT2(float _x, float _y)
	{
		XMStoreUShort2(this, XMVectorSet(_x, _y, 0.0f, 0.0f));
	}

	_Use_decl_annotations_
		inline XMUSHORT2::XMUSHORT2(const float* pArray)
	{
		XMStoreUShort2(this, XMLoadFloat2(reinterpret_cast<const XMFLOAT2*>(pArray)));
	}

	inline XMUSHORT4::XMUSHORT4(float _x, float _y, float _z, float _w)
	{
		XMStoreUShort4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMUSHORT4::XMUSHORT4(const float* pArray)
	{
		XMStoreUShort4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMXDEC4::XMXDEC4(float _x, float _y, float _z, float _w)
	{
		XMStoreXDec4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMXDEC4::XMXDEC4(const float* pArray)
	{
		XMStoreXDec4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMFLOAT3PK::XMFLOAT3PK(float _x, float _y, float _z)
	{
		XMStoreFloat3PK(this, XMVectorSet(_x, _y, _z, 0.0f));
	}

	_Use_decl_annotations_
		inline XMFLOAT3PK::XMFLOAT3PK(const float *pArray)
	{
		XMStoreFloat3PK(this, XMLoadFloat3(reinterpret_cast<const XMFLOAT3*>(pArray)));
	}

	inline XMFLOAT3SE::XMFLOAT3SE(float _x, float _y, float _z)
	{
		XMStoreFloat3SE(this, XMVectorSet(_x, _y, _z, 0.0f));
	}

	_Use_decl_annotations_
		inline XMFLOAT3SE::XMFLOAT3SE(const float *pArray)
	{
		XMStoreFloat3SE(this, XMLoadFloat3(reinterpret_cast<const XMFLOAT3*>(pArray)));
	}

	inline XMSHORT2::XMSHORT2(float _x, float _y)
	{
		XMStoreShort2(this, XMVectorSet(_x, _y, 0.0f, 0.0f));
	}

	_Use_decl_annotations_
		inline XMSHORT2::XMSHORT2(const float* pArray)
	{
		XMStoreShort2(this, XMLoadFloat2(reinterpret_cast<const XMFLOAT2*>(pArray)));
	}

	inline XMSHORT4::XMSHORT4(float _x, float _y, float _z, float _w)
	{
		XMStoreShort4(this, XMVectorSet(_x, _y, _z, _w));
	}

	//------------------------------------------------------------------------------
	_Use_decl_annotations_
		inline XMSHORT4::XMSHORT4(const float* pArray)
	{
		XMStoreShort4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMU555::XMU555(float _x, float _y, float _z, bool _w)
	{
		XMStoreU555(this, XMVectorSet(_x, _y, _z, ((_w) ? 1.0f : 0.0f)));
	}

	_Use_decl_annotations_
		inline XMU555::XMU555(const float *pArray, bool _w)
	{
		XMVECTOR V = XMLoadFloat3(reinterpret_cast<const XMFLOAT3*>(pArray));
		XMStoreU555(this, XMVectorSetW(V, ((_w) ? 1.0f : 0.0f)));
	}

	inline XMU565::XMU565(float _x, float _y, float _z)
	{
		XMStoreU565(this, XMVectorSet(_x, _y, _z, 0.0f));
	}

	_Use_decl_annotations_	inline XMU565::XMU565(const float *pArray)
	{
		XMStoreU565(this, XMLoadFloat3(reinterpret_cast<const XMFLOAT3*>(pArray)));
	}

	inline XMUBYTE2::XMUBYTE2(float _x, float _y)
	{
		XMStoreUByte2(this, XMVectorSet(_x, _y, 0.0f, 0.0f));
	}

	_Use_decl_annotations_
		inline XMUBYTE2::XMUBYTE2(const float* pArray)
	{
		XMStoreUByte2(this, XMLoadFloat2(reinterpret_cast<const XMFLOAT2*>(pArray)));
	}

	inline XMUBYTE4::XMUBYTE4(float _x, float _y, float _z, float _w)
	{
		XMStoreUByte4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMUBYTE4::XMUBYTE4(const float* pArray)
	{
		XMStoreUByte4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMBYTE2::XMBYTE2(float _x, float _y)
	{
		XMStoreByte2(this, XMVectorSet(_x, _y, 0.0f, 0.0f));
	}

	_Use_decl_annotations_
		inline XMBYTE2::XMBYTE2(const float* pArray)
	{
		XMStoreByte2(this, XMLoadFloat2(reinterpret_cast<const XMFLOAT2*>(pArray)));
	}

	inline XMBYTEN2::XMBYTEN2(float _x, float _y)
	{
		XMStoreByteN2(this, XMVectorSet(_x, _y, 0.0f, 0.0f));
	}

	_Use_decl_annotations_
		inline XMBYTEN2::XMBYTEN2(const float* pArray)
	{
		XMStoreByteN2(this, XMLoadFloat2(reinterpret_cast<const XMFLOAT2*>(pArray)));
	}

	inline XMBYTE4::XMBYTE4(float _x, float _y, float _z, float _w)
	{
		XMStoreByte4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMBYTE4::XMBYTE4(const float* pArray)
	{
		XMStoreByte4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMBYTEN4::XMBYTEN4(float _x, float _y, float _z, float _w)
	{
		XMStoreByteN4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMBYTEN4::XMBYTEN4(const float* pArray)
	{
		XMStoreByteN4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMDEC4::XMDEC4(float _x, float _y, float _z, float _w)
	{
		XMStoreDec4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMDEC4::XMDEC4(const float* pArray)
	{
		XMStoreDec4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMUDECN4::XMUDECN4(float _x, float _y, float _z, float _w)
	{
		XMStoreUDecN4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMUDECN4::XMUDECN4(const float* pArray)
	{
		XMStoreUDecN4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMDECN4::XMDECN4(float _x, float _y, float _z, float _w)
	{
		XMStoreDecN4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMDECN4::XMDECN4(const float* pArray)
	{
		XMStoreDecN4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMHALF2::XMHALF2(float _x, float _y)
	{
		x = XMConvertFloatToHalf(_x);
		y = XMConvertFloatToHalf(_y);
	}

	_Use_decl_annotations_ inline XMHALF2::XMHALF2(const float* pArray)
	{
		assert(pArray != nullptr);
		x = XMConvertFloatToHalf(pArray[0]);
		y = XMConvertFloatToHalf(pArray[1]);
	}

	inline XMHALF4::XMHALF4(float _x, float _y, float _z, float _w)
	{
		x = XMConvertFloatToHalf(_x);
		y = XMConvertFloatToHalf(_y);
		z = XMConvertFloatToHalf(_z);
		w = XMConvertFloatToHalf(_w);
	}

	//------------------------------------------------------------------------------

	_Use_decl_annotations_
		inline XMHALF4::XMHALF4(const float* pArray)
	{
		XMConvertFloatToHalfStream(&x, sizeof(HALF), pArray, sizeof(float), 4);
	}

	inline XMSHORTN2::XMSHORTN2(float _x, float _y)
	{
		XMStoreShortN2(this, XMVectorSet(_x, _y, 0.0f, 0.0f));
	}

	_Use_decl_annotations_
		inline XMSHORTN2::XMSHORTN2(const float* pArray)
	{
		XMStoreShortN2(this, XMLoadFloat2(reinterpret_cast<const XMFLOAT2*>(pArray)));
	}

	inline XMSHORTN4::XMSHORTN4(float _x, float _y, float _z, float _w)
	{
		XMStoreShortN4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMSHORTN4::XMSHORTN4(const float* pArray)
	{
		XMStoreShortN4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMUBYTEN2::XMUBYTEN2(float _x, float _y)
	{
		XMStoreUByteN2(this, XMVectorSet(_x, _y, 0.0f, 0.0f));
	}

	_Use_decl_annotations_
		inline XMUBYTEN2::XMUBYTEN2(const float* pArray)
	{
		XMStoreUByteN2(this, XMLoadFloat2(reinterpret_cast<const XMFLOAT2*>(pArray)));
	}

	inline XMUBYTEN4::XMUBYTEN4(float _x, float _y, float _z, float _w)
	{
		XMStoreUByteN4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMUBYTEN4::XMUBYTEN4(const float* pArray)
	{
		XMStoreUByteN4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMUSHORTN2::XMUSHORTN2(float _x, float _y)
	{
		XMStoreUShortN2(this, XMVectorSet(_x, _y, 0.0f, 0.0f));
	}

	_Use_decl_annotations_
		inline XMUSHORTN2::XMUSHORTN2(const float* pArray)
	{
		XMStoreUShortN2(this, XMLoadFloat2(reinterpret_cast<const XMFLOAT2*>(pArray)));
	}

	inline XMUSHORTN4::XMUSHORTN4(float _x, float _y, float _z, float _w)
	{
		XMStoreUShortN4(this, XMVectorSet(_x, _y, _z, _w));
	}

	_Use_decl_annotations_
		inline XMUSHORTN4::XMUSHORTN4(const float* pArray)
	{
		XMStoreUShortN4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMXDECN4::XMXDECN4(float _x, float _y, float _z, float _w)
	{
		XMStoreXDecN4(this, XMVectorSet(_x, _y, _z, _w));
	}

	//------------------------------------------------------------------------------
	_Use_decl_annotations_
		inline XMXDECN4::XMXDECN4(const float* pArray)
	{
		XMStoreXDecN4(this, XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(pArray)));
	}

	inline XMMATRIX::XMMATRIX
	(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33
	)
	{
		r[0] = XMVectorSet(m00, m01, m02, m03);
		r[1] = XMVectorSet(m10, m11, m12, m13);
		r[2] = XMVectorSet(m20, m21, m22, m23);
		r[3] = XMVectorSet(m30, m31, m32, m33);
	}

	inline XMMATRIX::XMMATRIX(const float* pArray)
	{
		assert(pArray != nullptr);
		r[0] = XMLoadFloat4((const XMFLOAT4*)pArray);
		r[1] = XMLoadFloat4((const XMFLOAT4*)(pArray + 4));
		r[2] = XMLoadFloat4((const XMFLOAT4*)(pArray + 8));
		r[3] = XMLoadFloat4((const XMFLOAT4*)(pArray + 12));
	}

	inline XMMATRIX& XMMATRIX::operator+= (FXMMATRIX M)
	{
		r[0] = XMVectorAdd(r[0], M.r[0]);
		r[1] = XMVectorAdd(r[1], M.r[1]);
		r[2] = XMVectorAdd(r[2], M.r[2]);
		r[3] = XMVectorAdd(r[3], M.r[3]);
		return *this;
	}
	inline XMMATRIX XMMATRIX::operator+ (FXMMATRIX M) const
	{
		XMMATRIX R;
		R.r[0] = XMVectorAdd(r[0], M.r[0]);
		R.r[1] = XMVectorAdd(r[1], M.r[1]);
		R.r[2] = XMVectorAdd(r[2], M.r[2]);
		R.r[3] = XMVectorAdd(r[3], M.r[3]);
		return R;
	}
	inline XMMATRIX XMMATRIX::operator- () const
	{
		XMMATRIX R;
		R.r[0] = XMVectorNegate(r[0]);
		R.r[1] = XMVectorNegate(r[1]);
		R.r[2] = XMVectorNegate(r[2]);
		R.r[3] = XMVectorNegate(r[3]);
		return R;
	}

	inline XMMATRIX& XMMATRIX::operator-= (FXMMATRIX M)
	{
		r[0] = XMVectorSubtract(r[0], M.r[0]);
		r[1] = XMVectorSubtract(r[1], M.r[1]);
		r[2] = XMVectorSubtract(r[2], M.r[2]);
		r[3] = XMVectorSubtract(r[3], M.r[3]);
		return *this;
	}
	inline XMMATRIX& XMMATRIX::operator*=(FXMMATRIX M)
	{
		*this = XMMatrixMultiply(*this, M);
		return *this;
	}
	inline XMMATRIX& XMMATRIX::operator*= (float S)
	{
		r[0] = XMVectorScale(r[0], S);
		r[1] = XMVectorScale(r[1], S);
		r[2] = XMVectorScale(r[2], S);
		r[3] = XMVectorScale(r[3], S);
		return *this;
	}
	inline XMMATRIX& XMMATRIX::operator/= (float S)
	{
		XMVECTOR vS = XMVectorReplicate(S);
		r[0] = XMVectorDivide(r[0], vS);
		r[1] = XMVectorDivide(r[1], vS);
		r[2] = XMVectorDivide(r[2], vS);
		r[3] = XMVectorDivide(r[3], vS);
		return *this;
	}
	inline XMMATRIX XMMATRIX::operator- (FXMMATRIX M) const
	{
		XMMATRIX R;
		R.r[0] = XMVectorSubtract(r[0], M.r[0]);
		R.r[1] = XMVectorSubtract(r[1], M.r[1]);
		R.r[2] = XMVectorSubtract(r[2], M.r[2]);
		R.r[3] = XMVectorSubtract(r[3], M.r[3]);
		return R;
	}
	inline XMMATRIX XMMATRIX::operator*(FXMMATRIX M) const
	{
		return XMMatrixMultiply(*this, M);
	}
	inline XMMATRIX XMMATRIX::operator* (float S) const
	{
		XMMATRIX R;
		R.r[0] = XMVectorScale(r[0], S);
		R.r[1] = XMVectorScale(r[1], S);
		R.r[2] = XMVectorScale(r[2], S);
		R.r[3] = XMVectorScale(r[3], S);
		return R;
	}
	inline XMMATRIX XMMATRIX::operator/ (float S) const
	{
		XMVECTOR vS = XMVectorReplicate(S);
		XMMATRIX R;
		R.r[0] = XMVectorDivide(r[0], vS);
		R.r[1] = XMVectorDivide(r[1], vS);
		R.r[2] = XMVectorDivide(r[2], vS);
		R.r[3] = XMVectorDivide(r[3], vS);
		return R;
	}

	inline XMMATRIX operator* (float S, FXMMATRIX M)
	{
		XMMATRIX R;
		R.r[0] = XMVectorScale(M.r[0], S);
		R.r[1] = XMVectorScale(M.r[1], S);
		R.r[2] = XMVectorScale(M.r[2], S);
		R.r[3] = XMVectorScale(M.r[3], S);
		return R;
	}

	inline XMFLOAT3X3::XMFLOAT3X3
	(
		float m00, float m01, float m02,
		float m10, float m11, float m12,
		float m20, float m21, float m22
	)
	{
		m[0][0] = m00;
		m[0][1] = m01;
		m[0][2] = m02;

		m[1][0] = m10;
		m[1][1] = m11;
		m[1][2] = m12;

		m[2][0] = m20;
		m[2][1] = m21;
		m[2][2] = m22;
	}
	_Use_decl_annotations_
		inline XMFLOAT3X3::XMFLOAT3X3(const float* pArray)
	{
		assert(pArray != nullptr);
		for (size_t Row = 0; Row < 3; Row++)
		{
			for (size_t Column = 0; Column < 3; Column++)
			{
				m[Row][Column] = pArray[Row * 3 + Column];
			}
		}
	}
	inline XMFLOAT3X3& XMFLOAT3X3::operator= (const XMFLOAT3X3& Float3x3)
	{
		_11 = Float3x3._11;
		_12 = Float3x3._12;
		_13 = Float3x3._13;
		_21 = Float3x3._21;
		_22 = Float3x3._22;
		_23 = Float3x3._23;
		_31 = Float3x3._31;
		_32 = Float3x3._32;
		_33 = Float3x3._33;

		return *this;
	}

	inline XMFLOAT4X3::XMFLOAT4X3
	(
		float m00, float m01, float m02,
		float m10, float m11, float m12,
		float m20, float m21, float m22,
		float m30, float m31, float m32
	)
	{
		m[0][0] = m00;
		m[0][1] = m01;
		m[0][2] = m02;

		m[1][0] = m10;
		m[1][1] = m11;
		m[1][2] = m12;

		m[2][0] = m20;
		m[2][1] = m21;
		m[2][2] = m22;

		m[3][0] = m30;
		m[3][1] = m31;
		m[3][2] = m32;
	}

	_Use_decl_annotations_
		inline XMFLOAT4X3::XMFLOAT4X3(const float* pArray)
	{
		assert(pArray != nullptr);

		m[0][0] = pArray[0];
		m[0][1] = pArray[1];
		m[0][2] = pArray[2];

		m[1][0] = pArray[3];
		m[1][1] = pArray[4];
		m[1][2] = pArray[5];

		m[2][0] = pArray[6];
		m[2][1] = pArray[7];
		m[2][2] = pArray[8];

		m[3][0] = pArray[9];
		m[3][1] = pArray[10];
		m[3][2] = pArray[11];
	}
	inline XMFLOAT4X3& XMFLOAT4X3::operator= (const XMFLOAT4X3& Float4x3)
	{
		XMVECTOR V1 = XMLoadFloat4((const XMFLOAT4*)&Float4x3._11);
		XMVECTOR V2 = XMLoadFloat4((const XMFLOAT4*)&Float4x3._22);
		XMVECTOR V3 = XMLoadFloat4((const XMFLOAT4*)&Float4x3._33);

		XMStoreFloat4((XMFLOAT4*)&_11, V1);
		XMStoreFloat4((XMFLOAT4*)&_22, V2);
		XMStoreFloat4((XMFLOAT4*)&_33, V3);

		return *this;
	}
	inline XMFLOAT4X4::XMFLOAT4X4
	(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33
	)
	{
		m[0][0] = m00;
		m[0][1] = m01;
		m[0][2] = m02;
		m[0][3] = m03;

		m[1][0] = m10;
		m[1][1] = m11;
		m[1][2] = m12;
		m[1][3] = m13;

		m[2][0] = m20;
		m[2][1] = m21;
		m[2][2] = m22;
		m[2][3] = m23;

		m[3][0] = m30;
		m[3][1] = m31;
		m[3][2] = m32;
		m[3][3] = m33;
	}
	_Use_decl_annotations_
		inline XMFLOAT4X4::XMFLOAT4X4(const float* pArray)
	{
		assert(pArray != nullptr);

		m[0][0] = pArray[0];
		m[0][1] = pArray[1];
		m[0][2] = pArray[2];
		m[0][3] = pArray[3];

		m[1][0] = pArray[4];
		m[1][1] = pArray[5];
		m[1][2] = pArray[6];
		m[1][3] = pArray[7];

		m[2][0] = pArray[8];
		m[2][1] = pArray[9];
		m[2][2] = pArray[10];
		m[2][3] = pArray[11];

		m[3][0] = pArray[12];
		m[3][1] = pArray[13];
		m[3][2] = pArray[14];
		m[3][3] = pArray[15];
	}
	inline XMFLOAT4X4& XMFLOAT4X4::operator= (const XMFLOAT4X4& Float4x4)
	{
		XMVECTOR V1 = XMLoadFloat4((const XMFLOAT4*)&Float4x4._11);
		XMVECTOR V2 = XMLoadFloat4((const XMFLOAT4*)&Float4x4._21);
		XMVECTOR V3 = XMLoadFloat4((const XMFLOAT4*)&Float4x4._31);
		XMVECTOR V4 = XMLoadFloat4((const XMFLOAT4*)&Float4x4._41);

		XMStoreFloat4((XMFLOAT4*)&_11, V1);
		XMStoreFloat4((XMFLOAT4*)&_21, V2);
		XMStoreFloat4((XMFLOAT4*)&_31, V3);
		XMStoreFloat4((XMFLOAT4*)&_41, V4);

		return *this;
	}

	inline XMVECTOR operator+ (FXMVECTOR V)
	{
		return V;
	}

	inline XMVECTOR operator- (FXMVECTOR V)
	{
		return XMVectorNegate(V);
	}

	inline XMVECTOR& operator+= (XMVECTOR& V1, FXMVECTOR V2)
	{
		V1 = XMVectorAdd(V1, V2);
		return V1;
	}

	inline XMVECTOR& operator-= (XMVECTOR& V1, FXMVECTOR V2)
	{
		V1 = XMVectorSubtract(V1, V2);
		return V1;
	}

	inline XMVECTOR& operator*=(XMVECTOR& V1, FXMVECTOR V2)
	{
		V1 = XMVectorMultiply(V1, V2);
		return V1;
	}

	inline XMVECTOR& operator/= (XMVECTOR& V1, FXMVECTOR V2)
	{
		V1 = XMVectorDivide(V1, V2);
		return V1;
	}

	inline XMVECTOR& operator*= (XMVECTOR&  V, const float S)
	{
		V = XMVectorScale(V, S);
		return V;
	}

	inline XMVECTOR& operator/= (XMVECTOR& V, const float S)
	{
		XMVECTOR vS = XMVectorReplicate(S);
		V = XMVectorDivide(V, vS);
		return V;
	}

	inline XMVECTOR operator+ (FXMVECTOR V1, FXMVECTOR V2)
	{
		return XMVectorAdd(V1, V2);
	}

	inline XMVECTOR operator-(FXMVECTOR V1, FXMVECTOR V2)
	{
		return XMVectorSubtract(V1, V2);
	}

	inline XMVECTOR operator*(FXMVECTOR V1, FXMVECTOR V2)
	{
		return XMVectorMultiply(V1, V2);
	}

	inline XMVECTOR operator/	(FXMVECTOR V1, FXMVECTOR V2)
	{
		return XMVectorDivide(V1, V2);
	}

	inline XMVECTOR operator*	(FXMVECTOR V, const float S)
	{
		return XMVectorScale(V, S);
	}

	inline XMVECTOR operator/ (FXMVECTOR V, const float S)
	{
		XMVECTOR vS = XMVectorReplicate(S);
		return XMVectorDivide(V, vS);
	}

	inline XMVECTOR operator*	(float S, FXMVECTOR V)
	{
		return XMVectorScale(V, S);
	}

	const uint32_t XM_SELECT_0 = 0x00000000;
	const uint32_t XM_SELECT_1 = 0xFFFFFFFF;
	const float XM_PI = 3.141592654f;
	const float XM_2PI = 6.283185307f;
	const float XM_1DIVPI = 0.318309886f;
	const float XM_1DIV2PI = 0.159154943f;
	const float XM_PIDIV2 = 1.570796327f;
	const float XM_PIDIV4 = 0.785398163f;
	const uint32_t XM_PERMUTE_0X = 0;
	const uint32_t XM_PERMUTE_0Y = 1;
	const uint32_t XM_PERMUTE_0Z = 2;
	const uint32_t XM_PERMUTE_0W = 3;
	const uint32_t XM_PERMUTE_1X = 4;
	const uint32_t XM_PERMUTE_1Y = 5;
	const uint32_t XM_PERMUTE_1Z = 6;
	const uint32_t XM_PERMUTE_1W = 7;

	const uint32_t XM_SWIZZLE_X = 0;
	const uint32_t XM_SWIZZLE_Y = 1;
	const uint32_t XM_SWIZZLE_Z = 2;
	const uint32_t XM_SWIZZLE_W = 3;


	XMGLOBALCONST XMVECTORF32 g_XMSinCoefficients0 = { -0.16666667f, +0.0083333310f, -0.00019840874f, +2.7525562e-06f };
	XMGLOBALCONST XMVECTORF32 g_XMSinCoefficients1 = { -2.3889859e-08f, -0.16665852f /*Est1*/, +0.0083139502f /*Est2*/, -0.00018524670f /*Est3*/ };
	XMGLOBALCONST XMVECTORF32 g_XMCosCoefficients0 = { -0.5f, +0.041666638f, -0.0013888378f, +2.4760495e-05f };
	XMGLOBALCONST XMVECTORF32 g_XMCosCoefficients1 = { -2.6051615e-07f, -0.49992746f /*Est1*/, +0.041493919f /*Est2*/, -0.0012712436f /*Est3*/ };
	XMGLOBALCONST XMVECTORF32 g_XMTanCoefficients0 = { 1.0f, 0.333333333f, 0.133333333f, 5.396825397e-2f };
	XMGLOBALCONST XMVECTORF32 g_XMTanCoefficients1 = { 2.186948854e-2f, 8.863235530e-3f, 3.592128167e-3f, 1.455834485e-3f };
	XMGLOBALCONST XMVECTORF32 g_XMTanCoefficients2 = { 5.900274264e-4f, 2.391290764e-4f, 9.691537707e-5f, 3.927832950e-5f };
	XMGLOBALCONST XMVECTORF32 g_XMArcCoefficients0 = { +1.5707963050f, -0.2145988016f, +0.0889789874f, -0.0501743046f };
	XMGLOBALCONST XMVECTORF32 g_XMArcCoefficients1 = { +0.0308918810f, -0.0170881256f, +0.0066700901f, -0.0012624911f };
	XMGLOBALCONST XMVECTORF32 g_XMATanCoefficients0 = { -0.3333314528f, +0.1999355085f, -0.1420889944f, +0.1065626393f };
	XMGLOBALCONST XMVECTORF32 g_XMATanCoefficients1 = { -0.0752896400f, +0.0429096138f, -0.0161657367f, +0.0028662257f };
	XMGLOBALCONST XMVECTORF32 g_XMATanEstCoefficients0 = { +0.999866f, +0.999866f, +0.999866f, +0.999866f };
	XMGLOBALCONST XMVECTORF32 g_XMATanEstCoefficients1 = { -0.3302995f, +0.180141f, -0.085133f, +0.0208351f };
	XMGLOBALCONST XMVECTORF32 g_XMTanEstCoefficients = { 2.484f, -1.954923183e-1f, 2.467401101f, XM_1DIVPI };
	XMGLOBALCONST XMVECTORF32 g_XMArcEstCoefficients = { +1.5707288f,-0.2121144f,+0.0742610f,-0.0187293f };
	XMGLOBALCONST XMVECTORF32 g_XMPiConstants0 = { XM_PI, XM_2PI, XM_1DIVPI, XM_1DIV2PI };
	XMGLOBALCONST XMVECTORF32 g_XMIdentityR0 = { 1.0f, 0.0f, 0.0f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMIdentityR1 = { 0.0f, 1.0f, 0.0f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMIdentityR2 = { 0.0f, 0.0f, 1.0f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMIdentityR3 = { 0.0f, 0.0f, 0.0f, 1.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNegIdentityR0 = { -1.0f,0.0f, 0.0f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNegIdentityR1 = { 0.0f,-1.0f, 0.0f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNegIdentityR2 = { 0.0f, 0.0f,-1.0f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNegIdentityR3 = { 0.0f, 0.0f, 0.0f,-1.0f };
	XMGLOBALCONST XMVECTORU32 g_XMNegativeZero = { 0x80000000, 0x80000000, 0x80000000, 0x80000000 };
	XMGLOBALCONST XMVECTORU32 g_XMNegate3 = { 0x80000000, 0x80000000, 0x80000000, 0x00000000 };
	XMGLOBALCONST XMVECTORU32 g_XMMask3 = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000 };
	XMGLOBALCONST XMVECTORU32 g_XMMaskX = { 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000 };
	XMGLOBALCONST XMVECTORU32 g_XMMaskY = { 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000 };
	XMGLOBALCONST XMVECTORU32 g_XMMaskZ = { 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000 };
	XMGLOBALCONST XMVECTORU32 g_XMMaskW = { 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF };
	XMGLOBALCONST XMVECTORF32 g_XMOne = { 1.0f, 1.0f, 1.0f, 1.0f };
	XMGLOBALCONST XMVECTORF32 g_XMOne3 = { 1.0f, 1.0f, 1.0f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMZero = { 0.0f, 0.0f, 0.0f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMTwo = { 2.f, 2.f, 2.f, 2.f };
	XMGLOBALCONST XMVECTORF32 g_XMFour = { 4.f, 4.f, 4.f, 4.f };
	XMGLOBALCONST XMVECTORF32 g_XMSix = { 6.f, 6.f, 6.f, 6.f };
	XMGLOBALCONST XMVECTORF32 g_XMNegativeOne = { -1.0f,-1.0f,-1.0f,-1.0f };
	XMGLOBALCONST XMVECTORF32 g_XMOneHalf = { 0.5f, 0.5f, 0.5f, 0.5f };
	XMGLOBALCONST XMVECTORF32 g_XMNegativeOneHalf = { -0.5f,-0.5f,-0.5f,-0.5f };
	XMGLOBALCONST XMVECTORF32 g_XMNegativeTwoPi = { -XM_2PI, -XM_2PI, -XM_2PI, -XM_2PI };
	XMGLOBALCONST XMVECTORF32 g_XMNegativePi = { -XM_PI, -XM_PI, -XM_PI, -XM_PI };
	XMGLOBALCONST XMVECTORF32 g_XMHalfPi = { XM_PIDIV2, XM_PIDIV2, XM_PIDIV2, XM_PIDIV2 };
	XMGLOBALCONST XMVECTORF32 g_XMPi = { XM_PI, XM_PI, XM_PI, XM_PI };
	XMGLOBALCONST XMVECTORF32 g_XMReciprocalPi = { XM_1DIVPI, XM_1DIVPI, XM_1DIVPI, XM_1DIVPI };
	XMGLOBALCONST XMVECTORF32 g_XMTwoPi = { XM_2PI, XM_2PI, XM_2PI, XM_2PI };
	XMGLOBALCONST XMVECTORF32 g_XMReciprocalTwoPi = { XM_1DIV2PI, XM_1DIV2PI, XM_1DIV2PI, XM_1DIV2PI };
	XMGLOBALCONST XMVECTORF32 g_XMEpsilon = { 1.192092896e-7f, 1.192092896e-7f, 1.192092896e-7f, 1.192092896e-7f };
	XMGLOBALCONST XMVECTORI32 g_XMInfinity = { 0x7F800000, 0x7F800000, 0x7F800000, 0x7F800000 };
	XMGLOBALCONST XMVECTORI32 g_XMQNaN = { 0x7FC00000, 0x7FC00000, 0x7FC00000, 0x7FC00000 };
	XMGLOBALCONST XMVECTORI32 g_XMQNaNTest = { 0x007FFFFF, 0x007FFFFF, 0x007FFFFF, 0x007FFFFF };
	XMGLOBALCONST XMVECTORI32 g_XMAbsMask = { 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF };
	XMGLOBALCONST XMVECTORI32 g_XMFltMin = { 0x00800000, 0x00800000, 0x00800000, 0x00800000 };
	XMGLOBALCONST XMVECTORI32 g_XMFltMax = { 0x7F7FFFFF, 0x7F7FFFFF, 0x7F7FFFFF, 0x7F7FFFFF };
	XMGLOBALCONST XMVECTORU32 g_XMNegOneMask = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
	XMGLOBALCONST XMVECTORU32 g_XMMaskA8R8G8B8 = { 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000 };
	XMGLOBALCONST XMVECTORU32 g_XMFlipA8R8G8B8 = { 0x00000000, 0x00000000, 0x00000000, 0x80000000 };
	XMGLOBALCONST XMVECTORF32 g_XMFixAA8R8G8B8 = { 0.0f,0.0f,0.0f,(float)(0x80000000U) };
	XMGLOBALCONST XMVECTORF32 g_XMNormalizeA8R8G8B8 = { 1.0f / (255.0f*(float)(0x10000)),1.0f / (255.0f*(float)(0x100)),1.0f / 255.0f,1.0f / (255.0f*(float)(0x1000000)) };
	XMGLOBALCONST XMVECTORU32 g_XMMaskA2B10G10R10 = { 0x000003FF, 0x000FFC00, 0x3FF00000, 0xC0000000 };
	XMGLOBALCONST XMVECTORU32 g_XMFlipA2B10G10R10 = { 0x00000200, 0x00080000, 0x20000000, 0x80000000 };
	XMGLOBALCONST XMVECTORF32 g_XMFixAA2B10G10R10 = { -512.0f,-512.0f*(float)(0x400),-512.0f*(float)(0x100000),(float)(0x80000000U) };
	XMGLOBALCONST XMVECTORF32 g_XMNormalizeA2B10G10R10 = { 1.0f / 511.0f,1.0f / (511.0f*(float)(0x400)),1.0f / (511.0f*(float)(0x100000)),1.0f / (3.0f*(float)(0x40000000)) };
	XMGLOBALCONST XMVECTORU32 g_XMMaskX16Y16 = { 0x0000FFFF, 0xFFFF0000, 0x00000000, 0x00000000 };
	XMGLOBALCONST XMVECTORI32 g_XMFlipX16Y16 = { 0x00008000, 0x00000000, 0x00000000, 0x00000000 };
	XMGLOBALCONST XMVECTORF32 g_XMFixX16Y16 = { -32768.0f,0.0f,0.0f,0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNormalizeX16Y16 = { 1.0f / 32767.0f,1.0f / (32767.0f*65536.0f),0.0f,0.0f };
	XMGLOBALCONST XMVECTORU32 g_XMMaskX16Y16Z16W16 = { 0x0000FFFF, 0x0000FFFF, 0xFFFF0000, 0xFFFF0000 };
	XMGLOBALCONST XMVECTORI32 g_XMFlipX16Y16Z16W16 = { 0x00008000, 0x00008000, 0x00000000, 0x00000000 };
	XMGLOBALCONST XMVECTORF32 g_XMFixX16Y16Z16W16 = { -32768.0f,-32768.0f,0.0f,0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNormalizeX16Y16Z16W16 = { 1.0f / 32767.0f,1.0f / 32767.0f,1.0f / (32767.0f*65536.0f),1.0f / (32767.0f*65536.0f) };
	XMGLOBALCONST XMVECTORF32 g_XMNoFraction = { 8388608.0f,8388608.0f,8388608.0f,8388608.0f };
	XMGLOBALCONST XMVECTORI32 g_XMMaskByte = { 0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF };
	XMGLOBALCONST XMVECTORF32 g_XMNegateX = { -1.0f, 1.0f, 1.0f, 1.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNegateY = { 1.0f,-1.0f, 1.0f, 1.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNegateZ = { 1.0f, 1.0f,-1.0f, 1.0f };
	XMGLOBALCONST XMVECTORF32 g_XMNegateW = { 1.0f, 1.0f, 1.0f,-1.0f };
	XMGLOBALCONST XMVECTORU32 g_XMSelect0101 = { XM_SELECT_0, XM_SELECT_1, XM_SELECT_0, XM_SELECT_1 };
	XMGLOBALCONST XMVECTORU32 g_XMSelect1010 = { XM_SELECT_1, XM_SELECT_0, XM_SELECT_1, XM_SELECT_0 };
	XMGLOBALCONST XMVECTORI32 g_XMOneHalfMinusEpsilon = { 0x3EFFFFFD, 0x3EFFFFFD, 0x3EFFFFFD, 0x3EFFFFFD };
	XMGLOBALCONST XMVECTORU32 g_XMSelect1000 = { XM_SELECT_1, XM_SELECT_0, XM_SELECT_0, XM_SELECT_0 };
	XMGLOBALCONST XMVECTORU32 g_XMSelect1100 = { XM_SELECT_1, XM_SELECT_1, XM_SELECT_0, XM_SELECT_0 };
	XMGLOBALCONST XMVECTORU32 g_XMSelect1110 = { XM_SELECT_1, XM_SELECT_1, XM_SELECT_1, XM_SELECT_0 };
	XMGLOBALCONST XMVECTORU32 g_XMSelect1011 = { XM_SELECT_1, XM_SELECT_0, XM_SELECT_1, XM_SELECT_1 };
	XMGLOBALCONST XMVECTORF32 g_XMFixupY16 = { 1.0f,1.0f / 65536.0f,0.0f,0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMFixupY16W16 = { 1.0f,1.0f,1.0f / 65536.0f,1.0f / 65536.0f };
	XMGLOBALCONST XMVECTORU32 g_XMFlipY = { 0,0x80000000,0,0 };
	XMGLOBALCONST XMVECTORU32 g_XMFlipZ = { 0,0,0x80000000,0 };
	XMGLOBALCONST XMVECTORU32 g_XMFlipW = { 0,0,0,0x80000000 };
	XMGLOBALCONST XMVECTORU32 g_XMFlipYZ = { 0,0x80000000,0x80000000,0 };
	XMGLOBALCONST XMVECTORU32 g_XMFlipZW = { 0,0,0x80000000,0x80000000 };
	XMGLOBALCONST XMVECTORU32 g_XMFlipYW = { 0,0x80000000,0,0x80000000 };
	XMGLOBALCONST XMVECTORI32 g_XMMaskDec4 = { 0x3FF,0x3FF << 10,0x3FF << 20,0x3 << 30 };
	XMGLOBALCONST XMVECTORI32 g_XMXorDec4 = { 0x200,0x200 << 10,0x200 << 20,0 };
	XMGLOBALCONST XMVECTORF32 g_XMAddUDec4 = { 0,0,0,32768.0f*65536.0f };
	XMGLOBALCONST XMVECTORF32 g_XMAddDec4 = { -512.0f,-512.0f*1024.0f,-512.0f*1024.0f*1024.0f,0 };
	XMGLOBALCONST XMVECTORF32 g_XMMulDec4 = { 1.0f,1.0f / 1024.0f,1.0f / (1024.0f*1024.0f),1.0f / (1024.0f*1024.0f*1024.0f) };
	XMGLOBALCONST XMVECTORU32 g_XMMaskByte4 = { 0xFF,0xFF00,0xFF0000,0xFF000000 };
	XMGLOBALCONST XMVECTORI32 g_XMXorByte4 = { 0x80,0x8000,0x800000,0x00000000 };
	XMGLOBALCONST XMVECTORF32 g_XMAddByte4 = { -128.0f,-128.0f*256.0f,-128.0f*65536.0f,0 };
	XMGLOBALCONST XMVECTORF32 g_XMFixUnsigned = { 32768.0f*65536.0f,32768.0f*65536.0f,32768.0f*65536.0f,32768.0f*65536.0f };
	XMGLOBALCONST XMVECTORF32 g_XMMaxInt = { 65536.0f*32768.0f - 128.0f,65536.0f*32768.0f - 128.0f,65536.0f*32768.0f - 128.0f,65536.0f*32768.0f - 128.0f };
	XMGLOBALCONST XMVECTORF32 g_XMMaxUInt = { 65536.0f*65536.0f - 256.0f,65536.0f*65536.0f - 256.0f,65536.0f*65536.0f - 256.0f,65536.0f*65536.0f - 256.0f };
	XMGLOBALCONST XMVECTORF32 g_XMUnsignedFix = { 32768.0f*65536.0f,32768.0f*65536.0f,32768.0f*65536.0f,32768.0f*65536.0f };
	XMGLOBALCONST XMVECTORF32 g_XMsrgbScale = { 12.92f, 12.92f, 12.92f, 1.0f };
	XMGLOBALCONST XMVECTORF32 g_XMsrgbA = { 0.055f, 0.055f, 0.055f, 0.0f };
	XMGLOBALCONST XMVECTORF32 g_XMsrgbA1 = { 1.055f, 1.055f, 1.055f, 1.0f };
	XMGLOBALCONST XMVECTORI32 g_XMExponentBias = { 127, 127, 127, 127 };
	XMGLOBALCONST XMVECTORI32 g_XMSubnormalExponent = { -126, -126, -126, -126 };
	XMGLOBALCONST XMVECTORI32 g_XMNumTrailing = { 23, 23, 23, 23 };
	XMGLOBALCONST XMVECTORI32 g_XMMinNormal = { 0x00800000, 0x00800000, 0x00800000, 0x00800000 };
	XMGLOBALCONST XMVECTORU32 g_XMNegInfinity = { 0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000 };
	XMGLOBALCONST XMVECTORU32 g_XMNegQNaN = { 0xFFC00000, 0xFFC00000, 0xFFC00000, 0xFFC00000 };
	XMGLOBALCONST XMVECTORI32 g_XMBin128 = { 0x43000000, 0x43000000, 0x43000000, 0x43000000 };
	XMGLOBALCONST XMVECTORU32 g_XMBinNeg150 = { 0xC3160000, 0xC3160000, 0xC3160000, 0xC3160000 };
	XMGLOBALCONST XMVECTORI32 g_XM253 = { 253, 253, 253, 253 };
	XMGLOBALCONST XMVECTORF32 g_XMExpEst1 = { -6.93147182e-1f, -6.93147182e-1f, -6.93147182e-1f, -6.93147182e-1f };
	XMGLOBALCONST XMVECTORF32 g_XMExpEst2 = { +2.40226462e-1f, +2.40226462e-1f, +2.40226462e-1f, +2.40226462e-1f };
	XMGLOBALCONST XMVECTORF32 g_XMExpEst3 = { -5.55036440e-2f, -5.55036440e-2f, -5.55036440e-2f, -5.55036440e-2f };
	XMGLOBALCONST XMVECTORF32 g_XMExpEst4 = { +9.61597636e-3f, +9.61597636e-3f, +9.61597636e-3f, +9.61597636e-3f };
	XMGLOBALCONST XMVECTORF32 g_XMExpEst5 = { -1.32823968e-3f, -1.32823968e-3f, -1.32823968e-3f, -1.32823968e-3f };
	XMGLOBALCONST XMVECTORF32 g_XMExpEst6 = { +1.47491097e-4f, +1.47491097e-4f, +1.47491097e-4f, +1.47491097e-4f };
	XMGLOBALCONST XMVECTORF32 g_XMExpEst7 = { -1.08635004e-5f, -1.08635004e-5f, -1.08635004e-5f, -1.08635004e-5f };
	XMGLOBALCONST XMVECTORF32 g_XMLogEst0 = { +1.442693f, +1.442693f, +1.442693f, +1.442693f };
	XMGLOBALCONST XMVECTORF32 g_XMLogEst1 = { -0.721242f, -0.721242f, -0.721242f, -0.721242f };
	XMGLOBALCONST XMVECTORF32 g_XMLogEst2 = { +0.479384f, +0.479384f, +0.479384f, +0.479384f };
	XMGLOBALCONST XMVECTORF32 g_XMLogEst3 = { -0.350295f, -0.350295f, -0.350295f, -0.350295f };
	XMGLOBALCONST XMVECTORF32 g_XMLogEst4 = { +0.248590f, +0.248590f, +0.248590f, +0.248590f };
	XMGLOBALCONST XMVECTORF32 g_XMLogEst5 = { -0.145700f, -0.145700f, -0.145700f, -0.145700f };
	XMGLOBALCONST XMVECTORF32 g_XMLogEst6 = { +0.057148f, +0.057148f, +0.057148f, +0.057148f };
	XMGLOBALCONST XMVECTORF32 g_XMLogEst7 = { -0.010578f, -0.010578f, -0.010578f, -0.010578f };
	XMGLOBALCONST XMVECTORF32 g_XMLgE = { +1.442695f, +1.442695f, +1.442695f, +1.442695f };
	XMGLOBALCONST XMVECTORF32 g_XMInvLgE = { +6.93147182e-1f, +6.93147182e-1f, +6.93147182e-1f, +6.93147182e-1f };
	XMGLOBALCONST XMVECTORF32 g_UnitPlaneEpsilon = { +6.93147182e-1f, +6.93147182e-1f, +6.93147182e-1f, +6.93147182e-1f };

	template<uint32_t PermuteX, uint32_t PermuteY, uint32_t PermuteZ, uint32_t PermuteW>
	inline XMVECTOR     DXM_CALLCONV     XMVectorPermute(FXMVECTOR V1, FXMVECTOR V2)
	{
		static_assert(PermuteX <= 7, "PermuteX template parameter out of range");
		static_assert(PermuteY <= 7, "PermuteY template parameter out of range");
		static_assert(PermuteZ <= 7, "PermuteZ template parameter out of range");
		static_assert(PermuteW <= 7, "PermuteW template parameter out of range");

		return XMVectorPermute(V1, V2, PermuteX, PermuteY, PermuteZ, PermuteW);

	};

	template<uint32_t SwizzleX, uint32_t SwizzleY, uint32_t SwizzleZ, uint32_t SwizzleW>
	inline XMVECTOR     DXM_CALLCONV     XMVectorSwizzle(FXMVECTOR V)
	{
		static_assert(SwizzleX <= 3, "SwizzleX template parameter out of range");
		static_assert(SwizzleY <= 3, "SwizzleY template parameter out of range");
		static_assert(SwizzleZ <= 3, "SwizzleZ template parameter out of range");
		static_assert(SwizzleW <= 3, "SwizzleW template parameter out of range");

		return XMVectorSwizzle(V, SwizzleX, SwizzleY, SwizzleZ, SwizzleW);
	};

	template<uint32_t VSLeftRotateElements, uint32_t Select0, uint32_t Select1, uint32_t Select2, uint32_t Select3>
	inline XMVECTOR     DXM_CALLCONV     XMVectorInsert(FXMVECTOR VD, FXMVECTOR VS)
	{
		XMVECTOR Control = XMVectorSelectControl(Select0 & 1, Select1 & 1, Select2 & 1, Select3 & 1);
		return XMVectorSelect(VD, XMVectorRotateLeft<VSLeftRotateElements>(VS), Control);
	};

	template<uint32_t Elements>
	inline XMVECTOR     DXM_CALLCONV     XMVectorShiftLeft(FXMVECTOR V1, FXMVECTOR V2)
	{
		static_assert(Elements < 4, "Elements template parameter out of range");
		return XMVectorPermute<Elements, (Elements + 1), (Elements + 2), (Elements + 3)>(V1, V2);
	};

	template<uint32_t Elements>
	inline XMVECTOR     DXM_CALLCONV     XMVectorRotateLeft(FXMVECTOR V)
	{
		static_assert(Elements < 4, "Elements template parameter out of range");
		return XMVectorSwizzle<Elements & 3, (Elements + 1) & 3, (Elements + 2) & 3, (Elements + 3) & 3>(V);
	};

	template<uint32_t Elements>
	inline XMVECTOR     DXM_CALLCONV     XMVectorRotateRight(FXMVECTOR V)
	{
		static_assert(Elements < 4, "Elements template parameter out of range");
		return XMVectorSwizzle<(4 - Elements) & 3, (5 - Elements) & 3, (6 - Elements) & 3, (7 - Elements) & 3>(V);
	};
	template<class T> inline T XMMin(T a, T b) { return (a < b) ? a : b; }
	template<class T> inline T XMMax(T a, T b) { return (a > b) ? a : b; }

};
