#pragma once
// -----------------------------------------------------------------------------

#include "macro.h"
#include "linked_list.h"
#include "mu_object_chat_data.h"
#include "mu_object_item_data.h"
// -----------------------------------------------------------------------------

struct ItemPost : public LinkNode<ItemPost> {
  public:
    ItemPost ( void * item_data ) {
        memcpy_s ( &item_, sizeof ( item_ ), item_data, sizeof ( MuObjectItemData ) );
        chat_ = nullptr;
    }
    virtual ~ItemPost() {}

  public:
    MuObjectChatData * chat_;
    MuObjectItemData item_;

  private:
    DISALLOW_COPY_AND_ASSIGN ( ItemPost );
};