#include <iostream>
#include <string>

#include "test.pb.h"
#include <benchmark/benchmark.h>

static void BM_Decode(benchmark::State &state) {
  FooBarContainer fbc;
  fbc.set_initialized(true);
  fbc.set_fruit(FRUIT_BANANAS);
  fbc.set_location("http://google.com/flatbuffers/");
  for (int i = 0; i < 3; i++) {
    FooBar *fb = fbc.add_list();
    fb->set_name("Hello, World!");
    fb->set_rating(3.1415432432445543543 + i);
    fb->set_postfix('!' + i);
    Bar *bar = fb->mutable_sibling();
    bar->set_time(123456 + i);
    bar->set_ratio(3.14159f + i);
    bar->set_size(10000 + i);
    Foo *foo = bar->mutable_parent();
    foo->set_id(0xABADCAFEABADCAFE + i);
    foo->set_count(10000 + i);
    foo->set_prefix('@' + i);
    foo->set_length(1000000 + i);
  }
  std::string buf = fbc.SerializePartialAsString();
  unsigned long total = 0;
  for (auto _ : state) {
    fbc.ParsePartialFromString(buf);
    total += fbc.initialized() + fbc.fruit() + fbc.location().size();
    for (const auto &fb : fbc.list()) {
      total += fb.name().size() + fb.postfix() +
               static_cast<unsigned long>(fb.rating());
      const Bar &bar = fb.sibling();
      total +=
          bar.time() + bar.size() + static_cast<unsigned long>(bar.ratio());
      const Foo &foo = bar.parent();
      total += foo.id() + foo.count() + foo.prefix() + foo.length();
    }
  }
  std::cout << total << std::endl;
}

BENCHMARK(BM_Decode);
BENCHMARK_MAIN();