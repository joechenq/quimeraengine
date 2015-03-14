#include "gps_position.h"

int main( void )
{
   
        try
        {
                gps_position p(25, 3, 35.6f);
                std::string myfile = "gps_position.xml";
				eternity::xml_archive xml;
				
                // Serializaci�n xml
				xml.open(myfile, eternity::archive::store);
				p.xml_serialize(xml);
				xml.close();

                // Deserializaci�n xml
				gps_position q;

				xml.open(myfile, eternity::archive::load);
				q.xml_serialize(xml);
				xml.close();

				eternity::file_archive bin;
				myfile = "gps_position.bin";

				// Serializaci�n binaria
				bin.open(myfile, eternity::archive::store);
				p.bin_serialize(bin);
				bin.close();

                // Deserializaci�n binaria
				gps_position r;

				bin.open(myfile, eternity::archive::load);
				r.bin_serialize(bin);
				bin.close();

                
     
        }
        catch( const std::exception & ex )
        {
                std::cerr << "EXCEPTION: " << ex.what() << "\n";
                return 1;
        }
        return 0;
}