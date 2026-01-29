#include <iostream>
#include <vector>
#include <numeric> 
#include <memory>
using namespace std;

// ================= OpenTelemetry Setup (stdout tracing) =================
#include <opentelemetry/exporters/ostream/span_exporter.h>
#include <opentelemetry/sdk/trace/simple_processor.h>
#include <opentelemetry/sdk/trace/tracer_provider.h>
#include <opentelemetry/trace/provider.h>
#include <opentelemetry/trace/scope.h>
#include <opentelemetry/nostd/shared_ptr.h>

namespace trace = opentelemetry::trace;
namespace sdktrace = opentelemetry::sdk::trace;

// global provider (OTel type, not std::shared_ptr)
static opentelemetry::nostd::shared_ptr<trace::TracerProvider> g_provider;

void InitTracer()
{
    auto exporter  = std::make_unique<opentelemetry::exporter::trace::OStreamSpanExporter>();
    auto processor = std::make_unique<sdktrace::SimpleSpanProcessor>(std::move(exporter));

    g_provider = opentelemetry::nostd::shared_ptr<trace::TracerProvider>(
        new sdktrace::TracerProvider(std::move(processor))
    );

    trace::Provider::SetTracerProvider(g_provider);
}
// =======================================================================


// ===================== Your QuickSort Implementations ===================
int partitionI(vector<int> &nums, int low, int high){
    int pivot = nums[low];
    int l = low, r = high;
    while(l <= r){
        while(l <= high && nums[l] <= pivot) l++;
        while(r >= low && nums[r] > pivot) r--;
        if(l < r) swap(nums[l], nums[r]);
    }
    swap(nums[low], nums[r]);
    return r;
}

void quickSortI(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = partitionI(nums, low, high);
        quickSortI(nums, low, mid - 1);
        quickSortI(nums, mid + 1, high);
    }
}

int partitionII(vector<int> &nums, int low, int high){
    int pivot = nums[high];
    int i = low - 1;
    for(int j = low; j < high; ++j){
        if(nums[j] < pivot){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void quickSortII(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = partitionII(nums, low, high);
        quickSortII(nums, low, mid - 1);
        quickSortII(nums, mid + 1, high);
    }
}

int partitionIII(vector<int> &nums, int low, int high){
    int mid = low + (high - low) / 2;
    swap(nums[mid], nums[low]);
    int pivot = nums[low];
    int l = low, r = high;
    while(l <= r){
        while(l <= high && nums[l] <= pivot) l++;
        while(r >= low && nums[r] > pivot) r--;
        if(l < r) swap(nums[l], nums[r]);
    }
    swap(nums[low], nums[r]);
    return r;
}

void quickSortIII(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = partitionIII(nums, low, high);
        quickSortIII(nums, low, mid - 1);
        quickSortIII(nums, mid + 1, high);
    }
}
// =======================================================================


// =============================== MAIN ===================================
int main()
{
    InitTracer();
    auto tracer = trace::Provider::GetTracerProvider()->GetTracer("quicksort");

    vector<int> base(1001);
    iota(base.begin(), base.end(), 0);

    // ---- quickSortI ----
    {
        auto nums = base;
        auto span = tracer->StartSpan("quickSortI_total");
        trace::Scope scope(span);

        span->SetAttribute("impl", "I");
        span->SetAttribute("n", (int)nums.size());

        quickSortI(nums, 0, nums.size() - 1);

        span->End();
    }

    // ---- quickSortII ----
    {
        auto nums = base;
        auto span = tracer->StartSpan("quickSortII_total");
        trace::Scope scope(span);

        span->SetAttribute("impl", "II");
        span->SetAttribute("n", (int)nums.size());

        quickSortII(nums, 0, nums.size() - 1);

        span->End();
    }

    // ---- quickSortIII ----
    {
        auto nums = base;
        auto span = tracer->StartSpan("quickSortIII_total");
        trace::Scope scope(span);

        span->SetAttribute("impl", "III");
        span->SetAttribute("n", (int)nums.size());

        quickSortIII(nums, 0, nums.size() - 1);

        span->End();
    }

    return 0;
}

// git clone https://github.com/microsoft/vcpkg.git
// cd vcpkg
// ./bootstrap-vcpkg.sh

// echo 'export PATH="$HOME/Documents/USC/24Winter/dailyPractice/vcpkg:$PATH"' >> ~/.zshrc
// source ~/.zshrc
// hash -r
// which vcpkg
// vcpkg version

// If you just want tracing quickly (no collector yet)
// Install the core SDK only (then use the stdout exporter in code):
// vcpkg install opentelemetry-cpp


// CMakeLists.txt
// cmake_minimum_required(VERSION 3.20)
// project(quickSort_OTel LANGUAGES CXX)

// set(CMAKE_CXX_STANDARD 17)
// set(CMAKE_CXX_STANDARD_REQUIRED ON)

// add_executable(quickSort_OTel quickSort_OTel.cpp)

// # opentelemetry-cpp provides CMake package + components.
// # We use the ostream exporter to print spans to stdout.
// find_package(opentelemetry-cpp CONFIG REQUIRED COMPONENTS
//     api
//     sdk
//     exporters_ostream
// )

// target_link_libraries(quickSort_OTel PRIVATE
//     opentelemetry-cpp::api
//     opentelemetry-cpp::trace
//     opentelemetry-cpp::sdk
//     opentelemetry-cpp::ostream_span_exporter
// )

// cd ..../dailyPractice
// mkdir -p build
// cmake --build build -j
// ./build/quickSort_OTel