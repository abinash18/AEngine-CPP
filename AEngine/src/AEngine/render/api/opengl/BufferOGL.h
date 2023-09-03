#pragma once
#include "AEngine/render/api/ae/Buffer.h"

namespace AEngine {
    class BufferOGL : public Buffer {
        public:
            BufferOGL() {};
            ~BufferOGL() override = default;
            virtual void bind() const override;
            virtual void unBind() const override;
            virtual void destroy() override;

            virtual void setBufferLayout(const BufferLayout& _layout) override {
                layout = _layout;
            };

            virtual BufferLayout& getLayout() override {
                return layout;
            };

            uint32_t getId() const {
                return id;
            }

            uint32_t getType() const {
                return type;
            }

        protected:
            uint32_t     id;
            uint32_t     type;
            BufferLayout layout;
    };
}
