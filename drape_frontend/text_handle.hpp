#pragma once

#include "drape/overlay_handle.hpp"
#include "drape/pointers.hpp"
#include "drape/utils/vertex_decl.hpp"

#include "base/string_utils.hpp"

namespace dp
{
  class TextureManager;
}

namespace df
{

class TextHandle : public dp::OverlayHandle
{
public:
  TextHandle(dp::OverlayID const & id, strings::UniString const & text,
             dp::Anchor anchor, uint64_t priority, int fixedHeight,
             ref_ptr<dp::TextureManager> textureManager,
             bool isBillboard = false);

  TextHandle(dp::OverlayID const & id, strings::UniString const & text,
             dp::Anchor anchor, uint64_t priority, int fixedHeight,
             ref_ptr<dp::TextureManager> textureManager,
             gpu::TTextDynamicVertexBuffer && normals,
             bool IsBillboard = false);

  bool Update(ScreenBase const & screen) override;

  void GetAttributeMutation(ref_ptr<dp::AttributeBufferMutator> mutator) const override;

  bool IndexesRequired() const override;

  void SetForceUpdateNormals(bool forceUpdate) const;

#ifdef DEBUG_OVERLAYS_OUTPUT
  virtual string GetOverlayDebugInfo() override;
#endif

protected:
  gpu::TTextDynamicVertexBuffer m_buffer;
  mutable bool m_forceUpdateNormals;

private:
  mutable bool m_isLastVisible;

  strings::UniString m_text;
  ref_ptr<dp::TextureManager> m_textureManager;
  bool m_glyphsReady;
  int m_fixedHeight;
};


} // namespace df
