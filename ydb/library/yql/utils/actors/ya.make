LIBRARY()

SRCS(
    rich_actor.cpp
    http_sender_actor.cpp
)

PEERDIR(
    ydb/library/actors/core
    ydb/library/yql/providers/common/token_accessor/client
    yql/essentials/public/types
    yql/essentials/public/udf
    ydb/library/yql/providers/solomon/proto
)

END()

RECURSE_FOR_TESTS(
    ut
)
