// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "stim/draw/3d/timeline_3d.h"

#include "gtest/gtest.h"
#include "stim/gen/circuit_gen_params.h"
#include "stim/gen/gen_surface_code.h"

using namespace stim;

TEST(circuit_diagram_timeline_3d, XXXXXXXXXXX) {
    CircuitGenParameters params(10, 31, "rotated_memory_z");
//    params.before_measure_flip_probability = 0.001;
//    params.after_reset_flip_probability = 0.001;
//    params.after_clifford_depolarization = 0.001;
    Circuit circuit = generate_surface_code_circuit(params).circuit;
//    circuit = stim::Circuit(R"CIRCUIT(
//        QUBIT_COORDS(0, 0) 0
//        QUBIT_COORDS(0, 1) 1
//        QUBIT_COORDS(1, 0) 2
//        QUBIT_COORDS(1, 2) 3
//        H 0 2
//        CX 0 1 2 3
//        TICK
//        CX 0 2 1 3
//        M 0 1 2 3
//    )CIRCUIT");

    auto s = circuit_diagram_timeline_3d(circuit);

    FILE *f = fopen("/home/craiggidney/tmp/test.gltf", "w");
    fprintf(f, "%s", s.data());
    fclose(f);
}
