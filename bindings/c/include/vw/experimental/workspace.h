// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "exports.h"
#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

  VW_DLL_PUBLIC VWStatus vw_create_workspace(VWOptions* options_handle, bool skip_model_load,
      VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output_handle,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_create_workspace_with_model(VWOptions* options_handle, void* context, VWReadFunc* reader, bool skip_model_load,
      VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output_handle,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_create_seeded_workspace(const VWWorkspace* existing_workspace_handle, VWOptions* extra_options_handle,
      VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output_handle,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;


  // Returns name of first incompatible feature.
  // Probably better to return an enum with enum->string mappings available?
  // TODO deprecate this... ?
  // TODO rename this to "is example parsing compatible" -> potentially refactor to taking in options
  VW_DLL_PUBLIC VWStatus vw_workspace_are_features_compatible_legacy(const VWWorkspace* workspace_handle_one,
      const VWWorkspace* workspace_handle_two, const char** incompatible_feature,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_workspace_get_model_id(
      const VWWorkspace* workspace_handle, const char** model_id, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_set_model_id(
      VWWorkspace* workspace_handle, const char* model_id, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_command_line(
      const VWWorkspace* workspace_handle, VWString* command_line, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // finish is now broken up into finish() and destroy_workspace().
  VW_DLL_PUBLIC VWStatus vw_workspace_finish(
      VWWorkspace* workspace_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_destroy_workspace(
      VWWorkspace* workspace_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_workspace_get_prediction_type(
      const VWWorkspace* workspace_handle, VWPredictionType* prediction_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_label_type(
      const VWWorkspace* workspace_handle, VWLabelType* label_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // TODO add multipredict

  // These are "Legacy" variants because predictions and labels are in the example object
  VW_DLL_PUBLIC VWStatus vw_workspace_learn_legacy(
      VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_learn_multiline_legacy(VWWorkspace* workspace_handle, VWExample** example_handle_list,
      size_t example_handle_list_length, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_workspace_predict_legacy(
      VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_predict_multiline_legacy(VWWorkspace* workspace_handle,
      VWExample** example_handle_list, size_t example_handle_list_length,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // finish one or more examples? How do we handle multi_ex?
  VW_DLL_PUBLIC VWStatus vw_workspace_finish_example(
      VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_finish_example_multiline(VWWorkspace* workspace_handle,
      VWExample** example_handle_list, size_t example_handle_list_length,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_workspace_end_pass(
      VWWorkspace* workspace_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_workspace_get_search(
      const VWWorkspace* workspace_handle, VWSearch** search_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif