#include "chimera_generated.h"
#include "flatbuffers/flatbuffer_builder.h"

#include <string>

extern "C" {
    #include <stdio.h>
}

void print_hex(uint8_t* buf, size_t len)
{
    for(size_t i = 0; i < len; i++)
    {
        printf("%02hhx ", buf[i]);
    }
    printf("\n");
}

int main(void)
{
    flatbuffers::FlatBufferBuilder builder(1024);
    auto m = Chimera::CreateMessage(builder, 9999);
    builder.Finish(m);
    uint8_t *ptr = builder.GetBufferPointer();
    size_t len = builder.GetSize();
    print_hex(ptr, len);
    return 0;
}