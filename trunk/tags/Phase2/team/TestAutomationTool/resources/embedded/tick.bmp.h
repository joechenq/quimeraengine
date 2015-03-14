#ifndef TICK_BMP_H
#define TICK_BMP_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char tick_bmp[] = 
{
	0x42, 0x4D, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x08, 0x00, 
	0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xC2, 0x00, 0x00, 0x00, 0x12, 0x0B, 
	0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xEA, 0xF3, 0xEC, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xA2, 0xD8, 0xB0, 0x19, 0x8D, 0x20, 
	0xAB, 0xD0, 0xAB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAA, 0xE4, 0xC0, 0x0E, 0xA3, 
	0x2E, 0x05, 0x97, 0x16, 0x0B, 0x91, 0x1B, 0xAC, 0xD9, 0xB3, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xF2, 0xD7, 0x42, 
	0xCC, 0x78, 0x41, 0xC6, 0x6E, 0x41, 0xC7, 0x71, 0x39, 0xC3, 
	0x68, 0x27, 0xB2, 0x4F, 0xB1, 0xE5, 0xC3, 0xFF, 0xFF, 0xFF, 
	0x9D, 0xE6, 0xBE, 0x31, 0xD5, 0x82, 0x5C, 0xDB, 0x96, 0xA9, 
	0xE7, 0xC1, 0x51, 0xD7, 0x8F, 0x4C, 0xDE, 0x95, 0x34, 0xCD, 
	0x78, 0xB7, 0xF1, 0xD4, 0xF8, 0xFA, 0xF8, 0x8D, 0xE2, 0xB3, 
	0xD5, 0xF3, 0xE1, 0xFF, 0xFF, 0xFF, 0xBC, 0xE4, 0xC7, 0x45, 
	0xD3, 0x88, 0x48, 0xE9, 0xA1, 0xA6, 0xF0, 0xCD, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xBB, 0xE1, 0xC3, 0xB8, 0xF1, 0xD3, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 
};

wxBitmap& tick_bmp_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( tick_bmp, sizeof( tick_bmp ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_BMP );
	static wxBitmap bmp( image );
	return bmp;
};


#endif //TICK_BMP_H
