#pragma once
#include "AEngine/render/api/ae/Buffer.h"

namespace AEngine {
    class BufferOGL : public Buffer {
        public:
            BufferOGL() {};
            virtual      ~BufferOGL() override = default;
            virtual void bind() const override;
            virtual void unBind() const override;
            virtual void destroy() override;

            virtual void          setBufferLayout(const BufferLayout& _layout) override { layout = _layout; };
            virtual BufferLayout& getLayout() override { return layout; };
        protected:
            uint32_t     id;
            uint32_t     type;
            BufferLayout layout;
    };
}
