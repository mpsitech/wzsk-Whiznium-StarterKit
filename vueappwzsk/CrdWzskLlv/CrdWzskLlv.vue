<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Low-level access</h1>
		<PnlWzskLlvIdent
			v-on:request="handleRequest"
			ref="PnlWzskLlvIdent"
			:scrJref=statshr.scrJrefIdent
		/>
		<PnlWzskLlvTermDcvsp
			v-if="statshr.pnltermdcvspAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermDcvsp"
			:scrJref=statshr.scrJrefTermDcvsp
		/>
		<PnlWzskLlvTermTivsp
			v-if="statshr.pnltermtivspAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermTivsp"
			:scrJref=statshr.scrJrefTermTivsp
		/>
		<PnlWzskLlvLaser
			v-on:request="handleRequest"
			ref="PnlWzskLlvLaser"
			:scrJref=statshr.scrJrefLaser
		/>
		<PnlWzskLlvRotary
			v-on:request="handleRequest"
			ref="PnlWzskLlvRotary"
			:scrJref=statshr.scrJrefRotary
		/>
		<PnlWzskLlvSysmon
			v-on:request="handleRequest"
			ref="PnlWzskLlvSysmon"
			:scrJref=statshr.scrJrefSysmon
		/>
		<PnlWzskLlvTermZuvsp
			v-if="statshr.pnltermzuvspAvail"
			v-on:request="handleRequest"
			ref="PnlWzskLlvTermZuvsp"
			:scrJref=statshr.scrJrefTermZuvsp
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskLlvIdent from './PnlWzskLlvIdent';
	import PnlWzskLlvTermDcvsp from './PnlWzskLlvTermDcvsp';
	import PnlWzskLlvTermTivsp from './PnlWzskLlvTermTivsp';
	import PnlWzskLlvLaser from './PnlWzskLlvLaser';
	import PnlWzskLlvRotary from './PnlWzskLlvRotary';
	import PnlWzskLlvSysmon from './PnlWzskLlvSysmon';
	import PnlWzskLlvTermZuvsp from './PnlWzskLlvTermZuvsp';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskLlv',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskLlvIdent,
			PnlWzskLlvTermDcvsp,
			PnlWzskLlvTermTivsp,
			PnlWzskLlvLaser,
			PnlWzskLlvRotary,
			PnlWzskLlvSysmon,
			PnlWzskLlvTermZuvsp
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskLlv.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWzskLlv) this.continf = dpcheng.ContInfWzskLlv;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskLlv) this.statapp = dpcheng.StatAppWzskLlv;
				if (dpcheng.StatShrWzskLlv) this.statshr = dpcheng.StatShrWzskLlv;
				if (dpcheng.TagWzskLlv) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlv);
					this.tag = dpcheng.TagWzskLlv;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefIdent) this.$refs.PnlWzskLlvIdent.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermDcvsp) this.$refs.PnlWzskLlvTermDcvsp.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermTivsp) this.$refs.PnlWzskLlvTermTivsp.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefLaser) this.$refs.PnlWzskLlvLaser.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefRotary) this.$refs.PnlWzskLlvRotary.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefSysmon) this.$refs.PnlWzskLlvSysmon.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefTermZuvsp) this.$refs.PnlWzskLlvTermZuvsp.handleReply(obj);
					else console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskLlvData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefIdent) {
						this.$refs.PnlWzskLlvIdent.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermDcvsp) {
						this.$refs.PnlWzskLlvTermDcvsp.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermTivsp) {
						this.$refs.PnlWzskLlvTermTivsp.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefLaser) {
						this.$refs.PnlWzskLlvLaser.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefRotary) {
						this.$refs.PnlWzskLlvRotary.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefSysmon) {
						this.$refs.PnlWzskLlvSysmon.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefTermZuvsp) {
						this.$refs.PnlWzskLlvTermZuvsp.handleUpdate(obj);
						processed = true;
					}
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
