#ifndef GCC_MORPHOS_PROTOS_H
#define GCC_MORPHOS_PROTOS_H

extern const char *morphos_check_pch_target_flags (int old_flags);

#ifdef RTX_CODE

extern rtx morphos_legitimize_baserel_address(rtx);
extern rtx morphos_legitimize_baserel_address_in_place(rtx, rtx);
extern bool morphos_baserel_operand(rtx);
extern bool morphos_baserel_referenced_p (rtx);
extern bool morphos_use_anchors_for_symbol_p (const_rtx);

#ifdef TREE_CODE
extern int morphos_not_baserel_tree_p(tree);
extern tree morphos_handle_saveds_attribute (tree *, tree, tree, int, bool*);
#endif /* TREE_CODE */

#endif /* RTX_CODE */

#endif /* GCC_MORPHOS_PROTOS_H */
